#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <SDL.h>
#include "Vector2.h"
#include "Board.h"

class Case;

class Piece
{
public:
	// These are the 3 stats used by pieces
	struct Stats
	{
		int hp;
		int armor;
		int attack;
	};

	// These are the diffrent type of pieces
	enum PieceType
	{
		none = -1,
		Pion = 0,
		Tour,
		Cheval,
		Reine,
		Fou,
		Roi		
	};

	Piece(bool isBlack);
	Piece() {}
	~Piece();

	void Render(SDL_Surface* gScreenSurface, SDL_Rect* Rect);

	SDL_Surface* m_Texture;

	const PieceType GetPieceType() { return m_Type; } // Gets the Type of the Piece (set by enum)

	const bool GetColor() { return isBlack; } // Tells if the color of the piece is black

	const int GetHP() { return m_Stats.hp; } // Returns current piece HP
	void HPGain(int hp); // Unit gains HP

	const int GetDamage() { return m_Stats.attack; } // Returns current piece Damage
	void AttackGain(int boost); // Unit gains damage

	const int GetArmor() { return m_Stats.armor; } // Returns current piece armor
	const void SetArmor(int a_Armor) { m_Stats.armor = a_Armor; } // Sets piece armor to a new int

	const bool GetCanSpell() { return canSpell; } // Sees if piece still has spell available
	const void SetCanSpell(bool a_CanSpell) { canSpell = a_CanSpell; } // Used to set the canSpell bool

	const std::string GetSpellText() { return m_SpellText; } // Usesd to show if spell is available in UI

	void SetDamage(int damage); // Calculates damage done by unit on attacks
	
	
	void Attack(std::shared_ptr<Piece> piece);

	
	virtual void CastSpell(const std::shared_ptr<Board>& board, const std::shared_ptr<Case>& aCase)
	{
		canSpell = false;
	}

	// Used to make a unit move in board
	virtual std::vector<std::shared_ptr<Vector2>> Move(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases)
	{
		return std::vector<std::shared_ptr<Vector2>>();
	}

	// Used to show targets available for spells in the board
	virtual std::vector<std::shared_ptr<Vector2>> SpellTarget(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases)
	{
		return std::vector<std::shared_ptr<Vector2>>();
	}

private:
	bool canSpell = true;

protected:
	bool isBlack;
	PieceType m_Type;
	Stats m_Stats;
	std::string m_SpellText;
};

