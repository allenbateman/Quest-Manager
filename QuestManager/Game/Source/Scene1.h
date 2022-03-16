#ifndef __SCENE1_H__
#define __SCENE1_H__

#include "Module.h"
#include "p2List.h"
#include "Globals.h"
#include "Animation.h"
#include "GuiButton.h"
#include "GuiSlider.h"
#include "GuiPanel.h"
#include "GuiToggle.h"

struct SDL_Texture;

class Scene1 : public Module
{
public:

	Scene1(bool isActive);

	// Destructor
	virtual ~Scene1();

	// Called before render is available
	bool Awake();

	// Called before the first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called each loop iteration
	bool Update(float dt);

	// Called before all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	void Enable();
	void Disable();

	// Load / Save
	bool LoadState(pugi::xml_node&);
	bool SaveState(pugi::xml_node&) const;


	bool OnGuiMouseClickEvent(GuiControl* control);

private:
	SDL_Texture* img;

	GuiPanel* pausePanel = NULL;
	GuiButton* resumeButton = NULL;
	GuiButton* settingsButton = NULL;
	GuiButton* backToTitleButton = NULL;
	GuiButton* exitButton = NULL;
	GuiButton* closePanelBttn2 = NULL;

	GuiPanel* UiPanel = NULL;

};

#endif // __SCENE1_H__