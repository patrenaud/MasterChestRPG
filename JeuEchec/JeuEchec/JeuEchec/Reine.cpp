#include "Reine.h"
#include <SDL_image.h>
#include "Case.h"

Reine::Reine(bool IsBlack)
	: Piece(IsBlack)
{
	m_Texture = IsBlack ? IMG_Load("images/bQueen.png") : IMG_Load("images/wQueen.png");
	Piece::m_Type = PieceType::Reine;
	m_Stats.hp = 4;
	m_Stats.armor = 1;
	m_Stats.attack = 1;
}

Reine::~Reine()
{
}

std::vector<std::shared_ptr<Vector2>> Reine::Move(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases)
{
	std::vector<std::shared_ptr<Vector2>>vec = {};
	bool destination;

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

std::vector<std::shared_ptr<Vector2>> Reine::SpellTarget(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases)
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

void Reine::CastSpell(const std::shared_ptr<Board>& board)
{
	Piece::CastSpell(board);
}
