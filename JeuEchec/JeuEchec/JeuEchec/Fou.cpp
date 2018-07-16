#include "Fou.h"
#include <SDL_image.h>
#include "Case.h"


Fou::Fou(bool IsBlack)
	: Piece(IsBlack)
{
	m_Texture = IsBlack ? IMG_Load("images/bFou.png") : IMG_Load("images/wFou.png");
	Piece::m_Type = PieceType::Fou;
	m_Stats.hp = 3;
	m_Stats.armor = 1;
	m_Stats.attack = 2;
	m_SpellText = "Allahu Akbar!: Kills an enemy unit with yourself";
}

Fou::~Fou()
{
}

std::vector<std::shared_ptr<Vector2>> Fou::Move(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases)
{
	bool destination;
	std::vector<std::shared_ptr<Vector2>>vec = {};

	for (int w = 1; w < 8; w++)
	{
		if ((i + w) < 8 && (j + w) <= 7)
		{
			if (cases[i + w][j + w]->GetPiece() == nullptr)
			{
				vec.push_back(std::make_shared<Vector2>(i + w, j + w, true));
			}
			else
			{
				destination = cases[i + w][j + w]->GetPiece()->GetColor();
				if (isBlack == destination)
				{
					break;
				}
				else if (isBlack != destination)
				{
					vec.push_back(std::make_shared<Vector2>(i + w, j + w, true));
					break;
				}
			}
		}
	}

	for (int w = 1; w < 8; w++)
	{
		if ((i - w) >= 0 && (j - w) >= 0)
		{
			if (cases[i - w][j - w]->GetPiece() == nullptr)
			{
				vec.push_back(std::make_shared<Vector2>(i - w, j - w, true));
			}
			else
			{
				destination = cases[i - w][j - w]->GetPiece()->GetColor();

				if (isBlack == destination)
				{
					break;
				}
				else if (isBlack != destination)
				{
					vec.push_back(std::make_shared<Vector2>(i - w, j - w, true));
					break;
				}
			}
		}
	}

	for (int w = 1; w < 8; w++)
	{
		if ((i - w) >= 0 && (j + w) <= 7)
		{
			if (cases[i - w][j + w]->GetPiece() == nullptr)
			{
				vec.push_back(std::make_shared<Vector2>(i - w, j + w, true));
			}
			else
			{
				destination = cases[i - w][j + w]->GetPiece()->GetColor();

				if (isBlack == destination)
				{
					break;
				}
				else if (isBlack != destination)
				{
					vec.push_back(std::make_shared<Vector2>(i - w, j + w, true));
					break;
				}
			}
		}
	}

	for (int w = 1; w < 8; w++)
	{
		if ((i + w) <= 7 && (j - w) >= 0)
		{
			if (cases[i + w][j - w]->GetPiece() == nullptr)
			{
				vec.push_back(std::make_shared<Vector2>(i + w, j - w, true));
			}
			else
			{
				destination = cases[i + w][j - w]->GetPiece()->GetColor();

				if (isBlack == destination)
				{
					break;
				}
				else if (isBlack != destination)
				{
					vec.push_back(std::make_shared<Vector2>(i + w, j - w, true));
					break;
				}
			}
		}
	}

	return vec;
}

std::vector<std::shared_ptr<Vector2>> Fou::SpellTarget(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases)
{
	bool destination;
	std::vector<std::shared_ptr<Vector2>>vec = {};

	for (int w = 1; w < 8; w++)
	{
		if ((i + w) < 8 && (j + w) <= 7)
		{
			if (cases[i + w][j + w]->GetPiece() != nullptr)
			{
				destination = cases[i + w][j + w]->GetPiece()->GetColor();
				if (isBlack != destination)
				{
					vec.push_back(std::make_shared<Vector2>(i + w, j + w, true));
					break;
				}
				else
				{
					break;
				}
			}
		}
	}

	for (int w = 1; w < 8; w++)
	{
		if ((i - w) >= 0 && (j - w) >= 0)
		{
			if (cases[i - w][j - w]->GetPiece() != nullptr)
			{
				destination = cases[i - w][j - w]->GetPiece()->GetColor();
				if (isBlack != destination)
				{
					vec.push_back(std::make_shared<Vector2>(i - w, j - w, true));
					break;
				}
				else
				{
					break;
				}
			}
		}
	}

	for (int w = 1; w < 8; w++)
	{
		if ((i - w) >= 0 && (j + w) <= 7)
		{
			if (cases[i - w][j + w]->GetPiece() != nullptr)
			{
				destination = cases[i - w][j + w]->GetPiece()->GetColor();
				if (isBlack != destination)
				{
					vec.push_back(std::make_shared<Vector2>(i - w, j + w, true));
					break;
				}
				else
				{
					break;
				}
			}
		}
	}

	for (int w = 1; w < 8; w++)
	{
		if ((i + w) <= 7 && (j - w) >= 0)
		{
			if (cases[i + w][j - w]->GetPiece() != nullptr)
			{
				destination = cases[i + w][j - w]->GetPiece()->GetColor();
				if (isBlack != destination)
				{
					vec.push_back(std::make_shared<Vector2>(i + w, j - w, true));
					break;
				}
			}
			else
			{
				break;
			}
		}
	}

	return vec;
}

void Fou::CastSpell(const std::shared_ptr<Board>& aBoard, const std::shared_ptr<Case>& aCase)
{
	Piece::CastSpell(aBoard, aCase);
}
