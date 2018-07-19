#include "Case.h"
#include "Piece.h"
#include "PieceFactory.h"

Case::Case(const int x, const int y, Piece::PieceType a_PieceType, const bool is_Black)
{
	XPos = x;
	YPos = y;
	gCase = { x, y, 100, 100 };
	gContours = IMG_Load("images/Contour.png");
	m_Highlight = false;

	// Used to create piece 
	if (a_PieceType != Piece::PieceType::none)
	{
		Piece* piece = PieceFactory::CreatePiece(a_PieceType, is_Black);
		gPiece = std::shared_ptr<Piece>(piece);
	}
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
		SDL_BlitSurface(gContours, NULL, gScreenSurface, &gCase); // render for highlight
	}
}

void Case::Reset()
{
	gCase.x = XPos;
	gCase.y = YPos;
}
