#pragma once
#include "GuiManager.h"

#include "List.h"
#include "SDL/include/SDL.h"


class GuiPanel
{
public:
	GuiPanel(bool isActive);
	~GuiPanel();

	// Called before the first frame to init all the elemnts of the Panel such as buttons and sliders...*
	virtual bool Start();

	bool Update(float dt, bool doLogic);

	bool UpdateAll(float dt, bool logic);

	bool Draw();

	// Called before quitting
	bool CleanUp();
	
	// this funtion will handle events recived on the panel
	virtual void OnGuiMouseClickEvent(GuiControl* control);



public:
	List<GuiControl*> controls;
	SDL_Rect bounds;
	iPoint position;
	SDL_Texture* texture;
	bool Active;

};

