#pragma once
#include "Board.h"

class Player
{
public:
	Player();
	~Player();

	const int GetMana() { return m_Mana; }
		
private:
	int m_Mana;	
	void Spell1();
	void Spell2();
	void Spell3();
	void Spell4();
	void Spell5();

};

