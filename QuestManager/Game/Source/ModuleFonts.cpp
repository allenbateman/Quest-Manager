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

	LOG("We compiled against SDL version %u.%u.%u ...\n",
		compiled.major, compiled.minor, compiled.patch);

	LOG("TTF status %i", TTF_Init());
	if (TTF_Init() == -1) {
		LOG("Can't init ttf library");
		LOG(TTF_GetError());
	}

	font = TTF_OpenFont("./Assets/GUI/Fonts/RobotoMedium.ttf", 24);
	if (font == NULL)
	{
		LOG("can't load font");
		LOG(TTF_GetError());
	}

	SDL_Color color = { 255, 255, 255 };
	SDL_Surface* surface = TTF_RenderText_Solid(font,
		"Project2", color);


	texture = SDL_CreateTextureFromSurface(app->render->renderer, surface);

	SDL_RenderCopy(app->render->renderer, texture, NULL, NULL);
	SDL_RenderPresent(app->render->renderer);

	int texW = 2;
	int texH = 2;
	SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
	dstrect = { 0, 0, texW, texH };


	return true;
}

bool ModuleFonts::CleanUp()
{


	TTF_CloseFont(font);
	return true;
}

bool ModuleFonts::Update(float dt)
{

	app->render->DrawTexture(texture,100, 100, &dstrect, 0.0f, false);

	return true;
}



bool ModuleFonts::LoadTIFF(const char* fontPath)
{

	//this opens a font style and sets a size


	return false;
}

// Load new texture from file path
int ModuleFonts::Load(const char* texture_path, const char* characters, uint rows)
{
	int id = -1;

	if(texture_path == nullptr || characters == nullptr || rows == 0)
	{
		LOG("Could not load font");
		return id;
	}

	SDL_Texture* tex = app->tex->Load(texture_path);

	if(tex == nullptr || strlen(characters) >= MAX_FONT_CHARS)
	{
		LOG("Could not load font at %s with characters '%s'", texture_path, characters);
		return id;
	}

	id = 0;
	for(; id < MAX_FONTS; ++id)
		if(fonts[id].texture == nullptr)
			break;

	if(id == MAX_FONTS)
	{
		LOG("Cannot load font %s. Array is full (max %d).", texture_path, MAX_FONTS);
		return id;
	}

	Font& font = fonts[id];

	font.texture = tex;
	font.rows = rows;

	strcpy_s(fonts[id].table, MAX_FONT_CHARS, characters);
	font.totalLength = strlen(characters);
	font.columns = fonts[id].totalLength / rows;

	uint tex_w, tex_h;
	app->tex->GetSize(tex, tex_w, tex_h);
	font.char_w = tex_w / font.columns;
	font.char_h = tex_h / font.rows;

	LOG("Successfully loaded BMP font from %s", texture_path);

	return id;
}

void ModuleFonts::UnLoad(int font_id)
{
	if(font_id >= 0 && font_id < MAX_FONTS && fonts[font_id].texture != nullptr)
	{
		app->tex->UnLoad(fonts[font_id].texture);
		fonts[font_id].texture = nullptr;
		LOG("Successfully Unloaded BMP font_id %d", font_id);
	}
}

void ModuleFonts::BlitText(int x, int y, int font_id, const char* text) const
{
	if(text == nullptr || font_id < 0 || font_id >= MAX_FONTS || fonts[font_id].texture == nullptr)
	{
		LOG("Unable to render text with bmp font id %d", font_id);
		return;
	}

	const Font* font = &fonts[font_id];
	SDL_Rect spriteRect;
	uint len = strlen(text);

	spriteRect.w = font->char_w;
	spriteRect.h = font->char_h;

	for(uint i = 0; i < len; ++i)
	{
		uint charIndex = 0;

		// Find the location of the current character in the lookup table
		for (uint j = 0; j < font->totalLength; ++j)
		{
			if (font->table[j] == text[i])
			{
				charIndex = j;
				break;
			}
		}

		// Retrieve the position of the current character in the sprite
		spriteRect.x = spriteRect.w * (charIndex % font->columns);
		spriteRect.y = spriteRect.h * (charIndex / font->columns);

		app->render->DrawTexture(font->texture, x, y, &spriteRect, 0.0f, false);

		// Advance the position where we blit the next character
		x += spriteRect.w;
	}
}
