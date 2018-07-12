#pragma once
#include <memory>
#include <iostream>
#include <SDL.h>
#include <vector>

class Vector2;
class Board;
class Case;

class Controls
{
public:
	Controls();
	~Controls();

	bool m_WhitePlaying = true;

	bool Update(const std::shared_ptr<Board>& board, SDL_Surface* screen);

	void SaveMove(std::shared_ptr<Case> _case, std::shared_ptr<Vector2> Pos);

	const std::shared_ptr<Case> &GetCurrentCase() { return _case; }

private:
	std::shared_ptr<Case> _case = nullptr;

protected:
	bool kingNeedToMove = false;
	std::vector<std::shared_ptr<Vector2>> availableMoves = std::vector<std::shared_ptr<Vector2>>();
};

