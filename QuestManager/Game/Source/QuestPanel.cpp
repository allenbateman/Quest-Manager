#include "QuestPanel.h"
#include "App.h"
#include "GuiManager.h"
#include "Log.h"

QuestPanel::QuestPanel(bool active) : GuiPanel(active)
{
	Active = active;
}

QuestPanel::~QuestPanel()
{
}

bool QuestPanel::Start()
{
	//texture = app->guiManager->UItexture2;
	//bounds = { 81,414,558,266 };
	//position = { 81,414 };

	//app->guiManager->panels.add(this);

	//GuiButton* button = (GuiButton*)CreateGuiButton(6, this, { 332, 610,52,56 });

	//button->texture = app->guiManager->UItexture2;
	//button->normalRec = { 0,297,56,52 };
	//button->focusedRec = { 0,349,56,52 };
    return true;
}

void QuestPanel::OnGuiMouseClickEvent(GuiControl* control)
{
	LOG("Here");
}
