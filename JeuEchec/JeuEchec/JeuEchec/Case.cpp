#include "Case.h"
#include "Piece.h"

Case::Case(const int x, const int y, std::shared_ptr<Piece> aPiece)
{
	XPos = x;
	YPos = y;
	gCase = { x, y, 100, 100 };
	gPiece = aPiece;
	gContours = IMG_Load("images/Contour.png");
	m_Highlight = false;
}

Case::~Case()
{
}

void Case::Render(SDL_Surface* gScreenSurface)
{
	if (gPiece != nullptr)
	{
		gPiece->Render(gScreenSurface, &gCase);
	}
	
	if (m_Highlight)
	{
		SDL_BlitSurface(gContours, NULL, gScreenSurface, &gCase);
	}
}

void Case::Reset() 
{
	gCase.x = XPos;
	gCase.y = YPos;
}
