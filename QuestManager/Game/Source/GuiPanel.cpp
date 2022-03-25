#include "GuiPanel.h"
#include "App.h"
#include "Render.h"

GuiPanel::GuiPanel(bool isActive)
{
	Active = isActive;
}

GuiPanel::~GuiPanel()
{
}

bool GuiPanel::Start()
{
	return true;
}

bool GuiPanel::Update(float dt ,bool doLogic)
{
	if (!Active)
		return false;

	UpdateAll(dt, doLogic);

	return true;
}

bool GuiPanel::UpdateAll(float dt, bool logic)
{

	if (logic) {

		ListItem<GuiControl*>* control = controls.start;

		while (control != nullptr)
		{
			control->data->Update(dt);
			control = control->next;
		}

	}
	return true;
}

bool GuiPanel::Draw()
{
	if (!Active)
		return false;


	app->render->DrawTexture(texture,position.x, position.y,&bounds);

	ListItem<GuiControl*>* control = controls.start;

	while (control != nullptr)
	{
		control->data->Draw(app->render);
		control = control->next;
	}
	return true;
}

bool GuiPanel::CleanUp()
{
	delete texture;
	texture = nullptr;

	ListItem<GuiControl*>* control = controls.start;

	while (control != nullptr)
	{
		control->data->CleanUp();
	}

	return true;

}

void GuiPanel::OnGuiMouseClickEvent(GuiControl* control)
{
}


