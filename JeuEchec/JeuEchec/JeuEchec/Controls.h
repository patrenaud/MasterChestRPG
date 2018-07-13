#pragma once
#include <memory>
#include <iostream>
#include <SDL.h>
#include <vector>
#include "Texts.h"

class Vector2;
class Board;
class Case;

class Controls
{
public:

	enum EControlState
	{
		ATTACK_PHASE,
		SPELL_PHASE
	};	

	Controls();
	~Controls();

	bool m_WhitePlaying = true;

	bool Update(const std::shared_ptr<Board>& board, SDL_Surface* screen);

	void SaveMove(std::shared_ptr<Case> _case, std::shared_ptr<Vector2> Pos);

	const std::shared_ptr<Case> &GetCurrentCase() { return _case; }

private:
	std::shared_ptr<Case> _case = nullptr;
	std::shared_ptr<Case> m_MouseSensor = nullptr;
	EControlState m_ControlState;

protected:
	std::vector<std::shared_ptr<Vector2>> availableMoves = std::vector<std::shared_ptr<Vector2>>();
	std::vector<std::shared_ptr<Vector2>> availableSpellDest = std::vector<std::shared_ptr<Vector2>>();

};

