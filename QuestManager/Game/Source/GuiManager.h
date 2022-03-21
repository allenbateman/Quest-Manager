#ifndef __GUIMANAGER_H__
#define __GUIMANAGER_H__

#include "Module.h"

#include "GuiControl.h"

#include "List.h"

class GuiManager : public Module
{
public:

	// Constructor
	GuiManager(bool isActive);

	// Destructor
	virtual ~GuiManager();

	// Called before the first frame
	 bool Start();

	 bool Update(float dt);

	bool UpdateAll(float dt,bool logic);

	bool Draw();

	// Called before quitting
	bool CleanUp();

	//bool OnGuiMouseClickEvent(GuiControl* control);

	// Additional methods
	GuiControl* CreateGuiControl(GuiControlType type, int id, SDL_Rect bounds, Module* observer, const char* text ="", int fontid = 0, SDL_Rect sliderBounds = {0,0,0,0});
	GuiControl* CreateGuiButton(int id, Module* observer, SDL_Rect bounds, const char* text = "", int fontId = 0, SDL_Color textColor = { 255,255,255 });
	GuiControl* CreateGuiSlider(int id, Module* observer, SDL_Rect bounds,SDL_Rect sliderBounds);
	GuiControl* CreateGuiCheckBox(int id, Module* observer, SDL_Rect bounds);
	
	
	void DestroyGuiControl(GuiControl* entity);
	void AddGuiControl(GuiControl* entity);

public:

	List<GuiControl*> controls;
//	List<GuiPanel*> panels;

	float accumulatedTime = 0.0f;
	float updateMsCycle = 0.0f;
	bool doLogic = false;

	SDL_Texture* UItexture = nullptr;
	SDL_Texture* UItexture2 = nullptr;

	int mainFont;
	int numberFont;
	bool Debug = false;
};

#endif // __GUIMANAGER_H__
