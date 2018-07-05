#pragma once
#include "Piece.h"
class Cheval :
	public Piece
{
public:
	Cheval() {};
	Cheval(bool IsBlack);
	~Cheval();

	virtual std::vector<std::shared_ptr<Vector2>> Move(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases);
};

