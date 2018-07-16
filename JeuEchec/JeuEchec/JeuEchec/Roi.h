#pragma once
#include "Piece.h"
class Roi :
	public Piece
{
public:
	Roi() {}
	Roi(bool IsBlack);
	~Roi();

	virtual std::vector<std::shared_ptr<Vector2>> Move(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases);
	virtual std::vector<std::shared_ptr<Vector2>> SpellTarget(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases);
	virtual void CastSpell(const std::shared_ptr<Board>& board, const std::shared_ptr<Case>& aCase);
};

