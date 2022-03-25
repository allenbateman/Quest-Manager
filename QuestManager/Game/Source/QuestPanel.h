#pragma once
#include "GuiPanel.h"
class QuestPanel :  public GuiPanel
{
	 QuestPanel(bool active);
	~QuestPanel();


	bool Start() override;

	void OnGuiMouseClickEvent(GuiControl* control) override;
};

