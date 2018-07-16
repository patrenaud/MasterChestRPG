#pragma once
#include <vector>
#include <SDL_image.h>
#include <memory>
#include "Vector2.h"
#include "Piece.h"

class Piece;

class Case
{
public:
	Case(const int x, const int y, Piece::PieceType a_PieceType = Piece::PieceType::none, const bool is_Black = false);
	~Case();

	const bool GetHighlight() { return m_Highlight; }
	SDL_Rect& GetRect() { return gCase; }
	std::shared_ptr<Piece>& GetPiece() { return gPiece; }
	void SetHighlight(bool IsHighlight) { m_Highlight = IsHighlight; }
	std::shared_ptr<Vector2> GetOrigin() { return std::make_shared<Vector2>(XPos, YPos); }	
	void Render(SDL_Surface* gScreenSurface);

	void Reset();
	
private:
	SDL_Rect gCase;
	SDL_Surface* gContours;
	int XPos;
	int YPos;
	bool m_Highlight;
	std::shared_ptr<Piece> gPiece;

	

};

