// MQActorAdvPath.cpp : Defines the entry point for the DLL application.
//

// PLUGIN_API is only to be used for callbacks.  All existing callbacks at this time
// are shown below. Remove the ones your plugin does not use.  Always use Initialize
// and Shutdown for setup and cleanup.

#include <mq/Plugin.h>

#include "MQActorAdvPath.h"
using namespace mq::proto::actorfollowee;

PreSetup("MQActorAdvPath");
PLUGIN_VERSION(0.1);

/**
 * Avoid Globals if at all possible, since they persist throughout your program.
 * But if you must have them, here is the place to put them.
 */
 // bool ShowMQActorAdvPathWindow = true;

enum class FOLLOW {
	OFF = 0,
	ON = 1,
};

enum class STATUS {
	OFF = 0,
	ON = 1,
	PAUSED = 2
};

FOLLOW FollowState = FOLLOW::OFF;
STATUS StatusState = STATUS::OFF;


std::vector<std::shared_ptr<postoffice::Address>> Subscribers;
std::queue<std::shared_ptr<proto::actorfollowee::Position>> Positions;
postoffice::DropboxAPI s_DropBox;
postoffice::Address subscription;

class MQActorAdvPathType* pMQActorAdvPathType = nullptr;
class MQActorAdvPathType : public MQ2Type
{
public:
	enum Members {
		Active = 1,
		State = 2,
		Status = 3,
		Waypoints = 4,
		Following = 5,
		Paused = 6,
	};

	MQActorAdvPathType() : MQ2Type("ActorAdvPath") {
		TypeMember(Active);
		TypeMember(State);
		TypeMember(Status);
		TypeMember(Waypoints);
		TypeMember(Following);
		TypeMember(Paused);
	}

	virtual bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override {
		auto pMember = MQActorAdvPathType::FindMember(Member);
		if (!pMember)
			return false;

		switch ((Members)(pMember->ID))
		{
		case MQActorAdvPathType::Active:
			Dest.DWord = (gbInZone && GetCharInfo() && GetCharInfo()->pSpawn);
			Dest.Type = mq::datatypes::pBoolType;
			return true;
		case MQActorAdvPathType::State:
			Dest.Type = mq::datatypes::pIntType;
			Dest.Int = static_cast<int>(FollowState);
			return true;
		case MQActorAdvPathType::Status:
			Dest.Type = mq::datatypes::pIntType;
			Dest.Int = static_cast<int>(StatusState);
			return true;
		case MQActorAdvPathType::Waypoints:
			Dest.Type = mq::datatypes::pIntType;
			Dest.Int = Subscribers.size();
			return true;
		case Following:
			Dest.DWord = (FollowState == FOLLOW::ON);
			Dest.Type = mq::datatypes::pBoolType;
			return true;
		case Paused:
			Dest.DWord = (StatusState == STATUS::PAUSED);
			Dest.Type = mq::datatypes::pBoolType;
			return true;
		}

		return false;
	}

	bool ToString(MQVarPtr VarPtr, char* Destination) {
		strcpy_s(Destination, MAX_STRING, "ActorAdvPath");
		return true;
	}
};

bool dataActorBots(const char* szIndex, MQTypeVar& Ret) {
	Ret.Type = pMQActorAdvPathType;
	return true;
}

void ReceivedMessageHandler(const std::shared_ptr<postoffice::Message>& message)
{
	if (GetGameState() != GAMESTATE_INGAME) {
		return;
	}

	mq::proto::actorfollowee::Message advPathMessage;
	advPathMessage.ParseFromString(*message->Payload);
	switch (advPathMessage.id())
	{
	case mq::proto::actorfollowee::MessageId::Subscribe:
		if (message->Sender.has_value()) {
			Subscribers.push_back(std::make_shared<postoffice::Address>(message->Sender.value()));
		}
		break;
	case mq::proto::actorfollowee::MessageId::UnSubscribe:
		for (std::vector<std::shared_ptr<postoffice::Address> >::iterator it = Subscribers.begin(); it != Subscribers.end();)
		{
			if ((*it)->Character == message->Sender->Character) {
				Subscribers.erase(it);
			}
		}
		break;
	case mq::proto::actorfollowee::MessageId::PositionUpdate:
		Positions.push(std::make_shared<mq::proto::actorfollowee::Position>(advPathMessage.position()));
		break;
	}
}

static void Post(postoffice::Address address, mq::proto::actorfollowee::MessageId messageId, const std::optional<proto::actorfollowee::Position>& data = std::nullopt)
{
	proto::actorfollowee::Message message;
	message.set_id(messageId);
	if (data) {
		*message.mutable_position() = *data;
	}

	s_DropBox.Post(address, message, nullptr);
}

static void Post(std::string reciever, mq::proto::actorfollowee::MessageId messageId)
{
	subscription.Server = GetServerShortName();
	subscription.Character = reciever;
	Post(subscription, messageId, std::nullopt);
}

void NotifyActorBotManager()
{
	if (!(GetCharInfo()->pSpawn && GetPcProfile())) {
		return;
	}

	if (auto pSpawn = GetCharInfo()->pSpawn) {
		proto::actorfollowee::Position newposition;
		newposition.set_spawnid(pSpawn->SpawnID);
		newposition.set_name(pSpawn->Name);
		newposition.set_x(pSpawn->X);
		newposition.set_y(pSpawn->Y);
		newposition.set_z(pSpawn->Z);
		newposition.set_heading(pSpawn->Heading);

		for (std::vector<std::shared_ptr<postoffice::Address>>::iterator it = Subscribers.begin(); it != Subscribers.end();) {
			Post(**it, mq::proto::actorfollowee::MessageId::PositionUpdate, newposition);
		}
	}
}

void DoFwd(bool hold) {
	static bool held = false;
	if (hold) {
		DoBck(false);
		if (!held) ExecuteCmd(FindMappableCommand("forward"), 1, 0);
		held = true;
	}
	else {
		if (held) ExecuteCmd(FindMappableCommand("forward"), 0, 0);
		held = false;
	}
}

void DoBck(bool hold) {
	static bool held = false;
	if (hold) {
		DoFwd(false);
		if (!held) ExecuteCmd(FindMappableCommand("back"), 1, 0);
		held = true;
	}
	else {
		if (held) ExecuteCmd(FindMappableCommand("back"), 0, 0);
		held = false;
	}
}

void DoLft(bool hold) {
	static bool held = false;
	if (hold) {
		DoRgt(false);
		if (!held) ExecuteCmd(FindMappableCommand("strafe_left"), 1, 0);
		held = true;
	}
	else {
		if (held) ExecuteCmd(FindMappableCommand("strafe_left"), 0, 0);
		held = false;
	}
}

void DoRgt(bool hold) {
	static bool held = false;
	if (hold) {
		DoLft(false);
		if (!held) ExecuteCmd(FindMappableCommand("strafe_right"), 1, 0);
		held = true;
	}
	else {
		if (held) ExecuteCmd(FindMappableCommand("strafe_right"), 0, 0);
		held = false;
	}
}

void ReleaseKeys() {
	DoFwd(false);
	DoBck(false);
	DoRgt(false);
	DoLft(false);
}

void DoStop() {
	DoBck(true);
	ReleaseKeys();
}

void StartFollowing(PlayerClient* pSpawn) {
	WriteChatf("[MQActorAdvPath] Following \aw%s\ax", pSpawn->Name);
	Post(pSpawn->Name, proto::actorfollowee::MessageId::Subscribe);
	FollowState = FOLLOW::ON;
	StatusState = STATUS::ON;
}

void EndFollowing() {
	DoStop();
	FollowState = FOLLOW::OFF;
	StatusState = STATUS::OFF;
	std::queue<std::shared_ptr<proto::actorfollowee::Position>>().swap(Positions);
	Post(subscription, proto::actorfollowee::MessageId::UnSubscribe);
}

void FollowCommand(SPAWNINFO* pChar, char* szLine) {
	if (szLine && szLine[0] == '\0')
	{
		WriteChatf("[MQActorAdvPath] Usage:");
		WriteChatf("    /actadvpath [character]");
		WriteChatf("    /actadvpath [on|off|pause|resume]");
		return;
	}

	char szArg1[MAX_STRING] = { 0 };
	GetArg(szArg1, szLine, 1);

	if (ci_equals(szArg1, "on")) {
		if (Subscribers.size()) {
			WriteChatf("[MQActorAdvPath] Im being followed so cannot follow others.");
			return;
		}
		else if (pTarget) {
			StartFollowing(pTarget);
		}
		else {
			WriteChatf("[MQActorAdvPath] No target specified.");
			return;
		}
	}
	else if (ci_equals(szArg1, "off")) {
		EndFollowing();
	}
	else if (ci_equals(szArg1, "pause")) {
		if (FollowState == FOLLOW::ON) {
			StatusState = STATUS::PAUSED;
		}
	}
	else if (ci_equals(szArg1, "resume")) {
		if (FollowState == FOLLOW::ON) {
			StatusState = STATUS::ON;
		}
	}
	else {
		if (auto pSpawn = GetSpawnByName(szArg1)) {
			if (Subscribers.size()) {
				WriteChatf("[MQActorAdvPath] Im being followed so cannot follow others.");
				return;
			}

			StartFollowing(pSpawn);
		}
		else {
			WriteChatf("[MQActorAdvPath] Character not found \aw%s\ax.", szArg1);
			return;
		}
	}
}

void LookAt(float x, float y, float z) {
	if (PCHARINFO pChar = GetCharInfo())
	{
		if (auto spawn = pChar->pSpawn)
		{
			gFaceAngle = (atan2(x - spawn->X, y - spawn->Y) * 256.0f / PI);

			if (gFaceAngle >= 512.0f) {
				gFaceAngle -= 512.0f;
			}

			if (gFaceAngle < 0.0f) {
				gFaceAngle += 512.0f;
			}

			pCharSpawn->Heading = (float)gFaceAngle;
			gFaceAngle = 10000.0f;

			if (spawn-> FeetWet || spawn->UnderWater == 5) { 
				spawn->CameraAngle = (float)(atan2(z - spawn->Z, (float)GetDistance(spawn->X, spawn->Y, x, y)) * 256.0f / PI); 
			}
			else if (spawn->mPlayerPhysicsClient.Levitate == 2) {
				if (z < spawn->Z - 5) {
					spawn->CameraAngle = -45.0f;
				}
				else if (z > spawn->Z + 5) {
					spawn->CameraAngle = 45.0f;
				}
				else {
					spawn->CameraAngle = 0.0f;
				}
			}
			else {
				spawn->CameraAngle = 0.0f;
			}

			gLookAngle = 10000.0f;
		}
	}
}

void Follow() {
	if (Positions.size() && StatusState == STATUS::ON) {
		auto spawn = GetCharInfo()->pSpawn;
		auto position = Positions.front();
		auto distance3d = GetDistance3D(spawn->X, spawn->Y, spawn->Z, position->x(), position->y(), position->z());
		if (distance3d > 50) {
			WriteChatf("[MQActorAdvPath] Warp detected, exiting...");
			EndFollowing();
			return;
		}

		if (GetDistance(spawn->X, spawn->Y, position->x(), position->y()) > 20) {
			LookAt(position->x(), position->y(), position->z());
			DoFwd(true);
		}
		else {
			Positions.pop();
		}
	}
}

/**
 * @fn InitializePlugin
 *
 * This is called once on plugin initialization and can be considered the startup
 * routine for the plugin.
 */
PLUGIN_API void InitializePlugin()
{
	DebugSpewAlways("[MQActorAdvPath]::Initializing version %f", MQ2Version);
	Subscribers.clear();
	std::queue<std::shared_ptr<proto::actorfollowee::Position>>().swap(Positions);

	s_DropBox = postoffice::AddActor("actorbots", ReceivedMessageHandler);

	// Examples:
	AddCommand("/actfollow", FollowCommand);
	pMQActorAdvPathType = new MQActorAdvPathType;
	AddMQ2Data("ActorAdvPath", dataActorBots);

	WriteChatf("[MQActorAdvPath] \ayv%1.0f\ax", MQ2Version);
}

/**
 * @fn ShutdownPlugin
 *
 * This is called once when the plugin has been asked to shutdown.  The plugin has
 * not actually shut down until this completes.
 */
PLUGIN_API void ShutdownPlugin()
{
	DebugSpewAlways("[MQActorAdvPath]:: Shutting down");
	s_DropBox.Remove();
	RemoveCommand("/actfollow");
	RemoveMQ2Data("ActorAdvPath");
	delete pMQActorAdvPathType;
	//ClearAll();
}

/**
 * @fn OnCleanUI
 *
 * This is called once just before the shutdown of the UI system and each time the
 * game requests that the UI be cleaned.  Most commonly this happens when a
 * /loadskin command is issued, but it also occurs when reaching the character
 * select screen and when first entering the game.
 *
 * One purpose of this function is to allow you to destroy any custom windows that
 * you have created and cleanup any UI items that need to be removed.
 */
PLUGIN_API void OnCleanUI()
{
	// DebugSpewAlways("MQActorAdvPath::OnCleanUI()");
}

/**
 * @fn OnReloadUI
 *
 * This is called once just after the UI system is loaded. Most commonly this
 * happens when a /loadskin command is issued, but it also occurs when first
 * entering the game.
 *
 * One purpose of this function is to allow you to recreate any custom windows
 * that you have setup.
 */
PLUGIN_API void OnReloadUI()
{
	// DebugSpewAlways("MQActorAdvPath::OnReloadUI()");
}

/**
 * @fn OnDrawHUD
 *
 * This is called each time the Heads Up Display (HUD) is drawn.  The HUD is
 * responsible for the net status and packet loss bar.
 *
 * Note that this is not called at all if the HUD is not shown (default F11 to
 * toggle).
 *
 * Because the net status is updated frequently, it is recommended to have a
 * timer or counter at the start of this call to limit the amount of times the
 * code in this section is executed.
 */
PLUGIN_API void OnDrawHUD()
{
	/*
		static std::chrono::steady_clock::time_point DrawHUDTimer = std::chrono::steady_clock::now();
		// Run only after timer is up
		if (std::chrono::steady_clock::now() > DrawHUDTimer)
		{
			// Wait half a second before running again
			DrawHUDTimer = std::chrono::steady_clock::now() + std::chrono::milliseconds(500);
			DebugSpewAlways("MQActorAdvPath::OnDrawHUD()");
		}
	*/
}

/**
 * @fn SetGameState
 *
 * This is called when the GameState changes.  It is also called once after the
 * plugin is initialized.
 *
 * For a list of known GameState values, see the constants that begin with
 * GAMESTATE_.  The most commonly used of these is GAMESTATE_INGAME.
 *
 * When zoning, this is called once after @ref OnBeginZone @ref OnRemoveSpawn
 * and @ref OnRemoveGroundItem are all done and then called once again after
 * @ref OnEndZone and @ref OnAddSpawn are done but prior to @ref OnAddGroundItem
 * and @ref OnZoned
 *
 * @param GameState int - The value of GameState at the time of the call
 */
PLUGIN_API void SetGameState(int GameState)
{
	// DebugSpewAlways("MQActorAdvPath::SetGameState(%d)", GameState);
	if (GameState == GAMESTATE_CHARSELECT) {
		Subscribers.clear();
		EndFollowing();
	}
}

/**
 * @fn OnPulse
 *
 * This is called each time MQ2 goes through its heartbeat (pulse) function.
 *
 * Because this happens very frequently, it is recommended to have a timer or
 * counter at the start of this call to limit the amount of times the code in
 * this section is executed.
 */
PLUGIN_API void OnPulse()
{
	static std::chrono::steady_clock::time_point PulseTimer = std::chrono::steady_clock::now();
	if (GetGameState() == GAMESTATE_INGAME) {
		// Run only after timer is up
		if (std::chrono::steady_clock::now() > PulseTimer) {
			PulseTimer = std::chrono::steady_clock::now() + std::chrono::milliseconds(50);
			NotifyActorBotManager();
		}
	}
}

/**
 * @fn OnWriteChatColor
 *
 * This is called each time WriteChatColor is called (whether by MQ2Main or by any
 * plugin).  This can be considered the "when outputting text from MQ" callback.
 *
 * This ignores filters on display, so if they are needed either implement them in
 * this section or see @ref OnIncomingChat where filters are already handled.
 *
 * If CEverQuest::dsp_chat is not called, and events are required, they'll need to
 * be implemented here as well.  Otherwise, see @ref OnIncomingChat where that is
 * already handled.
 *
 * For a list of Color values, see the constants for USERCOLOR_.  The default is
 * USERCOLOR_DEFAULT.
 *
 * @param Line const char* - The line that was passed to WriteChatColor
 * @param Color int - The type of chat text this is to be sent as
 * @param Filter int - (default 0)
 */
PLUGIN_API void OnWriteChatColor(const char* Line, int Color, int Filter)
{
	// DebugSpewAlways("MQActorAdvPath::OnWriteChatColor(%s, %d, %d)", Line, Color, Filter);
}

/**
 * @fn OnIncomingChat
 *
 * This is called each time a line of chat is shown.  It occurs after MQ filters
 * and chat events have been handled.  If you need to know when MQ2 has sent chat,
 * consider using @ref OnWriteChatColor instead.
 *
 * For a list of Color values, see the constants for USERCOLOR_. The default is
 * USERCOLOR_DEFAULT.
 *
 * @param Line const char* - The line of text that was shown
 * @param Color int - The type of chat text this was sent as
 *
 * @return bool - Whether to filter this chat from display
 */
PLUGIN_API bool OnIncomingChat(const char* Line, DWORD Color)
{
	if (!_stricmp(Line, "You have been summoned!") && FollowState == FOLLOW::ON) {
		WriteChatf("[MQActorAdvPath]:: Summon detected");
		EndFollowing();
	}

	return false;
}

/**
 * @fn OnAddSpawn
 *
 * This is called each time a spawn is added to a zone (ie, something spawns). It is
 * also called for each existing spawn when a plugin first initializes.
 *
 * When zoning, this is called for all spawns in the zone after @ref OnEndZone is
 * called and before @ref OnZoned is called.
 *
 * @param pNewSpawn PSPAWNINFO - The spawn that was added
 */
PLUGIN_API void OnAddSpawn(PSPAWNINFO pNewSpawn)
{
	// DebugSpewAlways("MQActorAdvPath::OnAddSpawn(%s)", pNewSpawn->Name);
}

/**
 * @fn OnRemoveSpawn
 *
 * This is called each time a spawn is removed from a zone (ie, something despawns
 * or is killed).  It is NOT called when a plugin shuts down.
 *
 * When zoning, this is called for all spawns in the zone after @ref OnBeginZone is
 * called.
 *
 * @param pSpawn PSPAWNINFO - The spawn that was removed
 */
PLUGIN_API void OnRemoveSpawn(PSPAWNINFO pSpawn)
{
	// DebugSpewAlways("MQActorAdvPath::OnRemoveSpawn(%s)", pSpawn->Name);
}

/**
 * @fn OnAddGroundItem
 *
 * This is called each time a ground item is added to a zone (ie, something spawns).
 * It is also called for each existing ground item when a plugin first initializes.
 *
 * When zoning, this is called for all ground items in the zone after @ref OnEndZone
 * is called and before @ref OnZoned is called.
 *
 * @param pNewGroundItem PGROUNDITEM - The ground item that was added
 */
PLUGIN_API void OnAddGroundItem(PGROUNDITEM pNewGroundItem)
{
	// DebugSpewAlways("MQActorAdvPath::OnAddGroundItem(%d)", pNewGroundItem->DropID);
}

/**
 * @fn OnRemoveGroundItem
 *
 * This is called each time a ground item is removed from a zone (ie, something
 * despawns or is picked up).  It is NOT called when a plugin shuts down.
 *
 * When zoning, this is called for all ground items in the zone after
 * @ref OnBeginZone is called.
 *
 * @param pGroundItem PGROUNDITEM - The ground item that was removed
 */
PLUGIN_API void OnRemoveGroundItem(PGROUNDITEM pGroundItem)
{
	// DebugSpewAlways("MQActorAdvPath::OnRemoveGroundItem(%d)", pGroundItem->DropID);
}

/**
 * @fn OnBeginZone
 *
 * This is called just after entering a zone line and as the loading screen appears.
 */
PLUGIN_API void OnBeginZone()
{
	// DebugSpewAlways("MQActorAdvPath::OnBeginZone()");
	Subscribers.clear();
	EndFollowing();
}

/**
 * @fn OnEndZone
 *
 * This is called just after the loading screen, but prior to the zone being fully
 * loaded.
 *
 * This should occur before @ref OnAddSpawn and @ref OnAddGroundItem are called. It
 * always occurs before @ref OnZoned is called.
 */
PLUGIN_API void OnEndZone()
{
	// DebugSpewAlways("MQActorAdvPath::OnEndZone()");
}

/**
 * @fn OnZoned
 *
 * This is called after entering a new zone and the zone is considered "loaded."
 *
 * It occurs after @ref OnEndZone @ref OnAddSpawn and @ref OnAddGroundItem have
 * been called.
 */
PLUGIN_API void OnZoned()
{
	// DebugSpewAlways("MQActorAdvPath::OnZoned()");
}

/**
 * @fn OnUpdateImGui
 *
 * This is called each time that the ImGui Overlay is rendered. Use this to render
 * and update plugin specific widgets.
 *
 * Because this happens extremely frequently, it is recommended to move any actual
 * work to a separate call and use this only for updating the display.
 */
PLUGIN_API void OnUpdateImGui()
{
	/*
		if (GetGameState() == GAMESTATE_INGAME)
		{
			if (ShowMQActorAdvPathWindow)
			{
				if (ImGui::Begin("MQActorAdvPath", &ShowMQActorAdvPathWindow, ImGuiWindowFlags_MenuBar))
				{
					if (ImGui::BeginMenuBar())
					{
						ImGui::Text("MQActorAdvPath is loaded!");
						ImGui::EndMenuBar();
					}
				}
				ImGui::End();
			}
		}
	*/
}

/**
 * @fn OnMacroStart
 *
 * This is called each time a macro starts (ex: /mac somemacro.mac), prior to
 * launching the macro.
 *
 * @param Name const char* - The name of the macro that was launched
 */
PLUGIN_API void OnMacroStart(const char* Name)
{
	// DebugSpewAlways("MQActorAdvPath::OnMacroStart(%s)", Name);
}

/**
 * @fn OnMacroStop
 *
 * This is called each time a macro stops (ex: /endmac), after the macro has ended.
 *
 * @param Name const char* - The name of the macro that was stopped.
 */
PLUGIN_API void OnMacroStop(const char* Name)
{
	// DebugSpewAlways("MQActorAdvPath::OnMacroStop(%s)", Name);
}

/**
 * @fn OnLoadPlugin
 *
 * This is called each time a plugin is loaded (ex: /plugin someplugin), after the
 * plugin has been loaded and any associated -AutoExec.cfg file has been launched.
 * This means it will be executed after the plugin's @ref InitializePlugin callback.
 *
 * This is also called when THIS plugin is loaded, but initialization tasks should
 * still be done in @ref InitializePlugin.
 *
 * @param Name const char* - The name of the plugin that was loaded
 */
PLUGIN_API void OnLoadPlugin(const char* Name)
{
	// DebugSpewAlways("MQActorAdvPath::OnLoadPlugin(%s)", Name);
}

/**
 * @fn OnUnloadPlugin
 *
 * This is called each time a plugin is unloaded (ex: /plugin someplugin unload),
 * just prior to the plugin unloading.  This means it will be executed prior to that
 * plugin's @ref ShutdownPlugin callback.
 *
 * This is also called when THIS plugin is unloaded, but shutdown tasks should still
 * be done in @ref ShutdownPlugin.
 *
 * @param Name const char* - The name of the plugin that is to be unloaded
 */
PLUGIN_API void OnUnloadPlugin(const char* Name)
{
	// DebugSpewAlways("MQActorAdvPath::OnUnloadPlugin(%s)", Name);
}