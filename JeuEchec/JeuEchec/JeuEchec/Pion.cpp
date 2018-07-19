#include "Pion.h"
#include <SDL_image.h>
#include <utility>
#include "Case.h"

Pion::Pion(bool IsBlack)
	: Piece(IsBlack)
{
	m_Texture = IsBlack ? IMG_Load("images/bPion.png") : IMG_Load("images/wPion.png");
	m_Type = PieceType::Pion;
	m_Stats.hp = 1;
	m_Stats.armor = 1;
	m_Stats.attack = 1;
	m_SpellText = "Switcharoo: Swaps position with an adjacent unit (friendly or enemy)";
}


Pion::~Pion()
{
}

std::vector<std::shared_ptr<Vector2>> Pion::Move(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases)
{
	std::vector<std::shared_ptr<Vector2>>vec = {};
	bool destination;

	if (i >= 1)
	{
		if (cases[i - 1][j]->GetPiece() != nullptr)
		{
			destination = cases[i - 1][j]->GetPiece()->GetColor();
		}
		if (cases[i - 1][j]->GetPiece() == nullptr || isBlack != destination)
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
		if (cases[i - 1][j - 1]->GetPiece() == nullptr || isBlack != destination)
		{
			vec.push_back(std::make_shared<Vector2>(i - 1, j - 1, true));
		}
	}

	if (i >= 1 && j <= 6)
	{
		if (cases[i - 1][j + 1]->GetPiece() != nullptr)
		{
			destination = cases[i - 1][j + 1]->GetPiece()->GetColor();
		}
		if (cases[i - 1][j + 1]->GetPiece() == nullptr || isBlack != destination)
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
		if (cases[i + 1][j]->GetPiece() == nullptr || isBlack != destination)
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
		if (cases[i + 1][j - 1]->GetPiece() == nullptr || isBlack != destination)
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
		if (cases[i + 1][j + 1]->GetPiece() == nullptr || isBlack != destination)
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
		if (cases[i][j - 1]->GetPiece() == nullptr || isBlack != destination)
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
		if (cases[i][j + 1]->GetPiece() == nullptr || isBlack != destination)
		{
			vec.push_back(std::make_shared<Vector2>(i, j + 1, true));
		}
	}

	return vec;
}

std::vector<std::shared_ptr<Vector2>> Pion::SpellTarget(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases)
{
	std::vector<std::shared_ptr<Vector2>>vec = {};

	if (i >= 1)
	{
		if (cases[i - 1][j]->GetPiece() != nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i - 1, j, true));
		}
	}

	if (i >= 1 && j >= 1)
	{
		if (cases[i - 1][j - 1]->GetPiece() != nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i - 1, j - 1, true));
		}
	}

	if (i >= 1 && j <= 6)
	{
		if (cases[i - 1][j + 1]->GetPiece() != nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i - 1, j + 1, true));
		}
	}

	if (i <= 6)
	{
		if (cases[i + 1][j]->GetPiece() != nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i + 1, j, true));
		}
	}

	if (i <= 6 && j >= 1)
	{
		if (cases[i + 1][j - 1]->GetPiece() != nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i + 1, j - 1, true));
		}
	}

	if (i <= 6 && j <= 6)
	{
		if (cases[i + 1][j + 1]->GetPiece() != nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i + 1, j + 1, true));
		}
	}

	if (j >= 1)
	{
		if (cases[i][j - 1]->GetPiece() != nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i, j - 1, true));
		}
	}

	if (j <= 6)
	{
		if (cases[i][j + 1]->GetPiece() != nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i, j + 1, true));
		}
	}

	return vec;
}

void Pion::CastSpell(const std::shared_ptr<Board>& aBoard, const std::shared_ptr<Case>& aCase)
{
	Piece::CastSpell(aBoard, aCase);
}
