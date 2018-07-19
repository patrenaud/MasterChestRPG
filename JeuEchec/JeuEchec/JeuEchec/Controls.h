#pragma once
#include <memory>
#include <iostream>
#include <SDL.h>
#include <vector>
#include "Texts.h"
#include "Player.h"

class Vector2;
class Board;
class Case;
class Player;

class Controls
{
public:
	// This enum is used by the events to control what kind of move is being played
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

	void SaveMove(std::shared_ptr<Case> _case, std::shared_ptr<Vector2> Pos); // Used to fill Seve.txt

	const std::shared_ptr<Case> &GetCurrentCase() { return _case; } 

	void SetWhitePlaying(bool whiteplaying) { m_WhitePlaying = whiteplaying; } // Sets first player as white

	// This is used to create 2 players with 2 distinct mana pool (see Player class)
	Player* m_WhitePlayer;
	Player* m_BlackPlayer;

private:
	// This is to Increase mana to players and to switch player's turn
	void Controls::SwitchTurn(const std::shared_ptr<Board>& board);
	// These are used to select of detect the case or the piece under mouse
	std::shared_ptr<Piece> _PlayingPiece = nullptr;
	std::shared_ptr<Case> _case = nullptr;
	std::shared_ptr<Case> m_MouseSensor = nullptr;

	// Creates the enum
	EControlState m_ControlState;

	// Sets white player as playing
	bool m_WhitePlaying = true;

	// Used as targets for spell casting by units
	std::vector<std::shared_ptr<Vector2>> availableMoves = std::vector<std::shared_ptr<Vector2>>();
	std::vector<std::shared_ptr<Vector2>> availableSpellDest = std::vector<std::shared_ptr<Vector2>>();
};

