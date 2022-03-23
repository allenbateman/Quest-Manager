#pragma once
#include "GuiManager.h"
#include "List.h"

#include "GuiControl.h"

#include "SDL/include/SDL.h"

#include "GuiButton.h"
#include "GuiSlider.h"
#include "GuiToggle.h"
#include "GuiPanel.h"

class GuiPanel
{
public:
	GuiPanel(bool isActive);
	~GuiPanel();

	// Called before the first frame
	bool Start();

	bool Update(float dt, bool doLogic);

	bool UpdateAll(float dt, bool logic);

	bool Draw();

	// Called before quitting
	bool CleanUp();

	//create ui elements
	GuiControl* CreateGuiControl(GuiControlType type, int id, SDL_Rect bounds, Module* observer, const char* text = "", int fontid = 0, SDL_Rect sliderBounds = { 0,0,0,0 });
	GuiControl* CreateGuiButton(int id, Module* observer, SDL_Rect bounds, const char* text = "", int fontId = 0, SDL_Color textColor = { 255,255,255 });
	GuiControl* CreateGuiSlider(int id, Module* observer, SDL_Rect bounds, SDL_Rect sliderBounds);
	GuiControl* CreateGuiCheckBox(int id, Module* observer, SDL_Rect bounds);

public:


	List<GuiControl*> controls;

	SDL_Rect bounds;
	iPoint position;
	SDL_Texture* texture;
	bool Active;

};

