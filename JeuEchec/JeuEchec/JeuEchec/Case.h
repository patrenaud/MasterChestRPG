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

	SDL_Rect& GetRect() { return gCase; } // Gets the Rect in that case
	std::shared_ptr<Piece>& GetPiece() { return gPiece; } // Returns a piece that belongs to this case

	const bool GetHighlight() { return m_Highlight; } // Tells if case is highlighted
	void SetHighlight(bool IsHighlight) { m_Highlight = IsHighlight; } // Makes a case highlighted

	std::shared_ptr<Vector2> GetOrigin() { return std::make_shared<Vector2>(XPos, YPos); }
	const int GetX() { return XPos / 100; }
	const int GetY() { return YPos / 100; }
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

