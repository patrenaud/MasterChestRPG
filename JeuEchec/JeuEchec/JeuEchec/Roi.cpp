#include "Roi.h"
#include <SDL_image.h>
#include "Case.h"
#include "Controls.h"

Roi::Roi(bool IsBlack)
	: Piece(IsBlack)
{
	//Texture de la piece
	m_Texture = IsBlack ? IMG_Load("images/bKing.png") : IMG_Load("images/wKing.png");
	//Type de la piece
	Piece::m_Type = PieceType::Roi;
	//Stats de la piece
	m_Stats.hp = 13;
	m_Stats.armor = 1;
	m_Stats.attack = 1;
	//Description du spell de la piece
	m_SpellText = "Healer: Heals an ally to max health";
}

Roi::~Roi()
{
}

std::vector<std::shared_ptr<Vector2>> Roi::Move(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases)
{
	//Pour savoir la couleur de la case destination(si isBlack == destination les pièces sont de la même couleur)
	bool destination;
	//Vector (contenant de tout destination possible) 
	std::vector<std::shared_ptr<Vector2>>vec = {};
	//Ma couleur
	bool myColor = cases[i][j]->GetPiece()->GetColor();


	//Mon Roi peut-il aller vers le haut
	if (i >= 1)
	{
		if (cases[i - 1][j]->GetPiece() != nullptr)
		{
			destination = cases[i - 1][j]->GetPiece()->GetColor();
			if (myColor != destination)
			{
				vec.push_back(std::make_shared<Vector2>(i - 1, j, true));
			}
		}
		else if (cases[i - 1][j]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i - 1, j, true));
		}
	}

	//Mon Roi peut-il aller vers le haut et vers la gauche
	if (i >= 1 && j >= 1)
	{
		if (cases[i - 1][j - 1]->GetPiece() != nullptr)
		{
			destination = cases[i - 1][j - 1]->GetPiece()->GetColor();
			if (myColor != destination)
			{
				vec.push_back(std::make_shared<Vector2>(i - 1, j - 1, true));
			}
		}
		if (cases[i - 1][j - 1]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i - 1, j - 1, true));
		}
	}

	//Mon Roi peut-il aller vers le haut et vers la droite
	if (i >= 1 && j <= 6)
	{
		if (cases[i - 1][j + 1]->GetPiece() != nullptr)
		{
			destination = cases[i - 1][j + 1]->GetPiece()->GetColor();
			if (myColor != destination)
			{
				vec.push_back(std::make_shared<Vector2>(i - 1, j + 1, true));
			}
		}
		if (cases[i - 1][j + 1]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i - 1, j + 1, true));
		}
	}

	//Mon Roi peut-il aller vers le bas
	if (i <= 6)
	{
		if (cases[i + 1][j]->GetPiece() != nullptr)
		{
			destination = cases[i + 1][j]->GetPiece()->GetColor();
			if (myColor != destination)
			{
				vec.push_back(std::make_shared<Vector2>(i + 1, j, true));
			}
		}
		if (cases[i + 1][j]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i + 1, j, true));
		}
	}

	//Mon Roi peut-il aller vers le bas et vers la gauche
	if (i <= 6 && j >= 1)
	{
		if (cases[i + 1][j - 1]->GetPiece() != nullptr)
		{
			destination = cases[i + 1][j - 1]->GetPiece()->GetColor();
			if (myColor != destination)
			{
				vec.push_back(std::make_shared<Vector2>(i + 1, j - 1, true));
			}
		}
		if (cases[i + 1][j - 1]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i + 1, j - 1, true));
		}
	}

	//Mon Roi peut-il aller vers le bas et vers la droite
	if (i <= 6 && j <= 6)
	{
		if (cases[i + 1][j + 1]->GetPiece() != nullptr)
		{
			if (myColor != destination)
			{
				destination = cases[i + 1][j + 1]->GetPiece()->GetColor();
				vec.push_back(std::make_shared<Vector2>(i + 1, j + 1, true));
			}
		}
		if (cases[i + 1][j + 1]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i + 1, j + 1, true));
		}
	}

	//Mon Roi peut-il aller vers la gauche
	if (j >= 1)
	{
		if (cases[i][j - 1]->GetPiece() != nullptr)
		{
			destination = cases[i][j - 1]->GetPiece()->GetColor();
			if (myColor != destination)
			{
				vec.push_back(std::make_shared<Vector2>(i, j - 1, true));
			}
		}
		if (cases[i][j - 1]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i, j - 1, true));
		}
	}

	//Mon Roi peut-il aller vers la droite
	if (j <= 6)
	{
		if (cases[i][j + 1]->GetPiece() != nullptr)
		{
			destination = cases[i][j + 1]->GetPiece()->GetColor();
			if (myColor != destination)
			{
				vec.push_back(std::make_shared<Vector2>(i, j + 1, true));
			}
		}
		if (cases[i][j + 1]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i, j + 1, true));
		}
	}

	return vec;
}

std::vector<std::shared_ptr<Vector2>> Roi::SpellTarget(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases)
{
	std::vector<std::shared_ptr<Vector2>>vec = {};
	bool destination;

	//Trouve les cases contenant des pieces de la couleurs de la reine
	for (int w = 0; w < 8; w++)
	{
		for (int z = 0; z < 8; z++)
		{
			if (cases[w][z]->GetPiece() != nullptr)
			{
				destination = cases[w][z]->GetPiece()->GetColor();
				if (isBlack == destination)
				{
					vec.push_back(std::make_shared<Vector2>(w, z, true));
				}
			}
		}
	}
	return vec;
}

void Roi::CastSpell(const std::shared_ptr<Board>& aBoard, const std::shared_ptr<Case>& aCase)
{
	//redonne de HP a la piece qui recoit le spell
	aCase->GetPiece()->HPGain(10);
	Piece::CastSpell(aBoard, aCase);
}
