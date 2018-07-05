#pragma once
#include "Piece.h"
class Tour :
	public Piece
{
public:
	Tour(bool IsBlack);
	Tour() {}
	~Tour();

	virtual std::vector<std::shared_ptr<Vector2>> Move(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases);
};

