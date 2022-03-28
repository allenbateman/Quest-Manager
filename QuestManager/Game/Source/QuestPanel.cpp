#include "QuestPanel.h"
#include "Log.h"
#include "App.h"
#include "GuiManager.h"
#include "QuestManager.h"

QuestPanel::QuestPanel(bool active) : GuiPanel(active)
{
	Active = active;
}

QuestPanel::~QuestPanel()
{
}

bool QuestPanel::Start()
{
	texture = app->guiManager->UItexture2;
	bounds = { 81,414,558,266 };
	position = { 81,414 };

	currentQuest = app->questManager->questList->start;

	nextButton = (GuiButton*)CreateGuiButton(6,app->guiManager,this, { 332, 610,52,56 });

	nextButton->texture = app->guiManager->UItexture2;
	nextButton->normalRec = { 0,297,56,52 };
	nextButton->focusedRec = { 0,349,56,52 };
	nextButton->pressedRec = { 0,349,56,52 };


    return true;
}

bool QuestPanel::Update(float dt, bool doLogic)
{
	if (!Active)
		return false;

	if (doLogic) {

		ListItem<GuiControl*>* control = controls.start;

		while (control != nullptr)
		{
			control->data->Update(dt);
			control = control->next;
		}

	}
}

bool QuestPanel::Draw()
{
	if (!Active)
		return false;


	if(texture != NULL)
	 app->render->DrawTexture(texture, position.x, position.y, &bounds);

	ListItem<GuiControl*>* control = controls.start;

	while (control != nullptr)
	{
		control->data->Draw(app->render);
		control = control->next;
	}


	if (currentQuest != nullptr && currentQuest->data->titleTex != NULL)
		app->render->DrawTexture(currentQuest->data->titleTex, 300, 433, &currentQuest->data->rTitle);

	if (currentQuest != nullptr && currentQuest->data->descriptionTex != NULL)
		app->render->DrawTexture(currentQuest->data->descriptionTex, 134, 450, &currentQuest->data->rDescription);


	return true;
}

bool QuestPanel::CleanUp()
{
	ListItem<GuiControl*>* control = controls.start;

	while (control != nullptr)
	{
		control->data->CleanUp();
		control = control->next;
	}
	return true;
}

bool QuestPanel::OnGuiMouseClickEvent(GuiControl* control)
{
	LOG("Here");
	if (control->id == nextButton->id)
	{
		currentQuest = currentQuest->next;

		if (currentQuest == nullptr)
		{
			currentQuest = app->questManager->questList->start;
		}
	}

	return true;
}
