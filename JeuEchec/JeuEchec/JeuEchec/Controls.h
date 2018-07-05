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

	const bool GetKingToMove() { return kingNeedToMove; }
	bool m_WhitePlaying = true;

	bool Update(const std::shared_ptr<Board>& board, SDL_Surface* screen);
	void SaveMove(std::shared_ptr<Case> _case, std::shared_ptr<Vector2> Pos);

	const std::shared_ptr<Case> &GetCurrentCase() { return _case; }
	const std::vector<std::vector<std::shared_ptr<Vector2>>> GetEnemiesMoves() { return enemiesMoves; }

private:

	std::shared_ptr<Case> _case = nullptr;

	std::vector<std::shared_ptr<Vector2>> CheckDanger = std::vector<std::shared_ptr<Vector2>>();

	std::vector<std::vector<std::shared_ptr<Vector2>>> enemiesMoves;

protected:
	bool kingNeedToMove = false;
	std::vector<std::shared_ptr<Vector2>> availableMoves = std::vector<std::shared_ptr<Vector2>>();
};

