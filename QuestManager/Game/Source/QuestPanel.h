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

	ListItem<Quest*>* currentQuest;

};

