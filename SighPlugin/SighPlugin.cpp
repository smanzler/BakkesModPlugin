#include "pch.h"
#include "SighPlugin.h"

BAKKESMOD_PLUGIN(SighPlugin, "Sigh's Plugin", "1.0", PERMISSION_ALL)

void SighPlugin::onLoad()
{
	this->Log("This is my first BakkesMod Plugin");
	this->LoadHooks();
}

void SighPlugin::onUnload() 
{

}

void SighPlugin::LoadHooks()
{
	gameWrapper->HookEvent("Function TAGame.GameEvernt_Soccar_TA.EventMatchEnded", std::bind(&SighPlugin::GameEndedEvent, this, std::placeholders::_1));
	gameWrapper->HookEvent("Function TAGame.AchievementManager_TA.HandleMatchEnded", std::bind(&SighPlugin::GameEndedEvent, this, std::placeholders::_1));
}

void SighPlugin::GameEndedEvent(std::string name) 
{
	this->Log("Going to freeplay");
	cvarManager->executeCommand("load_freeplay");
}

void SighPlugin::Log(std::string msg)
{
	cvarManager->log(msg);
}