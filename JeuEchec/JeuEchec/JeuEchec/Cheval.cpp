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
}


Cheval::~Cheval()
{
}

std::vector<std::shared_ptr<Vector2>> Cheval::Move(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases)
{
	bool canEatKing;
	std::vector<std::shared_ptr<Vector2>>vec = {};

	if (i >= 2 && j <= 6)
	{
		if(cases[i - 2][j + 1]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i - 2, j + 1, true));
		}
		else
		{
			bool destination = cases[i-2][j+1]->GetPiece()->GetColor();
			if (isBlack != destination)
			{
				vec.push_back(std::make_shared<Vector2>(i- 2, j + 1, true));
				if (cases[i - 2][j + 1]->GetPiece()->GetPieceType() == Piece::PieceType::Roi)
				{
					canEatKing = true;
				}
			}
		}
	}

	if (i >= 2 && j >= 1)
	{
		if (cases[i - 2][j - 1]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i - 2, j - 1, true));
		}
		else
		{
			bool destination = cases[i - 2][j - 1]->GetPiece()->GetColor();
			if (isBlack != destination)
			{
				vec.push_back(std::make_shared<Vector2>(i - 2, j - 1, true));
				if (cases[i - 2][j - 1]->GetPiece()->GetPieceType() == Piece::PieceType::Roi)
				{
					canEatKing = true;
				}
			}
		}
	}

	if (i >= 1 && j >= 2)
	{
		if (cases[i - 1][j - 2]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i - 1, j - 2, true));
		}
		else
		{
			bool destination = cases[i - 1][j - 2]->GetPiece()->GetColor();
			if (isBlack != destination)
			{
				vec.push_back(std::make_shared<Vector2>(i - 1, j - 2, true));
				if (cases[i - 1][j - 2]->GetPiece()->GetPieceType() == Piece::PieceType::Roi)
				{
					canEatKing = true;
				}
			}
		}
	}

	if (i <= 6 && j >= 2)
	{
		if (cases[i + 1][j - 2]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i + 1, j - 2, true));
		}
		else
		{
			bool destination = cases[i + 1][j - 2]->GetPiece()->GetColor();
			if (isBlack != destination)
			{
				vec.push_back(std::make_shared<Vector2>(i + 1, j - 2, true));
				if (cases[i + 1][j - 2]->GetPiece()->GetPieceType() == Piece::PieceType::Roi)
				{
					canEatKing = true;
				}
			}
		}
	}

	if (i <= 5 && j >= 1)
	{
		if (cases[i + 2][j - 1]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i + 2, j - 1, true));
		}
		else
		{
			bool destination = cases[i + 2][j - 1]->GetPiece()->GetColor();
			if (isBlack != destination)
			{
				vec.push_back(std::make_shared<Vector2>(i + 2, j - 1, true));
				if (cases[i + 2][j - 1]->GetPiece()->GetPieceType() == Piece::PieceType::Roi)
				{
					canEatKing = true;
				}
			}
		}
	}

	if (i <= 5 && j <= 6)
	{
		if (cases[i + 2][j + 1]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i + 2, j + 1, true));
		}
		else
		{
			bool destination = cases[i + 2][j + 1]->GetPiece()->GetColor();
			if (isBlack != destination)
			{
				vec.push_back(std::make_shared<Vector2>(i + 2, j + 1, true));
				if (cases[i + 2][j + 1]->GetPiece()->GetPieceType() == Piece::PieceType::Roi)
				{
					canEatKing = true;
				}
			}
		}
	}

	if (i <= 6 && j <= 5)
	{
		if (cases[i + 1][j + 2]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i + 1, j + 2, true));
		}
		else
		{
			bool destination = cases[i + 1][j + 2]->GetPiece()->GetColor();
			if (isBlack != destination)
			{
				vec.push_back(std::make_shared<Vector2>(i + 1, j + 2, true));
				if (cases[i + 1][j + 2]->GetPiece()->GetPieceType() == Piece::PieceType::Roi)
				{
					canEatKing = true;
				}
			}
		}
	}

	if (i >= 1 && j <= 5)
	{
		if (cases[i - 1][j + 2]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i - 1, j + 2, true));
		}
		else
		{
			bool destination = cases[i - 1][j + 2]->GetPiece()->GetColor();
			if (isBlack != destination)
			{
				vec.push_back(std::make_shared<Vector2>(i - 1, j + 2, true));
				if (cases[i - 1][j + 2]->GetPiece()->GetPieceType() == Piece::PieceType::Roi)
				{
					canEatKing = true;
				}
			}
		}
	}

	return vec;	
}