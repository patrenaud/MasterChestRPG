#pragma once
#include "Board.h"

class Player
{
public:
	Player();
	~Player();

	// This is to identify a player's mana
	int GetMana() { return m_Mana; } 

	// This is to change the player's mana
	void SetMana(int Mana) { m_Mana += Mana; }
	
	// This is to increase by 1 when turn has finished
	void IncreaseMana() { SetMana(1); }

private:
	int m_Mana;	
};

