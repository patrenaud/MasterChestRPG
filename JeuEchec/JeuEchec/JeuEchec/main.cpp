/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include "Board.h"
#include "Case.h"
#include "Piece.h"
#include "Controls.h"
#include <fstream>
#include "Vector2.h"
#include <SDL_ttf.h>
#include "Texts.h"

//Screen dimension constants
const int SCREEN_WIDTH = 1400;
const int SCREEN_HEIGHT = 800;

//Starts up SDL and creates window
bool init();

std::shared_ptr<Controls> controls = std::make_shared<Controls>();

//Frees media and shuts down SDL
void close();

// Déclaration du board
std::shared_ptr<Board> board = std::make_shared<Board>();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

bool init()
{
	// This is for text Lib
	Texts::Init(gWindow);

	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Initialize PNG loading
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
				success = false;
			}
			else
			{
				//Get window surface
				gScreenSurface = SDL_GetWindowSurface(gWindow);
			}
		}
	}
	return success;
}

void close()
{
	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Main loop flag
		bool quit = false;

		//Event handler
		SDL_Event e;

		// on ouvre le fichier de Save
		std::ifstream fichier("Save.txt", std::ios::in);


		//While application is running
		while (!quit)
		{
			//Update the surface
			SDL_UpdateWindowSurface(gWindow);

			// Ceci est pour render le board
			board->Render(gScreenSurface);

			// This is to draw the text on Runtime
			Texts::DrawTexts(gScreenSurface);

			// This is to reset game
			if (controls->Update(board, gScreenSurface))
			{
				board.reset();
				board = std::make_shared<Board>();
				controls.reset();
				controls = std::make_shared<Controls>();
				remove("Save.txt");
			}

			if (fichier.is_open())  // si l'ouverture a réussi
			{
				std::vector<std::vector<int>> StartMoves = std::vector<std::vector<int>>();
				std::vector<std::vector<int>> EndMoves = std::vector<std::vector<int>>();

				while (!fichier.eof())
				{
					char buffer[256];
					fichier.getline(buffer, 256);
					if (buffer[0] != '\0')
					{
						// The parameters were from teacher help (-48 !?)
						StartMoves.push_back(std::vector<int>({ (int)buffer[0] - 48, (int)buffer[1] - 48 }));
						EndMoves.push_back(std::vector<int>({ (int)buffer[2] - 48, (int)buffer[3] - 48 }));
					}
				}
				fichier.close();

				for (int i = 0; i < StartMoves.size(); i++)
				{
					// 
					board->GetCase(EndMoves[i][0], EndMoves[i][1])->GetPiece() = board->GetCase(StartMoves[i][0], StartMoves[i][1])->GetPiece();
					board->GetCase(StartMoves[i][0], StartMoves[i][1])->GetPiece() = nullptr;

					//Update the surface
					SDL_UpdateWindowSurface(gWindow);

					// Ceci est pour render le board
					board->Render(gScreenSurface);

					SDL_Delay(1000); // 1000 miliseconds between each moves in save game restart
				}
				controls->SetWhitePlaying(!(StartMoves.size() % 2)); // This will make the next move after load game be the right player
			}
		}
	}
	system("pause");
	//Free resources and close SDL
	close();

	return 0;
}