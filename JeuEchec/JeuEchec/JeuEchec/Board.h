#pragma once
#include <memory>
#include <vector>
#include <SDL.h>

class Piece;
class Case;

class Board
{
public:
	Board();
	~Board();
	void Render(SDL_Surface* gScreenSurface);

	std::shared_ptr<Case> GetCase(int i, int j) {return gCase[i][j]; } // returns a specefic case

	const std::vector<std::vector<std::shared_ptr<Case>>> &GetCases() { return gCase; }  // returns all cases

	void SetHighlightFalse(); // Removes the Highlight for all cases

private:

	// Main window
	SDL_Rect gBoard;

	//The surface contained by the window
	SDL_Surface* gPNGSurface = NULL;

	std::vector<std::vector<std::shared_ptr<Case>>> gCase;


};

