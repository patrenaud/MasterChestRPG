#include "Roi.h"
#include <SDL_image.h>
#include "Case.h"
#include "Controls.h"

Roi::Roi(bool IsBlack)
	: Piece(IsBlack)
{
	m_Texture = IsBlack ? IMG_Load("images/bKing.png") : IMG_Load("images/wKing.png");
	Piece::m_Type = PieceType::Roi;
	m_Stats.hp = 13;
	m_Stats.armor = 1;
	m_Stats.attack = 1;
}

Roi::~Roi()
{
}

std::vector<std::shared_ptr<Vector2>> Roi::Move(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases)
{
	std::vector<std::shared_ptr<Vector2>>vec = {};
	bool myColor = cases[i][j]->GetPiece()->GetColor();
	bool destination;

	if (i >= 1)
	{
		if (cases[i - 1][j]->GetPiece() != nullptr)
		{
			destination = cases[i - 1][j]->GetPiece()->GetColor();
		}
		if (cases[i - 1][j]->GetPiece() == nullptr || myColor != destination)
		{
			vec.push_back(std::make_shared<Vector2>(i - 1, j, true));
		}
	}

	if (i >= 1 && j >= 1)
	{
		if (cases[i - 1][j - 1]->GetPiece() != nullptr)
		{
			destination = cases[i - 1][j - 1]->GetPiece()->GetColor();
		}
		if (cases[i - 1][j - 1]->GetPiece() == nullptr || myColor != destination)
		{
			vec.push_back(std::make_shared<Vector2>(i - 1, j - 1, true));
		}
	}

	if (i >= 1 && j <= 6)
	{
		if (cases[i - 1][j + 1]->GetPiece()->GetColor())
		{
			destination = cases[i - 1][j + 1]->GetPiece()->GetColor();
		}
		if (cases[i - 1][j + 1]->GetPiece() == nullptr || myColor != destination)
		{
			vec.push_back(std::make_shared<Vector2>(i - 1, j + 1, true));
		}
	}

	if (i <= 6)
	{
		if (cases[i + 1][j]->GetPiece() != nullptr)
		{
			destination = cases[i + 1][j]->GetPiece()->GetColor();
		}
		if (cases[i + 1][j]->GetPiece() == nullptr || myColor != destination)
		{
			vec.push_back(std::make_shared<Vector2>(i + 1, j, true));
		}
	}

	if (i <= 6 && j >= 1)
	{
		if (cases[i + 1][j - 1]->GetPiece() != nullptr)
		{
			destination = cases[i + 1][j - 1]->GetPiece()->GetColor();
		}
		if (cases[i + 1][j - 1]->GetPiece() == nullptr || myColor != destination)
		{
			vec.push_back(std::make_shared<Vector2>(i + 1, j - 1, true));
		}
	}

	if (i <= 6 && j <= 6)
	{
		if (cases[i + 1][j + 1]->GetPiece() != nullptr)
		{
			destination = cases[i + 1][j + 1]->GetPiece()->GetColor();
		}
		if (cases[i + 1][j + 1]->GetPiece() == nullptr || myColor != destination)
		{
			vec.push_back(std::make_shared<Vector2>(i + 1, j + 1, true));
		}
	}

	if (j >= 1)
	{
		if (cases[i][j - 1]->GetPiece() != nullptr)
		{
			destination = cases[i][j - 1]->GetPiece()->GetColor();
		}
		if (cases[i][j - 1]->GetPiece() == nullptr || myColor != destination)
		{
			vec.push_back(std::make_shared<Vector2>(i, j - 1, true));
		}
	}

	if (j <= 6)
	{
		if (cases[i][j + 1]->GetPiece() != nullptr)
		{
			destination = cases[i][j + 1]->GetPiece()->GetColor();
		}
		if (cases[i][j + 1]->GetPiece() == nullptr || myColor != destination)
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
	Piece::CastSpell(aBoard, aCase);
}
