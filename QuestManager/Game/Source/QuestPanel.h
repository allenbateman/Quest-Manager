#pragma once
#include "GuiPanel.h"
#include "List.h"
#include "Quest.h"

class QuestPanel :  public GuiPanel
{

public:
	QuestPanel(bool active);
	~QuestPanel();


	bool Start() override;
	bool Update(float dt, bool doLogic) override;
	bool Draw() override;
	bool CleanUp();

	bool OnGuiMouseClickEvent(GuiControl* control) override;

	GuiButton* nextButton;
	GuiButton* completeButton;
	GuiButton* dialogueButton;
	GuiButton* finishButton;
	GuiButton* cancelButton;

	ListItem<Quest*>* currentQuest;
	SDL_Texture* notAvailableTex;
	SDL_Rect notavailable;

	SDL_Texture* availableTex;
	SDL_Rect rAvailable;
};

