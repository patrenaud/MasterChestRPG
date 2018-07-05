#pragma once
#include <vector>
#include <SDL_image.h>
#include <memory>
#include "Vector2.h"

class Piece;

class Case
{
public:
	Case(const int x, const int y, std::shared_ptr<Piece> aPiece = nullptr);
	~Case();

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

