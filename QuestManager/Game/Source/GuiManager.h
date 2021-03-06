#ifndef __GUIMANAGER_H__
#define __GUIMANAGER_H__

#include "Module.h"
#include "SDL/include/SDL.h"
#include "List.h"
#include "GuiPanel.h"

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

	bool OnGuiMouseClickEvent(GuiControl* control);

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
