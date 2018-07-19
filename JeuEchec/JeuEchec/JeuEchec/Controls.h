#pragma once
#include <memory>
#include <iostream>
#include <SDL.h>
#include <vector>
#include "Texts.h"
#include "Player.h"
#include <random>

class Vector2;
class Board;
class Case;
class Player;

class Controls
{
public:

	enum EControlState
	{
		ATTACK_PHASE,
		SPELL_PHASE,
		POWER1,
		POWER2,
		POWER3,
		POWER4,
		POWER5
	};

	Controls();
	~Controls();

	bool Update(const std::shared_ptr<Board>& board, SDL_Surface* screen);

	void SaveMove(std::shared_ptr<Case> _case, std::shared_ptr<Vector2> Pos);

	const std::shared_ptr<Case> &GetCurrentCase() { return _case; }

	void SetWhitePlaying(bool whiteplaying) { m_WhitePlaying = whiteplaying; }

	Player* m_WhitePlayer;
	Player* m_BlackPlayer;

private:
	void Controls::SwitchTurn();

	std::shared_ptr<Piece> _PlayingPiece = nullptr;
	std::shared_ptr<Case> _case = nullptr;
	std::shared_ptr<Case> m_MouseSensor = nullptr;

	EControlState m_ControlState;

	bool m_WhitePlaying = true;

	std::vector<std::shared_ptr<Vector2>> availableMoves = std::vector<std::shared_ptr<Vector2>>();
	std::vector<std::shared_ptr<Vector2>> availableSpellDest = std::vector<std::shared_ptr<Vector2>>();

	std::mt19937 rng;
};

