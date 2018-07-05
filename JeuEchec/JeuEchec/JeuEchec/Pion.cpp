#include "Pion.h"
#include <SDL_image.h>
#include "Case.h"

Pion::Pion(bool IsBlack)
	: Piece(IsBlack)
{
	m_Texture = IsBlack ? IMG_Load("images/bPion.png") : IMG_Load("images/wPion.png");
	Piece::m_Type = PieceType::Pion;
}


Pion::~Pion()
{
}

std::vector<std::shared_ptr<Vector2>> Pion::Move(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases)
{
	std::vector<std::shared_ptr<Vector2>>vec = {};

	bool isBlack = cases[i][j]->GetPiece()->GetColor();
	bool BeenPlayed = false;
	bool destination;
	
	if (!isBlack)
	{
		if (cases[i+1][j]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i + 1, j, true));
			if(i == 1 && cases[i + 1][j]->GetPiece() == nullptr && cases[i + 2][j]->GetPiece() == nullptr)
			{
				vec.push_back(std::make_shared<Vector2>(i + 2, j, true));
			}
		}
	}
	if (!isBlack && i <= 6 && j <= 6)
	{
		if (cases[i + 1][j + 1]->GetPiece() != nullptr)
		{
			destination = cases[i + 1][j + 1]->GetPiece()->GetColor();
			if (isBlack != destination)
			{
				vec.push_back(std::make_shared<Vector2>(i + 1, j + 1, true));
				if (cases[i + 1][j + 1]->GetPiece()->GetPieceType() == Piece::PieceType::Roi)
				{
					canEatKing = true;
				}
			}
		}
	}
	if (!isBlack && i <= 6 && j >= 1)
	{
		if (cases[i + 1][j - 1]->GetPiece() != nullptr)
		{
			destination = cases[i + 1][j - 1]->GetPiece()->GetColor();
			if (isBlack != destination)
			{
				vec.push_back(std::make_shared<Vector2>(i + 1, j - 1, true));
				if (cases[i + 1][j - 1]->GetPiece()->GetPieceType() == Piece::PieceType::Roi)
				{
					canEatKing = true;
				}
			}
		}
	}
	
	if (isBlack)
	{
		if (cases[i-1][j]->GetPiece() == nullptr)
		{
			vec.push_back(std::make_shared<Vector2>(i - 1, j, true));
			if (i == 6 && cases[i - 1][j]->GetPiece() == nullptr && cases[i - 2][j]->GetPiece() == nullptr)
			{
				vec.push_back(std::make_shared<Vector2>(i - 2, j, true));
			}
		}
		if (isBlack && i >=1 && j >= 1)
		{

			if (cases[i - 1][j - 1]->GetPiece() != nullptr)
			{
				destination = cases[i - 1][j - 1]->GetPiece()->GetColor();
				if (isBlack != destination)
				{
					vec.push_back(std::make_shared<Vector2>(i - 1, j - 1, true));
					if (cases[i - 1][j - 1]->GetPiece()->GetPieceType() == Piece::PieceType::Roi)
					{
						canEatKing = true;
					}
				}
			}
		}
		if (isBlack && i >= 1 && j <= 6)
		{
			if (cases[i - 1][j + 1]->GetPiece() != nullptr)
			{
				destination = cases[i - 1][j + 1]->GetPiece()->GetColor();
				if (isBlack != destination)
				{
					vec.push_back(std::make_shared<Vector2>(i - 1, j + 1, true));
					if (cases[i - 1][j + 1]->GetPiece()->GetPieceType() == Piece::PieceType::Roi)
					{
						canEatKing = true;
					}
				}
			}
		}
	}

	return vec;
}
