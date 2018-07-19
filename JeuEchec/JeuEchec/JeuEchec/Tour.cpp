#include "Tour.h"
#include <SDL_image.h>
#include "Case.h"

Tour::Tour(bool IsBlack)
	: Piece(IsBlack)
{
	//Texture de la piece
	m_Texture = IsBlack ? IMG_Load("images/bTower.png") : IMG_Load("images/wTower.png");
	//Type de la piece
	Piece::m_Type = PieceType::Tour;
	//Stats de la piece
	m_Stats.hp = 10;
	m_Stats.armor = 1;
	m_Stats.attack = 3;
	//Description du spell de la piece
	m_SpellText = "Sniper: Deals damage to any enemy on the map";
}

Tour::~Tour()
{
}

std::vector<std::shared_ptr<Vector2>> Tour::Move(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases)
{
	bool destination;
	std::vector<std::shared_ptr<Vector2>>vec = {};

	//Ma Tour peut-elle aller vers le haut
	for (int w = i - 1; w >= 0; w--)
	{
		if (cases[w][j]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(w, j, true));
		}
		else
		{
			destination = cases[w][j]->GetPiece()->GetColor();

			if (isBlack == destination)
			{
				break;
			}
			else if (isBlack != destination)
			{
				vec.push_back(std::make_shared<Vector2>(w, j, true));
				break;
			}
		}
	}

	//Ma Tour peut-elle se déplacer vers le bas
	for (int w = i + 1; w <= 7; w++)
	{
		if (cases[w][j]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(w, j, true));
		}
		else
		{
			destination = cases[w][j]->GetPiece()->GetColor();

			if (isBlack == destination)
			{
				break;
			}
			else if (isBlack != destination)
			{
				vec.push_back(std::make_shared<Vector2>(w, j, true));
				break;
			}
		}
	}

	//Ma Tour peut-elle se déplacer vers la gauche
	for (int w = j - 1; w >= 0; w--)
	{
		if (cases[i][w]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i, w, true));
		}
		else
		{
			destination = cases[i][w]->GetPiece()->GetColor();

			if (isBlack == destination)
			{
				break;
			}
			else if (isBlack != destination)
			{
				vec.push_back(std::make_shared<Vector2>(i, w, true));
				break;
			}
		}
	}
	//Ma Tour peut-elle se déplacer vers la droite
	for (int w = j + 1; w <= 7; w++)
	{
		if (cases[i][w]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i, w, true));
		}
		else
		{
			destination = cases[i][w]->GetPiece()->GetColor();

			if (isBlack == destination)
			{
				break;
			}
			else if (isBlack != destination)
			{
				vec.push_back(std::make_shared<Vector2>(i, w, true));
				break;
			}
		}
	}

	return vec;
}

std::vector<std::shared_ptr<Vector2>> Tour::SpellTarget(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases)
{
	std::vector<std::shared_ptr<Vector2>>vec = {};
	bool destination;

	//Trouve tout les pions de sa couleurs
	for (int w = 0; w < 8; w++)
	{
		for (int z = 0; z < 8; z++)
		{
			if (cases[w][z]->GetPiece() != nullptr)
			{
				destination = cases[w][z]->GetPiece()->GetColor();
				if (isBlack != destination)
				{
					if (cases[w][z]->GetPiece()->GetPieceType() == Pion)
					{
						vec.push_back(std::make_shared<Vector2>(w, z, true));
					}
				}
			}
		}
	}

	return vec;
}

void Tour::CastSpell(const std::shared_ptr<Board>& aBoard, const std::shared_ptr<Case>& aCase)
{
	//Fait du dommage a piece qui recoit le spell
	aCase->GetPiece()->SetDamage(5);
	if (aCase->GetPiece()->GetHP() <= 0)
	{
		aCase->GetPiece() = nullptr;
	}
	Piece::CastSpell(aBoard, aCase);
}
