
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
#include "GuiManager.h"


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


	return true;
}

// Called each loop iteration
bool Scene1::PostUpdate()
{
	bool ret = true;



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
	return true;
}
