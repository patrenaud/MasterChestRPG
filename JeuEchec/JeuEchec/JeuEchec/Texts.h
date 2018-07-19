#pragma once
#include "Board.h"
#include <SDL_ttf.h>

static class Texts
{



public:
	enum ETextType
	{
		Hp = 8,
		Damage = 9,
		Armor = 10,
		Power = 11,
		PowerText = 12,
		Player1 = 15,
		Player2 = 16,	
		Playing = 17
	};
	struct TextData
	{
		SDL_Color color;
		SDL_Rect rect;
		std::string text;
		TextData(std::string aText)
		{
			text = aText;
		}
	};

	Texts();
	~Texts();

	static std::vector<TextData> m_Texts;
	static void Init(SDL_Window* window); // First function called
	static void CreateTexts(); // Creates all strings used in texts
	static void CreateRects(); // Creates all Rects used to position texts
	static void CreateColors(); // Creates color for all string texts in Rects
	static void DrawTexts(SDL_Surface* surface); // DrawTexts is used to print all on the screen

private:

	void Destroy();
	static TTF_Font* m_Font;
	static SDL_Renderer* m_renderer;

};

