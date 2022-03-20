#pragma once
#include"SString.h"
#include "PugiXml/src/pugixml.hpp"

class Quest
{

public:
	enum QuestProgress { AVAILABLE, NOT_AVAILABLE, ACTIVE, COMPLETE, DONE }; //States a quest can have


	int id;							//Quest identification
	QuestProgress progress;			//State of the current quest 
	int nextQuest;					//next quest, if there is any (chain quest)

	int objective;					//Posible quest objectives
	int reward;						//Posible quest rewards
	int amount;

	SString title;					//Title for the quest
	SString description;			//What player has to know about the quest

	//virtual void Update();
	//// Load / Save
	//virtual bool LoadState(pugi::xml_node&);
	//virtual bool SaveState(pugi::xml_node&) const;

};

