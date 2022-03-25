#ifndef __GUIMANAGER_H__
#define __GUIMANAGER_H__

#include "Module.h"
#include "SDL/include/SDL.h"
#include "List.h"
#include "GuiPanel.h"
#include "GuiControl.h"


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

	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	//create ui elements
	GuiControl* CreateGuiControl(GuiControlType type, int id, SDL_Rect bounds, GuiPanel* observer, const char* text = "", int fontid = 0, SDL_Rect sliderBounds = { 0,0,0,0 });
	GuiControl* CreateGuiButton(int id, GuiPanel* observer, SDL_Rect bounds, const char* text = "", int fontId = 0, SDL_Color textColor = { 255,255,255 });
	GuiControl* CreateGuiSlider(int id, GuiPanel* observer, SDL_Rect bounds, SDL_Rect sliderBounds);
	GuiControl* CreateGuiCheckBox(int id, GuiPanel* observer, SDL_Rect bounds);

public:


	List<GuiPanel*> panels;

	float accumulatedTime = 0.0f;
	float updateMsCycle = 0.0f;
	bool doLogic = false;

	SDL_Texture* UItexture = nullptr;
	SDL_Texture* UItexture2 = nullptr;

	int mainFont;
	int numberFont;
	bool Debug = false;


	//gui panels used in the game
	GuiPanel* questPanel;

};

#endif // __GUIMANAGER_H__
