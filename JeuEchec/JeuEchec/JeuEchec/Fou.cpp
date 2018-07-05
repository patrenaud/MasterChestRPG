#include "Fou.h"
#include <SDL_image.h>
#include "Case.h"


Fou::Fou(bool IsBlack)
	: Piece(IsBlack)
{
	m_Texture = IsBlack ? IMG_Load("images/bFou.png") : IMG_Load("images/wFou.png");
	Piece::m_Type = PieceType::Fou;
}


Fou::~Fou()
{
}

std::vector<std::shared_ptr<Vector2>> Fou::Move(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases)
{
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
				bool destination = cases[i + w][j + w]->GetPiece()->GetColor();
				if (isBlack == destination)
				{
					break;
				}
				else if (isBlack != destination)
				{
					vec.push_back(std::make_shared<Vector2>(i + w, j + w, true));
					
					if (cases[i+w][j+w]->GetPiece()->GetPieceType() == Piece::PieceType::Roi)
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
					
					if (cases[i + w][j - w]->GetPiece()->GetPieceType() == Piece::PieceType::Roi)
					{
						canEatKing = true;
					}
					break;
				}
			}
		}
	}
	
	return vec;
}
