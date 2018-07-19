#include "Cheval.h"
#include <SDL_image.h>
#include "Case.h"
#include "Board.h"
#include "Controls.h"

Cheval::Cheval(bool IsBlack)
	: Piece(IsBlack)
{
	m_Texture = IsBlack ? IMG_Load("images/bCavalier.png") : IMG_Load("images/wCavalier.png");
	Piece::m_Type = PieceType::Cheval;
	m_Stats.hp = 2;
	m_Stats.armor = 2;
	m_Stats.attack = 2;
	m_SpellText = "Stampede: Damages all enemy around the landing area (friendly or enemy)";
}


Cheval::~Cheval()
{
}

std::vector<std::shared_ptr<Vector2>> Cheval::Move(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases)
{
	bool destination;
	std::vector<std::shared_ptr<Vector2>>vec = {};

	if (i >= 2 && j <= 6)
	{
		if (cases[i - 2][j + 1]->GetPiece() != nullptr)
		{
			destination = cases[i - 2][j + 1]->GetPiece()->GetColor();
		}
		if(cases[i - 2][j + 1]->GetPiece() == nullptr || isBlack != destination)
		{
			vec.push_back(std::make_shared<Vector2>(i - 2, j + 1, true));
		}
	}

	if (i >= 2 && j >= 1)
	{
		if (cases[i - 2][j - 1]->GetPiece() != nullptr)
		{
			destination = cases[i - 2][j - 1]->GetPiece()->GetColor();
		}
		if (cases[i - 2][j - 1]->GetPiece() == nullptr || isBlack != destination)
		{
			vec.push_back(std::make_shared<Vector2>(i - 2, j - 1, true));
		}
	}

	if (i >= 1 && j >= 2)
	{
		if (cases[i - 1][j - 2]->GetPiece() != nullptr)
		{
			destination = cases[i - 1][j - 2]->GetPiece()->GetColor();
		}
		if (cases[i - 1][j - 2]->GetPiece() == nullptr || isBlack != destination)
		{
			vec.push_back(std::make_shared<Vector2>(i - 1, j - 2, true));
		}
	}

	if (i <= 6 && j >= 2)
	{
		if (cases[i + 1][j - 2]->GetPiece() != nullptr)
		{
			destination = cases[i + 1][j - 2]->GetPiece()->GetColor();
		}
		if (cases[i + 1][j - 2]->GetPiece() == nullptr || isBlack != destination)
		{
			vec.push_back(std::make_shared<Vector2>(i + 1, j - 2, true));
		}
	}

	if (i <= 5 && j >= 1)
	{
		if (cases[i + 2][j - 1]->GetPiece() != nullptr)
		{
			destination = cases[i + 2][j - 1]->GetPiece()->GetColor();
		}
		if (cases[i + 2][j - 1]->GetPiece() == nullptr || isBlack != destination)
		{
			vec.push_back(std::make_shared<Vector2>(i + 2, j - 1, true));
		}
	}

	if (i <= 5 && j <= 6)
	{
		if (cases[i + 2][j + 1]->GetPiece() != nullptr)
		{
			destination = cases[i + 2][j + 1]->GetPiece()->GetColor();
		}
		if (cases[i + 2][j + 1]->GetPiece() == nullptr || isBlack != destination)
		{
			vec.push_back(std::make_shared<Vector2>(i + 2, j + 1, true));
		}
	}

	if (i <= 6 && j <= 5)
	{
		if (cases[i + 1][j + 2]->GetPiece() != nullptr)
		{
			destination = cases[i + 1][j + 2]->GetPiece()->GetColor();
		}
		if (cases[i + 1][j + 2]->GetPiece() == nullptr || isBlack != destination)
		{
			vec.push_back(std::make_shared<Vector2>(i + 1, j + 2, true));
		}
	}

	if (i >= 1 && j <= 5)
	{
		if (cases[i - 1][j + 2]->GetPiece() != nullptr)
		{
			destination = cases[i - 1][j + 2]->GetPiece()->GetColor();
		}
		if (cases[i - 1][j + 2]->GetPiece() == nullptr || isBlack != destination)
		{
			vec.push_back(std::make_shared<Vector2>(i - 1, j + 2, true));
		}
	}

	return vec;	
}

std::vector<std::shared_ptr<Vector2>> Cheval::SpellTarget(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases)
{
	std::vector<std::shared_ptr<Vector2>>vec = {};

	if (i >= 2 && j <= 6)
	{
		if (cases[i - 2][j + 1]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i - 2, j + 1, true));
		}
	}

	if (i >= 2 && j >= 1)
	{
		if (cases[i - 2][j - 1]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i - 2, j - 1, true));
		}
	}

	if (i >= 1 && j >= 2)
	{
		if (cases[i - 1][j - 2]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i - 1, j - 2, true));
		}
	}

	if (i <= 6 && j >= 2)
	{
		if (cases[i + 1][j - 2]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i + 1, j - 2, true));
		}
	}

	if (i <= 5 && j >= 1)
	{
		if (cases[i + 2][j - 1]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i + 2, j - 1, true));
		}
	}

	if (i <= 5 && j <= 6)
	{
		if (cases[i + 2][j + 1]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i + 2, j + 1, true));
		}
	}

	if (i <= 6 && j <= 5)
	{
		if (cases[i + 1][j + 2]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i + 1, j + 2, true));
		}
	}

	if (i >= 1 && j <= 5)
	{
		if (cases[i - 1][j + 2]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i - 1, j + 2, true));
		}
	}

	return vec;
}

void Cheval::CastSpell(const std::shared_ptr<Board>& aBoard, const std::shared_ptr<Case>& aCase)
{
	int y = aCase->GetX();
	int x = aCase->GetY();

	if (x >= 1 && aBoard->GetCase(x - 1, y)->GetPiece() != nullptr)
	{
		std::shared_ptr<Piece>& piece = aBoard->GetCase(x - 1, y)->GetPiece();
		piece->SetDamage(5);
		
		if (piece->GetHP() <= 0)
		{
			piece = nullptr;
		}
	}

	if (x >= 1 && y >= 1 && aBoard->GetCase(x - 1, y - 1)->GetPiece() != nullptr)
	{
		std::shared_ptr<Piece>& piece = aBoard->GetCase(x - 1, y - 1)->GetPiece();
		piece->SetDamage(5);

		if (piece->GetHP() <= 0)
		{
			piece = nullptr;
		}
	}

	if (y >= 1 && aBoard->GetCase(x, y - 1)->GetPiece() != nullptr)
	{
		std::shared_ptr<Piece>& piece = aBoard->GetCase(x, y - 1)->GetPiece();
		piece->SetDamage(5);

		if (piece->GetHP() <= 0)
		{
			piece = nullptr;
		}
	}

	if (x <= 6 && y >= 1 && aBoard->GetCase(x + 1, y - 1)->GetPiece() != nullptr)
	{
		std::shared_ptr<Piece>& piece = aBoard->GetCase(x + 1, y - 1)->GetPiece();
		piece->SetDamage(5);

		if (piece->GetHP() <= 0)
		{
			piece = nullptr;
		}
	}

	if (x <= 6 && aBoard->GetCase(x + 1, y)->GetPiece() != nullptr)
	{
		std::shared_ptr<Piece>& piece = aBoard->GetCase(x + 1, y)->GetPiece();
		piece->SetDamage(5);
		
		if (piece->GetHP() <= 0)
		{
			piece = nullptr;
		}
	}

	if (x <= 6 && y <= 6 && aBoard->GetCase(x + 1, y + 1)->GetPiece() != nullptr)
	{
		std::shared_ptr<Piece>& piece = aBoard->GetCase(x + 1, y + 1)->GetPiece();
		piece->SetDamage(5);
		
		if (piece->GetHP() <= 0)
		{
			piece = nullptr;
		}
	}

	if (y >= 1 && aBoard->GetCase(x, y - 1)->GetPiece() != nullptr)
	{
		std::shared_ptr<Piece>& piece = aBoard->GetCase(x, y - 1)->GetPiece();
		piece->SetDamage(5);

		if (piece->GetHP() <= 0)
		{
			piece = nullptr;
		}
	}

	if (x >= 1 && y <= 6 && aBoard->GetCase(x - 1, y + 1)->GetPiece() != nullptr)
	{
		std::shared_ptr<Piece>& piece = aBoard->GetCase(x - 1, y + 1)->GetPiece();
		piece->SetDamage(5);

		if (piece->GetHP() <= 0)
		{
			piece = nullptr;
		}
	}
	Piece::CastSpell(aBoard, aCase);
}