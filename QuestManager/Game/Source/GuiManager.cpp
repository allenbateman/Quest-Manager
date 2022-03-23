#include "GuiManager.h"
#include "App.h"
#include "Textures.h"
#include "ModuleFonts.h"
#include "Window.h"
#include "Render.h"
#include "Audio.h"





GuiManager::GuiManager(bool isActive) :Module(isActive)
{
	name.Create("guiManager");
}

GuiManager::~GuiManager() {}

bool GuiManager::Start()
{

	UItexture = app->tex->Load("Assets/Spritesx16/GUI.png");
	UItexture2 = app->tex->Load("Assets/Spritesx16/GUI2.png");

	app->audio->LoadFx("Assets/audio/fx/buttonFocus.wav");
	app->audio->LoadFx("Assets/audio/fx/buttonPressed.wav");
	Debug = false;


	InitPanels();

	return true;
}


bool GuiManager::Update(float dt)
{	
	if (app->input->GetKey(SDL_SCANCODE_F8) == KEY_DOWN)
		Debug = !Debug;

	accumulatedTime += dt;
	if (accumulatedTime >= updateMsCycle) doLogic = true;


	UpdateAll(dt,doLogic);

	if (doLogic == true)
	{
		accumulatedTime = 0.0f;
		doLogic = false;
	}
	
	return true;
}

bool GuiManager::UpdateAll(float dt, bool doLogic) {

	if (doLogic) {

		ListItem<GuiPanel*>* panel = panels.start;

		while (panel != nullptr && panel->data->Active)
		{
			panel->data->Update(dt,doLogic);
			panel = panel->next;
		}

	}
	return true; 

}

bool GuiManager::PostUpdate() {

	ListItem<GuiPanel*>* panel = panels.start;

	while (panel != nullptr && panel->data->Active)
	{
		panel->data->Draw();
		panel = panel->next;
	}

	return true;

}

bool GuiManager::CleanUp()
{
	ListItem<GuiPanel*>* panel = panels.start;

	while (panel != nullptr)
	{
		panel->data->CleanUp();
		panel = panel->next;
	}

	panels.clear();

	delete UItexture;
	delete UItexture2;

	UItexture = nullptr;
	UItexture2 = nullptr;

	return true;
}

void GuiManager::InitPanels()
{
	questPanel = new GuiPanel(true);
	questPanel->texture = UItexture2;
	questPanel->bounds = { 81,414,558,266 };
	questPanel->position = { 81,414 };

	app->guiManager->panels.add(questPanel);

	GuiButton* button =(GuiButton*) questPanel->CreateGuiButton(6, this, { 332, 610,52,56 });

	button->texture = UItexture2;
	button->normalRec = { 0,297,56,52 };
	button->focusedRec = { 0,349,56,52 };

}




