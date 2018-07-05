#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <SDL.h>
#include "Vector2.h"

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
	void SetCanEatKing(const bool canEat) { canEatKing = canEat; }

	SDL_Surface* m_Texture;
	const PieceType GetPieceType() { return m_Type; }

	const bool GetColor() { return isBlack; }
	const bool GetCanEatKing() { return canEatKing; }

	virtual void CastSpell()
	{
		canSpell = false;
	}

	virtual std::vector<std::shared_ptr<Vector2>> Move(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases)
	{
		return std::vector<std::shared_ptr<Vector2>>();
	}

private:
	bool canSpell;

protected:

	bool canEatKing;
	bool isBlack;
	PieceType m_Type;
	Stats m_Stats;
};

