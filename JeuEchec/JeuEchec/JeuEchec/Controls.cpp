#include "Controls.h"
#include "Board.h"
#include "Case.h"
#include "Piece.h"
#include "Vector2.h"
#include "Roi.h"
#include <fstream>

Controls::Controls()
{
}

Controls::~Controls()
{
}



bool Controls::Update(const std::shared_ptr<Board>& board, SDL_Surface* screen)
{
	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;

	if (_case != nullptr)
	{
		_case->Render(screen);
	}

	//Handle events on queue
	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.sym == SDLK_SPACE)
			{
				std::cout << "Restart Game" << std::endl;
				return true;
			}
		}

		//User requests quit
		if (e.type == SDL_QUIT)
		{
			quit = true;
		}

		// User Mouse hover 
		if (e.type == SDL_MOUSEMOTION)
		{
			int x = 0;
			int y = 0;
			SDL_GetMouseState(&x, &y);

			if (_case != nullptr)
			{
				_case->GetRect().x = x - 50;
				_case->GetRect().y = y - 50;
			}
		}

		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			int x = 0;
			int y = 0;
			SDL_GetMouseState(&y, &x);
			std::shared_ptr<Vector2> Pos = std::make_shared<Vector2>(x, y);

			_case = board->GetCase(Pos->GetI(), Pos->GetJ());

			// Need to find a Piece and it has to be the right color depending on turn
			if (_case->GetPiece() != nullptr && _case->GetPiece()->GetColor() == !m_WhitePlaying)
			{
				if (!kingNeedToMove || (kingNeedToMove && _case->GetPiece()->GetPieceType() == Piece::Roi))
				{
					// This provides the diffrent moves the player can make with this Piece
					availableMoves = _case->GetPiece()->Move(Pos->GetI(), Pos->GetJ(), board->GetCases());

					for (int i = 0; i < availableMoves.size(); i++)
					{
						board->GetCase(availableMoves[i]->GetI(), availableMoves[i]->GetJ())->SetHighlight(true);
					}
				}
			}
			else
			{
				_case = nullptr;
			}
		}
		else if (e.type == SDL_MOUSEBUTTONUP)
		{
			if (_case != nullptr)
			{
				int x = 0;
				int y = 0;
				SDL_GetMouseState(&y, &x);
				std::shared_ptr<Vector2> Pos = std::make_shared<Vector2>(x, y);
				for (int i = 0; i < availableMoves.size(); i++)
				{
					for (int i = 0; i < availableMoves.size(); i++)
					{
						board->GetCase(availableMoves[i]->GetI(), availableMoves[i]->GetJ())->SetHighlight(false);
					}

					if (Pos->GetI() == availableMoves[i]->GetI() &&
						Pos->GetJ() == availableMoves[i]->GetJ())
					{
						SaveMove(_case, Pos); // Saves the move in the Save.txt file
						board->GetCase(Pos->GetI(), Pos->GetJ())->GetPiece() = _case->GetPiece();
						_case->GetPiece() = nullptr;

						m_WhitePlaying = !m_WhitePlaying; // When a piece is dropped to another spot, the player's turn is done (bool)

						kingNeedToMove = false;

						// This cheks all the other side's object to see if the King is in danger
						enemiesMoves = std::vector<std::vector<std::shared_ptr<Vector2>>>();
						for (int i = 0; i < board->GetCases().size(); i++)
						{
							for (int j = 0; j < board->GetCases()[i].size(); j++)
							{
								if (board->GetCases()[i][j]->GetPiece() != nullptr)
								{
									// si la couleur joueur actuel n'est pas la couleur de la piece
									if (board->GetCases()[i][j]->GetPiece()->GetColor() == m_WhitePlaying)
									{
										board->GetCases()[i][j]->GetPiece()->Move(i, j, board->GetCases());
										if (board->GetCases()[i][j]->GetPiece()->GetCanEatKing())
										{
											kingNeedToMove = true;
											std::cout << "KingNeedsToMove" + kingNeedToMove << std::endl;
											board->GetCases()[i][j]->GetPiece()->SetCanEatKing(false);
										}
									}
								}
							}
							_case->GetPiece() = nullptr;
						}
					}
				}
				_case->Reset();
				_case = nullptr;
			}
		}
	}
	return false;
}

void Controls::SaveMove(std::shared_ptr<Case> _case, std::shared_ptr<Vector2> Pos)
{
	std::ofstream SaveGame;
	SaveGame.open("Save.txt", std::ios::app);

	// Inverse I and J cause x and y are inverted on mouse state.	
	SaveGame << _case->GetOrigin()->GetJ() << _case->GetOrigin()->GetI() << Pos->GetI() << Pos->GetJ() << std::endl;

	SaveGame.close();
}

