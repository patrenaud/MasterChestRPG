#pragma once
#include "Piece.h"
class Reine :
	public Piece
{
public:
	Reine() {}
	Reine(bool IsBlack);
	~Reine();

	virtual std::vector<std::shared_ptr<Vector2>> Move(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases);
};

