#pragma once
#include "Piece.h"
class Pion :
	public Piece
{
public:
	Pion() {}
	Pion(bool IsBlack);
	~Pion();
	
	virtual std::vector<std::shared_ptr<Vector2>> Move(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases);
};

