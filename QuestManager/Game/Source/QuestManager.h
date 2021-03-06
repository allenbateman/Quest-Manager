#include "Module.h"
#include "List.h"
#include "Quest.h"
#include "PugiXml/src/pugixml.hpp"
#include "App.h"
#include "ModuleFonts.h"

#define QUEST_FILE "quests.xml"

class QuestManager : public Module {

public:
	QuestManager(bool isActive);
	~QuestManager();

	bool Awake(pugi::xml_node& config);
	bool Start();
	bool CleanUp();

public: 

	List<Quest*>* questList = new List<Quest*>();
	List<Quest*>* currentQuestList = new List<Quest*>();

	//Activate Quest
	void ActivateQuest(int questID);

	//Cancel Quest
	void CanelQuest(int questID);

	//Complete Quest
	void CompleteQuest(int questID);

	//Finish Quest
	void FinishQuest(int questID);

	//Add item
	void AddItem();

	//Get available quest 
	bool GetAvailableQuest(int questID);

	//Get active quest
	bool GetActiveQuest(int questID);

	//Get complete quest but not Done (get rewards etc)
	bool GetCompletedQuest(int questID);

	//Load quest files 
	bool QuestManager::Load(const char* path);

	// Load / Save
	bool LoadState(pugi::xml_node&);
	bool SaveState(pugi::xml_node&) const;


	SString folder;
	SString questFile;
};