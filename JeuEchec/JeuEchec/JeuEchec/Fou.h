#pragma once
#include "Piece.h"
class Fou :
	public Piece
{
public:
	Fou() {}
	Fou(bool IsBlack);
	~Fou();

	virtual std::vector<std::shared_ptr<Vector2>> Move(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases);
};

