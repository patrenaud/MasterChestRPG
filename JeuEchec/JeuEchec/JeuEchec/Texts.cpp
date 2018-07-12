#include "Texts.h"
#include "Board.h"

// This creates a lsit of Data containing Rects, Texts and Colors
std::vector<Texts::TextData> Texts::m_Texts = std::vector<Texts::TextData>();
SDL_Renderer* Texts::m_renderer = nullptr;
TTF_Font* Texts::m_Font = nullptr;


Texts::Texts()
{
	// All data is created in constructor

}

Texts::~Texts()
{

}

void Texts::Init(SDL_Window* window)
{
	TTF_Init();
	m_renderer = SDL_CreateRenderer(window, 0, SDL_RendererFlags::SDL_RENDERER_ACCELERATED);
	m_Font = TTF_OpenFont("./times.ttf", 18); // Gets the TimeNewRoman Font for texts

	CreateTexts();
	CreateRects();
	CreateColors();
}

void Texts::DrawTexts(SDL_Surface* surface)
{
	for (int i = 0; i < m_Texts.size(); i++)
	{
		// This creates all texts (with its font and color) on the screen SDL_Surface
		SDL_Surface* textSurface = TTF_RenderText_Solid(m_Font, m_Texts[i].text.c_str(), m_Texts[i].color);
		SDL_BlitSurface(textSurface, NULL, surface, &m_Texts[i].rect);
		SDL_FreeSurface(textSurface); // Not to Draw more than once at the same place
	}
}

// All Texts shown by data
void Texts::CreateTexts()
{
	m_Texts.push_back(TextData("Player Power # 1: Retreat = Brings a unit to its original position"));
	m_Texts.push_back(TextData("Player Power # 2: Second Breath = Reactivate skill for a unit"));
	m_Texts.push_back(TextData("Player Power # 3: Call To Arms! = Instantiate a peon in an original peon position"));
	m_Texts.push_back(TextData("Player Power # 4: Double Move = Make 2 moves in your turn"));
	m_Texts.push_back(TextData("Player Power # 5: Healer = Heals a unit to maximum health"));
	m_Texts.push_back(TextData("                  "));
	m_Texts.push_back(TextData("______________________________"));
	m_Texts.push_back(TextData("-----Unit Stats-----"));
	m_Texts.push_back(TextData("HP: "));
	m_Texts.push_back(TextData("Damage: "));
	m_Texts.push_back(TextData("Armor: "));
	m_Texts.push_back(TextData("Power Available? : "));
	m_Texts.push_back(TextData("                  "));
	m_Texts.push_back(TextData("                  "));
	m_Texts.push_back(TextData("-----Player Mana-----"));
	m_Texts.push_back(TextData("Player 1: "));
	m_Texts.push_back(TextData("Player 2: "));
}

void Texts::CreateColors()
{
	// All text is now white
	for (int i = 0; i < m_Texts.size(); i++)
	{
		m_Texts[i].color = { 255, 255, 255 };
	}
}

void Texts::CreateRects()
{
	// Creates text lines with a diffrence of 20 between all rects
	m_Texts[0].rect = { 810, 0, 200, 100 };
	for (int i = 1; i < m_Texts.size(); i++)
	{
		m_Texts[i].rect = m_Texts[i - 1].rect;
		m_Texts[i].rect.y += 40;		
	}
}

void Texts::Destroy()
{
	TTF_CloseFont(m_Font);
	TTF_Quit();
}


