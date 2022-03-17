#include "QuestManager.h"

QuestManager::QuestManager(bool isActive) : Module(isActive)
{
}

QuestManager::~QuestManager()
{
}

bool QuestManager::Awake(pugi::xml_node&)
{

	pugi::xml_document questFile;
	pugi::xml_node config;
	pugi::xml_node configApp;

	bool ret = false;

	config = LoadConfig(configFile);

	if (config.empty() == false)
	{
		ret = true;
		configApp = config.child("app");

		title.Create(configApp.child("title").child_value());
		organization.Create(configApp.child("organization").child_value());
	}

	if (ret == true)
	{
		ListItem<Module*>* item;
		item = modules.start;

		while ((item != NULL) && (ret == true))
		{
			ret = item->data->Awake(config.child(item->data->name.GetString()));
			item = item->next;
		}
	}

	return true;
}



void QuestManager::ActivateQuest(int questID)
{
	ListItem<Quest>* currentQuest = questList->start;
	while (currentQuest != NULL)
	{

		if (currentQuest->data.id == questID && currentQuest->data.progress == Quest::AVAILABLE)
		{
			currentQuestList->add(currentQuest->data);
			currentQuest->data.progress = Quest::ACTIVE;
		}

		currentQuest = currentQuest->next;
	}
}

void QuestManager::CanelQuest(int questID)
{
	ListItem<Quest>* currentQuest = questList->start;
	while (currentQuest != NULL)
	{

		if (currentQuest->data.id == questID && currentQuest->data.progress == Quest::ACTIVE)
		{
			currentQuestList->add(currentQuest->data);
			currentQuest->data.progress = Quest::AVAILABLE;
		}

		currentQuest = currentQuest->next;
	}
}

void QuestManager::CompleteQuest(int questID)
{
	ListItem<Quest>* currentQuest = questList->start;
	while (currentQuest != NULL)
	{

		if (currentQuest->data.id == questID && currentQuest->data.progress == Quest::ACTIVE)
		{
			currentQuestList->add(currentQuest->data);
			currentQuest->data.progress = Quest::COMPLETE;
		}

		currentQuest = currentQuest->next;
	}
}

void QuestManager::FinishQuest(int questID)
{
	ListItem<Quest>* currentQuest = questList->start;
	while (currentQuest != NULL)
	{

		if (currentQuest->data.id == questID && currentQuest->data.progress == Quest::COMPLETE)
		{
			currentQuestList->add(currentQuest->data);
			currentQuest->data.progress = Quest::DONE;
		}

		currentQuest = currentQuest->next;
	}
}

void QuestManager::AddItem()
{
}

bool QuestManager::GetAvailableQuest(int questID)
{
	ListItem<Quest>* currentQuest = questList->start;
	while (currentQuest != NULL)
	{

		if (currentQuest->data.id == questID && currentQuest->data.progress == Quest::AVAILABLE)
			return true;

		currentQuest = currentQuest->next;
	}
	return false;
}

bool QuestManager::GetActiveQuest(int questID)
{
	ListItem<Quest>* currentQuest = questList->start;
	while (currentQuest != NULL)
	{

		if (currentQuest->data.id == questID && currentQuest->data.progress == Quest::ACTIVE)
			return true;

		currentQuest = currentQuest->next;
	}
	return false;
}

bool QuestManager::GetCompletedQuest(int questID)
{
	ListItem<Quest>* currentQuest = questList->start;
	while (currentQuest != NULL)
	{

		if (currentQuest->data.id == questID && currentQuest->data.progress == Quest::COMPLETE)
			return true;

		currentQuest = currentQuest->next;
	}
	return false;
}

pugi::xml_node QuestManager::LoadConfig(pugi::xml_document& configFile) const
{
	pugi::xml_node ret;

	pugi::xml_parse_result result = configFile.load_file(CONFIG_FILENAME);

	if (result == NULL) LOG("Could not load xml file: %s. pugi error: %s", CONFIG_FILENAME, result.description());
	else ret = configFile.child("config");



	return ret;
}