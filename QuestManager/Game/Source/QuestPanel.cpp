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

	nextButton = (GuiButton*)CreateGuiButton(0,app->guiManager,this, { 332, 610,52,56 });

	nextButton->texture = app->guiManager->UItexture2;
	nextButton->normalRec = { 0,297,56,52 };
	nextButton->focusedRec = { 0,349,56,52 };
	nextButton->pressedRec = { 0,349,56,52 };

	cancelButton = (GuiButton*)CreateGuiButton(1, app->guiManager, this, { 270, 610,52,56 });

	cancelButton->texture = app->guiManager->UItexture2;
	cancelButton->normalRec = {0,399,56,52};
	cancelButton->focusedRec = {0,451,56,52};
	cancelButton->pressedRec = {0,451,56,52};

	acceptButton = (GuiButton*)CreateGuiButton(2, app->guiManager, this, { 210, 610,52,56 });

	acceptButton->texture = app->guiManager->UItexture2;
	acceptButton->normalRec = { 0,613,56,52 };
	acceptButton->focusedRec = { 0,664,56,52 };
	acceptButton->pressedRec = { 0,664,56,52 };

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

	switch (currentQuest->data->progress)
	{
	case Quest::NOT_AVAILABLE:
		break;
	case Quest::AVAILABLE:

		if (currentQuest != nullptr && currentQuest->data->descriptionTex != NULL)
			app->render->DrawTexture(currentQuest->data->descriptionTex, 134, 450, &currentQuest->data->rDescription);

		break;
	case Quest::ACTIVE:

		if (currentQuest != nullptr && currentQuest->data->descriptionTex != NULL)
			app->render->DrawTexture(currentQuest->data->descriptionTex, 134, 450, &currentQuest->data->rDescription);

		break;
	case Quest::COMPLETE:

		break;
	case Quest::DONE:

		break;

	default:
		break;
	}





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
	if (control->id == nextButton->id)
	{
		currentQuest = currentQuest->next;

		if (currentQuest == nullptr)
		{
			currentQuest = app->questManager->questList->start;
		}
	}
	else if (control->id == cancelButton->id)
	{
		currentQuest->data->progress = Quest::AVAILABLE;
	}
	else if (control->id == acceptButton->id)
	{
		currentQuest->data->progress = Quest::ACTIVE;
	}

	return true;
}
