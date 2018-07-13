#include "Piece.h"
#include "Board.h"
#include <SDL_image.h>


Piece::Piece(bool IsBlack)
	: isBlack(IsBlack)
	
{	
}

Piece::~Piece()
{
	//Free loaded image
	SDL_FreeSurface(m_Texture);
	m_Texture = NULL;
}

void Piece::Render(SDL_Surface* gScreenSurface, SDL_Rect* Rect)
{
	SDL_BlitSurface(m_Texture, NULL, gScreenSurface, Rect);
}

void Piece::SetHP(int damage)
{
	if (damage - m_Stats.armor > 0)
	{
		m_Stats.hp -= damage - m_Stats.armor;
	}
}

void Piece::Attack(std::shared_ptr<Piece> piece)
{
	piece->SetHP(m_Stats.attack);
}