#include "Reine.h"
#include <SDL_image.h>
#include "Case.h"

Reine::Reine(bool IsBlack)
	: Piece(IsBlack)
{
	m_Texture = IsBlack ? IMG_Load("images/bQueen.png") : IMG_Load("images/wQueen.png");
	Piece::m_Type = PieceType::Reine;
}

Reine::~Reine()
{
}

std::vector<std::shared_ptr<Vector2>> Reine::Move(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases)
{
	std::vector<std::shared_ptr<Vector2>>vec = {};

	for (int w = i - 1; w >= 0; w--)
	{
		if (cases[w][j]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(w, j, true));
		}
		else
		{
			bool myColor = cases[i][j]->GetPiece()->GetColor();
			bool destination = cases[w][j]->GetPiece()->GetColor();
			if (myColor == destination)
			{
				break;
			}
			else if (myColor != destination)
			{
				vec.push_back(std::make_shared<Vector2>(w, j, true));
				if (cases[w][j]->GetPiece()->GetPieceType() == Piece::PieceType::Roi)
				{
					canEatKing = true;
				}
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
			bool myColor = cases[i][j]->GetPiece()->GetColor();
			bool destination = cases[w][j]->GetPiece()->GetColor();
			if (myColor == destination)
			{
				break;
			}
			else if (myColor != destination)
			{
				vec.push_back(std::make_shared<Vector2>(w, j, true));
				if (cases[w][j]->GetPiece()->GetPieceType() == Piece::PieceType::Roi)
				{
					canEatKing = true;
				}
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
			bool myColor = cases[i][j]->GetPiece()->GetColor();
			bool destination = cases[i][w]->GetPiece()->GetColor();
			if (myColor == destination)
			{
				break;
			}
			else if (myColor != destination)
			{
				vec.push_back(std::make_shared<Vector2>(i, w, true));
				if (cases[i][w]->GetPiece()->GetPieceType() == Piece::PieceType::Roi)
				{
					canEatKing = true;
				}
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
			bool myColor = cases[i][j]->GetPiece()->GetColor();
			bool destination = cases[i][w]->GetPiece()->GetColor();
			if (myColor == destination)
			{
				break;
			}
			else if (myColor != destination)
			{
				vec.push_back(std::make_shared<Vector2>(i, w, true));
				if (cases[i][w]->GetPiece()->GetPieceType() == Piece::PieceType::Roi)
				{
					canEatKing = true;
				}
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
				bool destination = cases[i + w][j + w]->GetPiece()->GetColor();
				if (isBlack == destination)
				{
					break;
				}
				else if (isBlack != destination)
				{
					vec.push_back(std::make_shared<Vector2>(i + w, j + w, true));
					if (cases[i + w][j + w]->GetPiece()->GetPieceType() == Piece::PieceType::Roi)
					{
						canEatKing = true;
					}
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
				bool destination = cases[i - w][j - w]->GetPiece()->GetColor();
				if (isBlack == destination)
				{
					break;
				}
				else if (isBlack != destination)
				{
					vec.push_back(std::make_shared<Vector2>(i - w, j - w, true));
					if (cases[i - w][j - w]->GetPiece()->GetPieceType() == Piece::PieceType::Roi)
					{
						canEatKing = true;
					}
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
				bool destination = cases[i - w][j + w]->GetPiece()->GetColor();
				if (isBlack == destination)
				{
					break;
				}
				else if (isBlack != destination)
				{
					vec.push_back(std::make_shared<Vector2>(i - w, j + w, true));
					if (cases[i - w][j + w]->GetPiece()->GetPieceType() == Piece::PieceType::Roi)
					{
						canEatKing = true;
					}
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
				bool destination = cases[i + w][j - w]->GetPiece()->GetColor();
				if (isBlack == destination)
				{
					break;
				}
				else if (isBlack != destination)
				{
					vec.push_back(std::make_shared<Vector2>(i + w, j - w, true));
					canEatKing = cases[i + w][j - w]->GetPiece()->GetPieceType() == Piece::PieceType::Roi;
					break;
				}
			}
		}
	}

	return vec;
}
