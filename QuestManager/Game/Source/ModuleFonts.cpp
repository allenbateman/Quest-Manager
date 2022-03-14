#include "ModuleFonts.h"
#include "App.h"
#include "Textures.h"
#include "Render.h"
#include "Log.h"
#include<string.h>





ModuleFonts::ModuleFonts(bool isEnabled) : Module(isEnabled)
{



}

ModuleFonts::~ModuleFonts()
{

}

bool ModuleFonts::Start()
{
	SDL_version compiled;
	SDL_version linked;

	SDL_VERSION(&compiled);
	SDL_GetVersion(&linked);
	
	// check SDL version 
	LOG("We compiled against SDL version %u.%u.%u ...\n",
		compiled.major, compiled.minor, compiled.patch);

	// initialize the TTF library
	LOG("TTF status %i", TTF_Init());
	if (TTF_Init() == -1) {
		LOG("Can't init ttf library");
		LOG(TTF_GetError());
	}

	basicFont = LoadTIFF("./Assets/GUI/Fonts/RobotoMedium.ttf", 24);

	return true;
}

bool ModuleFonts::CleanUp()
{

	return true;
}

bool ModuleFonts::Update(float dt)
{

	

	return true;
}

int ModuleFonts::LoadTIFF(const char* fontPath,int fontSize)
{

	int id = -1;
	if(fontPath == NULL || fontSize == NULL)
	{
		LOG("Could not load font...");
		return id;
	}

	id = 0;

	for (; id < MAX_FONTS; ++id)
		if (fonts[id]== nullptr)
			break;

	if (id == MAX_FONTS)
	{
		LOG("Cannot load font %s. Array is full (max %d).", fontPath, MAX_FONTS);
		return id;
	}

	//this opens a font style and sets a size
	fonts[id] = TTF_OpenFont(fontPath, fontSize);

	if (fonts[id] == nullptr)
	{
		LOG("can't load font");
		LOG(TTF_GetError());

		return -1;
	}


	return id;
}

void ModuleFonts::UnLoadTIFF(int font_id)
{
	if (font_id >= 0 && font_id < MAX_FONTS && fonts[font_id] != nullptr)
	{
		TTF_CloseFont(fonts[font_id]);
		fonts[font_id] = nullptr;
		LOG("Successfully Unloaded BMP font_id %d", font_id);
	}
}

void ModuleFonts::DrawText(SDL_Rect rect, int font_id, const char* text, SDL_Color color) const
{

	SDL_Surface* surface = TTF_RenderText_Solid(fonts[font_id],text, color);

	SDL_RenderCopy(app->render->renderer, texture, NULL, NULL);
	SDL_RenderPresent(app->render->renderer);
	SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
}


