#include "Fou.h"
#include <SDL_image.h>
#include "Case.h"


Fou::Fou(bool IsBlack)
	: Piece(IsBlack)
{
	//Texture de la piece
	m_Texture = IsBlack ? IMG_Load("images/bFou.png") : IMG_Load("images/wFou.png");
	//Type de la piece
	Piece::m_Type = PieceType::Fou;
	//Stats de la piece
	m_Stats.hp = 3;
	m_Stats.armor = 1;
	m_Stats.attack = 2;
	//Description du spell de la piece
	m_SpellText = "Allahu Akbar!: Kills an enemy unit with yourself";
}

Fou::~Fou()
{
}

std::vector<std::shared_ptr<Vector2>> Fou::Move(int i, int j, const std::vector<std::vector<std::shared_ptr<Case>>>& cases)
{
	//Pour savoir la couleur de la case destination(si isBlack == destination les pièces sont de la même couleur)
	bool destination;
	//Vector (contenant de tout destination possible) 
	std::vector<std::shared_ptr<Vector2>>vec = {};

	//boucle sur la largeur et/ou longeur du board
	for (int w = 1; w < 8; w++)
	{
		//Mon fou peut-il se déplacer en diagonale vers le bas et la droite
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
		//Mon fou peut-il se déplacer en diagonale vers le haut et la gauche
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
		//Mon fou peut-il se déplacer en diagonale vers le haut et la droite
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
		//Mon fou peut-il se déplacer en diagonale vers le bas et la gauche
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
		//Mon fou peut-il se déplacer en diagonale vers le bas et la droite
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
		//Mon fou peut-il se déplacer en diagonale vers le haut et la gauche
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
		//Mon fou peut-il se déplacer en diagonale vers le haut et la droite
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
		//Mon fou peut-il se déplacer en diagonale vers le bas et la gauche
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

				else
				{
					break;
				}
			}
		}
	}

	return vec;
}

void Fou::CastSpell(const std::shared_ptr<Board>& aBoard, const std::shared_ptr<Case>& aCase)
{
	//tue la piece qui recoit le spell
	aCase->GetPiece() = nullptr;

	Piece::CastSpell(aBoard, aCase);
}
