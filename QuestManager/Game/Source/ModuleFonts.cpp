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

	basicFont = LoadTIFF("./Assets/GUI/Fonts/RobotoMedium.ttf", 48);

	textTex1 = LoadRenderedText(0, "Start", SDL_Color{ 255,155,0 });
	if (textTex1 == NULL)
		LOG("Did not load Text texture");
	textTex2 = LoadRenderedText(0, "Booo", SDL_Color{ 255,155,0 });
	//textTex3 = LoadRenderedText(0, "Oh no", SDL_Color{ 255,155,255 });
	return true;
}

bool ModuleFonts::CleanUp()
{
	if(textTex1 != NULL)
	  SDL_DestroyTexture(textTex1);
	if (textTex2 != NULL)
		SDL_DestroyTexture(textTex2);
	//if (textTex3 != NULL)
	//	SDL_DestroyTexture(textTex3);

	for (uint i = 0; i < MAX_FONTS; i++)
	{
		UnLoadTIFF(i);
	}
	return true;
}

bool ModuleFonts::Update(float dt)
{
	dpsRect = { 0,0,110,100 };
	app->render->DrawTexture(textTex1, 0, 0, &dpsRect, 0.0f, false);
	dpsRect = { 0,0,150,100 };
	app->render->DrawTexture(textTex2, 200, 0, &dpsRect, 0.0f, false);
	//dpsRect = { 450,250,100,100 };
	//app->render->DrawTexture(textTex3, 0, 0, &dpsRect, 0.0f, false);
	
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

SDL_Texture* ModuleFonts::LoadRenderedText(int font_id, const char* text, SDL_Color color)
{


	SDL_Surface* surface = TTF_RenderText_Solid(fonts[font_id],text, color);
	SDL_Texture* tex;
	if (surface == NULL)
	{
		LOG(TTF_GetError());
		return nullptr;
	}
	else {
		tex = SDL_CreateTextureFromSurface(app->render->renderer, surface);

		if (tex == NULL)
		{
		   LOG("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());		
		   return tex;

		}else{
			//Get image dimensions
			mWidth = surface->w;
			mHeight = surface->h;

			SDL_RenderCopy(app->render->renderer, tex, NULL, NULL);
			SDL_RenderPresent(app->render->renderer);

			SDL_QueryTexture(tex, NULL, NULL, &mWidth, &mHeight);
			dpsRect = {0, 0, mWidth, mHeight };
			return tex;
		}
		SDL_FreeSurface(surface);
	}	
}


