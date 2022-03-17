
#include "App.h"
#include "Input.h"
#include "Textures.h"
#include "Animation.h"
#include "Audio.h"
#include "Render.h"
#include "Window.h"
#include "Scene1.h"
#include "player.h"
#include "ModuleFonts.h"

#include "Defs.h"
#include "Log.h"

Scene1::Scene1(bool isActive) : Module(isActive)
{
	name.Create("level1");
}

// Destructor
Scene1::~Scene1()
{}

// Called before render is available
bool Scene1::Awake()
{
	LOG("Loading Scene 1");
	bool ret = true;

	return ret;
}

// Called before the first frame
bool Scene1::Start()
{

	LOG("start scene1");

	pausePanel = new GuiPanel(true);
	pausePanel->bounds = { 777,0,266 ,382 };
	pausePanel->position = { (app->win->GetWidth() * 40 / 100) ,(app->win->GetWidth() * 5 / 100) };
	
	resumeButton = (GuiButton*)pausePanel->CreateGuiButton(6, this, { pausePanel->position.x + 48, pausePanel->position.y + 90,170,60 }, "Resume",1, SDL_Color{32,27,46});
	resumeButton->texture = app->guiManager->UItexture2;
	resumeButton->normalRec = { 0,0,170,60 };
	resumeButton->focusedRec = { 0,119,170,60 };
	
	settingsButton = (GuiButton*)pausePanel->CreateGuiControl(GuiControlType::BUTTON, 2, { pausePanel->position.x + 48,pausePanel->position.y + 152,170,60 }, this, "Stteings", 0);
	settingsButton->texture = app->guiManager->UItexture2;
	settingsButton->normalRec = { 0,0,170,60 };
	settingsButton->focusedRec = { 0,119,170,60 };
	
	
	backToTitleButton = (GuiButton*)pausePanel->CreateGuiControl(GuiControlType::BUTTON, 5, { pausePanel->position.x + 48,pausePanel->position.y + 214,170,60 }, this, "Backtotitle", 0);
	backToTitleButton->texture = app->guiManager->UItexture2;
	backToTitleButton->normalRec = { 0,0,170,60 };
	backToTitleButton->focusedRec = { 0,119,170,60 };
	
	exitButton = (GuiButton*)pausePanel->CreateGuiControl(GuiControlType::BUTTON, 4, { pausePanel->position.x + 48,pausePanel->position.y + 276,170,60 }, this, "Exit", 0);
	exitButton->texture = app->guiManager->UItexture2;
	exitButton->normalRec = { 0,0,170,60 };
	exitButton->focusedRec = { 0,119,170,60 };

	return true;
}

// Called each loop iteration
bool Scene1::PreUpdate()
{

	return true;
}

// Called each loop iteration
bool Scene1::Update(float dt)
{

	if(app->input->GetKey(SDL_SCANCODE_L) == KEY_DOWN || app->input->GetKey(SDL_SCANCODE_F6) == KEY_DOWN)
		app->LoadGameRequest();

	if(app->input->GetKey(SDL_SCANCODE_S) == KEY_DOWN || app->input->GetKey(SDL_SCANCODE_F5) == KEY_DOWN)
		app->SaveGameRequest();

	pausePanel->Update(dt);

	return true;
}

// Called each loop iteration
bool Scene1::PostUpdate()
{
	bool ret = true;

	pausePanel->Draw();

	return ret;
}

// Called before quitting
bool Scene1::CleanUp()
{
	LOG("Disable scene 1");
	app->audio->StopMusic();
	return true;
}

void Scene1::Enable()
{
	LOG("Enable scene 1");
	Start();
}

void Scene1::Disable()
{
	LOG("Disable scene 1");
}

bool Scene1::LoadState(pugi::xml_node& data)
{
	bool ret = true;
	pugi::xml_node level = data.child("level1");
	return ret;
}

bool Scene1::SaveState(pugi::xml_node& data) const
{
	bool ret = true;
	pugi::xml_node level = data.append_child("level1");

	return ret;
}

bool Scene1::OnGuiMouseClickEvent(GuiControl* control)
{
	if (control->id == resumeButton->id)
	{
		pausePanel->Active = false;

	}
	else if (control->id == exitButton->id)
	{
		app->exit = true;
	}
	return true;
}
