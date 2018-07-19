#include "Tour.h"
#include <SDL_image.h>
#include "Case.h"

Tour::Tour(bool IsBlack)
	: Piece(IsBlack)
{
	m_Texture = IsBlack ? IMG_Load("images/bTower.png") : IMG_Load("images/wTower.png");
	Piece::m_Type = PieceType::Tour;
	m_Stats.hp = 42;
	m_Stats.armor = 1;
	m_Stats.attack = 1;
	m_SpellText = "Sniper: Deals damage to any enemy on the map";
}

Tour::~Tour()
{
}

std::vector<std::shared_ptr<Vector2>> Tour::Move(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases)
{
	bool destination;
	std::vector<std::shared_ptr<Vector2>>vec = {};

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
	aCase->GetPiece()->SetDamage(5);
	if (aCase->GetPiece()->GetHP() <= 0)
	{
		aCase->GetPiece() = nullptr;
	}
	Piece::CastSpell(aBoard, aCase);
}
