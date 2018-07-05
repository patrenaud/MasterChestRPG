#include "Board.h"
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <memory>
#include "Case.h"
#include "Pion.h"
#include "Tour.h"
#include "Cheval.h"
#include "Fou.h"
#include "Reine.h"
#include "Roi.h"

Board::Board()
{
	//Load PNG surface
	gPNGSurface = IMG_Load("images/ChestBoard.png");
	
	// Création du board
	gBoard = { 0, 0, 1000, 800 };

	// Cette boucle est pour créer les différentes cases
	for (int i = 0; i < 8; i++)
	{
		gCase.push_back(std::vector<std::shared_ptr<Case>>());
		
		for (int j = 0; j < 8; j++)
		{
			if (i == 0)
			{
				if (j == 0 || j == 7)
				{
					gCase[i].push_back(std::make_shared<Case>(gBoard.x + 100 * j, gBoard.y + 100 * i, std::make_shared<Tour>(false)));
				}														 
				else if (j == 1 || j == 6)								 
				{														 
					gCase[i].push_back(std::make_shared<Case>(gBoard.x + 100 * j, gBoard.y + 100 * i, std::make_shared<Cheval>(false)));
				}														 
				else if (j == 2 || j == 5)								 
				{														 
					gCase[i].push_back(std::make_shared<Case>(gBoard.x + 100 * j, gBoard.y + 100 * i, std::make_shared<Fou>(false)));
				}														 
				else if (j == 3)										 
				{														 
					gCase[i].push_back(std::make_shared<Case>(gBoard.x + 100 * j, gBoard.y + 100 * i, std::make_shared<Reine>(false)));
				}														 
				else if (j == 4)										 
				{														 
					gCase[i].push_back(std::make_shared<Case>(gBoard.x + 100 * j, gBoard.y + 100 * i, std::make_shared<Roi>(false)));
				}
			}
			else if (i == 1)
			{
				gCase[i].push_back(std::make_shared<Case>(gBoard.x + 100 * j, gBoard.y + 100 * i, std::make_shared<Pion>(false)));
			}
			else if (i== 7)
			{
				if (j == 0 || j == 7)
				{
					gCase[i].push_back(std::make_shared<Case>(gBoard.x + 100 * j, gBoard.y + 100 * i, std::make_shared<Tour>(true)));
				}
				else if (j == 1 || j == 6)
				{
					gCase[i].push_back(std::make_shared<Case>(gBoard.x + 100 * j, gBoard.y + 100 * i, std::make_shared<Cheval>(true)));
				}
				else if (j == 2 || j == 5)
				{
					gCase[i].push_back(std::make_shared<Case>(gBoard.x + 100 * j, gBoard.y + 100 * i, std::make_shared<Fou>(true)));
				}
				else if (j == 3)
				{
					gCase[i].push_back(std::make_shared<Case>(gBoard.x + 100 * j, gBoard.y + 100 * i, std::make_shared<Reine>(true)));
				}
				else if (j == 4)
				{
					gCase[i].push_back(std::make_shared<Case>(gBoard.x + 100 * j, gBoard.y + 100 * i, std::make_shared<Roi>(true)));
				}
			}
			else if (i == 6)
			{
				gCase[i].push_back(std::make_shared<Case>(gBoard.x + 100 * j, gBoard.y + 100 * i, std::make_shared<Pion>(true)));
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