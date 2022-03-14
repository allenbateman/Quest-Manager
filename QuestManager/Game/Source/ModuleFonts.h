#ifndef __MODULE_FONTS_H__
#define __MODULE_FONTS_H__

#include "Module.h"
#include "SDL\include\SDL_pixels.h"
#include "External/SDL_ttf/include/SDL_ttf.h"

#define MAX_FONTS 10
#define MAX_FONT_CHARS 256

struct SDL_Texture;

struct Font
{
	// Lookup table. All characters displayed in the same order as the texture
	char table[MAX_FONT_CHARS];

	// The font texture
	SDL_Texture* texture = nullptr;

	// Font setup data
	uint totalLength;
	uint rows, columns;
	uint char_w, char_h;
};

class ModuleFonts : public Module
{
public:

	// Constructor
	ModuleFonts(bool isEnabled);

	// Destructor
	~ModuleFonts();

	bool Start();
	bool CleanUp();
	bool Update(float dt);

	//Load font
	int LoadTIFF(const char* fontPath, int fontSize);

	//Unload font
	void UnLoadTIFF(int font_id);

	// Create a surface from font
	// Returns a font index from the fonts array
	// Param rect			- The rectangle where the text will be displayed
	// Param fontIndex		- The index to refer to a font 
	// Param text			- The text to dispaly
	// Param color			- The color to render the text
	void DrawText(SDL_Rect rect, int fontIndex, const char* text, SDL_Color color) const;

private:
	// An array to keep track and store all loaded fonts
	TTF_Font* fonts[MAX_FONTS];
	SDL_Texture* texture;
	SDL_Rect dpsRect;//

	int basicFont;
};


#endif // __ModuleFonts_H__