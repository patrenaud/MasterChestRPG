#pragma once
#include "Piece.h"
class Fou :
	public Piece
{
public:
	Fou() {}
	//Couleur de la piece
	Fou(bool IsBlack);
	~Fou();

	//Movement possible
	virtual std::vector<std::shared_ptr<Vector2>> Move(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases);
	//Spell Target possible
	virtual std::vector<std::shared_ptr<Vector2>> SpellTarget(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases);
	//Spell de la piece
	virtual void CastSpell(const std::shared_ptr<Board>& aBoard, const std::shared_ptr<Case>& aCase);
};

