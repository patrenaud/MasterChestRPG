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
	struct Stats
	{
		int hp;
		int armor;
		int attack;
	};

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
	const PieceType GetPieceType() { return m_Type; }

	const bool GetColor() { return isBlack; }

	const int GetHP() { return m_Stats.hp; }
	const int GetDamage() { return m_Stats.attack; }
	const int GetArmor() { return m_Stats.armor; }
	const bool GetCanSpell() { return canSpell; }
	const std::string GetSpellText() { return m_SpellText; }

	void SetHP(int damage);
	void Attack(std::shared_ptr<Piece> piece);

	virtual void CastSpell(const std::shared_ptr<Board>& board, const std::shared_ptr<Case>& aCase)
	{
		canSpell = false;
	}

	virtual std::vector<std::shared_ptr<Vector2>> Move(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases)
	{
		return std::vector<std::shared_ptr<Vector2>>();
	}

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

