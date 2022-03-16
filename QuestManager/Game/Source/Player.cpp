#include "Player.h"
#include "Globals.h"
#include "App.h"
#include "Audio.h"
#include "Input.h"
#include "Render.h"
#include "Log.h"
#include <SDL/include/SDL_scancode.h>


Player::Player()
{
}

Player::~Player()
{
}

// Load assets
bool Player::Start()
{
	
	return true;
}

bool Player::PreUpdate()
{
	

	return true;
}

// Update: draw background
bool Player::Update(float dt)
{
	bool ret = true;


	return ret;

}

bool Player::PostUpdate()
{
	
	return true;
}

// Unload assets
bool Player::CleanUp()
{


	
	return true;
}


void Player::OnCollision(PhysBody* bodyA, PhysBody* bodyB)
{
}

bool Player::LoadState(pugi::xml_node& data)
{
	bool ret = true;

	return ret;
}

bool Player::SaveState(pugi::xml_node& data) const
{
	bool ret = true;
	
	return ret;
}