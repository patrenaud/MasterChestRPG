#pragma once
#include "Board.h"

class Player
{
public:
	Player();
	~Player();

	int GetMana() { return m_Mana; }
	void SetMana(int Mana) { m_Mana += Mana; }
	void IncreaseMana() { SetMana(1); }

private:
	int m_Mana;	
	void Spell1();
	void Spell2();
	void Spell3();
	void Spell4();
	void Spell5();

};
