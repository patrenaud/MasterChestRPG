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
		Plaer1 = 15,
		Player2 = 16

	};
	static struct TextData
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
	static void Init(SDL_Window* window);
	static void CreateTexts();
	static void CreateRects();
	static void CreateColors();
	static void DrawTexts(SDL_Surface* surface);

private:	
		
	void Destroy();
	static TTF_Font* m_Font;
	static SDL_Renderer* m_renderer;

};

