#include "GuiManager.h"
#include "App.h"
#include "Textures.h"
#include "ModuleFonts.h"
#include "Window.h"
#include "Render.h"
#include "Audio.h"

#include "GuiButton.h"
#include "GuiSlider.h"
#include "GuiToggle.h"
#include "GuiPanel.h"




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

	return true;
}

GuiControl* GuiManager::CreateGuiControl(GuiControlType type, int id, SDL_Rect bounds, Module* observer, const char* text,int fontid, SDL_Rect sliderBounds)
{

	GuiControl* control = nullptr;

	//Call the constructor according to the GuiControlType
	switch (type)
	{
	case GuiControlType::BUTTON:
		control = new GuiButton(id, bounds, text, fontid);
		break;
	case GuiControlType::SLIDER:
		control = new GuiSlider(id, bounds, sliderBounds);
		break;
	case GuiControlType::CHECKBOX:
		control = new GuiToggle(id, bounds);
		break;
	
	// More Gui Controls can go here

	default:
		break;
	}

	//Set the observer
	control->SetObserver(observer);


	// Created GuiControls are added to the list of controls
	if (control != nullptr) controls.add(control);

	return control;
}

GuiControl* GuiManager::CreateGuiButton(int id, Module* observer, SDL_Rect bounds, const char* text, int fontId, SDL_Color textColor)
{
	GuiControl* control = nullptr;

	control = new GuiButton(id, bounds, text, fontId,textColor);
	control->SetObserver(observer);

	if (control != nullptr) controls.add(control);

	return control;
}

GuiControl* GuiManager::CreateGuiSlider(int id, Module* observer, SDL_Rect bounds, SDL_Rect sliderBounds)
{
	GuiControl* control = nullptr;

	control = new GuiSlider(id, bounds, sliderBounds);
	control->SetObserver(observer);

	if (control != nullptr) controls.add(control);

	return control;
}

GuiControl* GuiManager::CreateGuiCheckBox(int id, Module* observer, SDL_Rect bounds)
{
	GuiControl* control = nullptr;

	control = new GuiToggle(id, bounds);
	control->SetObserver(observer);

	if (control != nullptr) controls.add(control);

	return control;
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

		ListItem<GuiControl*>* control = controls.start;

		while (control != nullptr)
		{
			control->data->Update(dt);
			control = control->next;
		}

	}
	return true; 

}

bool GuiManager::Draw() {

	ListItem<GuiControl*>* control = controls.start;

	while (control != nullptr)
	{
		control->data->Draw(app->render);
		control = control->next;
	}

	return true;

}

bool GuiManager::CleanUp()
{
	ListItem<GuiControl*>* control = controls.start;

	while (control != nullptr)
	{
		RELEASE(control);
	}

	return true;
}




