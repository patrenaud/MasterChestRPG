#include "Board.h"
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <memory>
#include "PieceFactory.h"
#include "Case.h"

Board::Board()
{
	//Load PNG surface
	gPNGSurface = IMG_Load("images/ChestBoard.png");
	
	// Cr�ation du board
	gBoard = { 0, 0, 1000, 800 };

	// Cette boucle est pour cr�er les diff�rentes cases
	for (int i = 0; i < 8; i++)
	{
		gCase.push_back(std::vector<std::shared_ptr<Case>>());
		
		for (int j = 0; j < 8; j++)
		{
			if (i == 0)
			{
				if (j == 0 || j == 7)
				{
					gCase[i].push_back(std::make_shared<Case>(gBoard.x + 100 * j, gBoard.y + 100 * i, Piece::PieceType::Tour, false));
				}														 
				else if (j == 1 || j == 6)								 
				{														 
					gCase[i].push_back(std::make_shared<Case>(gBoard.x + 100 * j, gBoard.y + 100 * i, Piece::PieceType::Cheval, false));
				}														 
				else if (j == 2 || j == 5)								 
				{														 
					gCase[i].push_back(std::make_shared<Case>(gBoard.x + 100 * j, gBoard.y + 100 * i, Piece::PieceType::Fou, false));
				}														 
				else if (j == 3)										 
				{														 
					gCase[i].push_back(std::make_shared<Case>(gBoard.x + 100 * j, gBoard.y + 100 * i, Piece::PieceType::Reine, false));
				}														 
				else if (j == 4)										 
				{														 
					gCase[i].push_back(std::make_shared<Case>(gBoard.x + 100 * j, gBoard.y + 100 * i, Piece::PieceType::Roi, false));
				}
			}
			else if (i == 1)
			{
				gCase[i].push_back(std::make_shared<Case>(gBoard.x + 100 * j, gBoard.y + 100 * i, Piece::PieceType::Pion, false));
			}
			else if (i== 7)
			{
				if (j == 0 || j == 7)
				{
					gCase[i].push_back(std::make_shared<Case>(gBoard.x + 100 * j, gBoard.y + 100 * i, Piece::PieceType::Tour, true));
				}
				else if (j == 1 || j == 6)
				{
					gCase[i].push_back(std::make_shared<Case>(gBoard.x + 100 * j, gBoard.y + 100 * i, Piece::PieceType::Cheval, true));
				}
				else if (j == 2 || j == 5)
				{
					gCase[i].push_back(std::make_shared<Case>(gBoard.x + 100 * j, gBoard.y + 100 * i, Piece::PieceType::Fou, true));
				}
				else if (j == 3)
				{
					gCase[i].push_back(std::make_shared<Case>(gBoard.x + 100 * j, gBoard.y + 100 * i, Piece::PieceType::Reine, true));
				}
				else if (j == 4)
				{
					gCase[i].push_back(std::make_shared<Case>(gBoard.x + 100 * j, gBoard.y + 100 * i, Piece::PieceType::Roi, true));
				}
			}
			else if (i == 6)
			{
				gCase[i].push_back(std::make_shared<Case>(gBoard.x + 100 * j, gBoard.y + 100 * i, Piece::PieceType::Pion, true));
			}
			else
			{
				gCase[i].push_back(std::make_shared<Case>(gBoard.x + 100 * j, gBoard.y + 100 * i));
			}
		}
	}
}


Board::~Board()
{
	//Free loaded image
	SDL_FreeSurface(gPNGSurface);
	gPNGSurface = NULL;
}

void Board::Render(SDL_Surface* gScreenSurface)
{	
	//Apply the PNG pour toutes les cases
	SDL_BlitSurface(gPNGSurface, NULL, gScreenSurface, &gBoard);
	for (int i = 0; i < 8; i++)
	{	
		for (int j = 0; j < 8; j++)
		{
			gCase[i][j]->Render(gScreenSurface);
		}
	}
}

void Board::SetHighlightFalse()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			gCase[i][j]->SetHighlight(false);
		}
	}
}