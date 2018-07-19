#include "Controls.h"
#include "Board.h"
#include "Case.h"
#include "Piece.h"
#include "Vector2.h"
#include "Roi.h"
#include <fstream>
#include <string>


Controls::Controls()
	: m_ControlState(EControlState::ATTACK_PHASE)
{
	m_WhitePlayer = new Player{};
	m_BlackPlayer = new Player{};

	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
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
			board->SetHighlightFalse();

			if (e.key.keysym.sym == SDLK_SPACE)
			{
				std::cout << "Restart Game" << std::endl;
				return true;
			}

			// This contains all Powers that the player can make
#pragma region---       ---Power Activatables
			if (e.key.keysym.sym == SDLK_1)
			{
				if (m_ControlState == POWER1)
				{
					m_ControlState = ATTACK_PHASE;
				}
				else
				{
					std::cout << "State: power 1" << std::endl;
					m_ControlState = POWER1;

					const std::vector<std::vector<std::shared_ptr<Case>>>& cases = board->GetCases();
					// Player needs to have enough Mana
					if (m_WhitePlayer->GetMana() >= 1 && m_WhitePlaying ||
						m_BlackPlayer->GetMana() >= 1 && !m_WhitePlaying)
					{
						for (int i = 0; i < cases.size(); i++)
						{
							for (int j = 0; j < cases[i].size(); j++)
							{
								std::shared_ptr<Piece> piece = cases[i][j]->GetPiece();
								// If conditions are met in any case of the board, cases are highlighted
								if (piece != nullptr && piece->GetColor() == !m_WhitePlaying && !piece->GetCanSpell())
								{
									cases[i][j]->SetHighlight(true);
								}
							}
						}
					}
				}
			}

			if (e.key.keysym.sym == SDLK_2)
			{
				if (m_ControlState == POWER2)
				{
					m_ControlState = ATTACK_PHASE;
				}
				else
				{
					std::cout << "State: power 2" << std::endl;
					m_ControlState = POWER2;

					const std::vector<std::vector<std::shared_ptr<Case>>>& cases = board->GetCases();
					// Player needs to have enough Mana
					if (m_WhitePlayer->GetMana() >= 1 && m_WhitePlaying ||
						m_BlackPlayer->GetMana() >= 1 && !m_WhitePlaying)
					{
						for (int i = 0; i < cases.size(); i++)
						{
							for (int j = 0; j < cases[i].size(); j++)
							{
								std::shared_ptr<Piece> piece = cases[i][j]->GetPiece();
								// If conditions are met in any case of the board, cases are highlighted
								if (piece != nullptr && piece->GetColor() == m_WhitePlaying && piece->GetArmor() > 0)
								{
									cases[i][j]->SetHighlight(true);
								}
							}
						}
					}
				}
			}
			if (e.key.keysym.sym == SDLK_3)
			{
				int damage;
				std::uniform_int_distribution<int> uni(2, 4); // guaranteed unbiased
				damage = uni(rng);
				std::cout << "Damage: " << damage;
				if (m_WhitePlayer->GetMana() >= 3 && m_WhitePlaying)
				{
					m_WhitePlayer->SetMana(-3);
					if (m_BlackPlayer->GetMana() - damage < 0)
					{
						m_BlackPlayer->SetMana(-m_BlackPlayer->GetMana());
					}
					else
					{
						m_BlackPlayer->SetMana(-damage);
					}
				}
				else if (m_BlackPlayer->GetMana() >= 3 && !m_WhitePlaying)
				{
					m_BlackPlayer->SetMana(-3);
					if (m_WhitePlayer->GetMana() - damage < 0)
					{
						m_WhitePlayer->SetMana(-m_WhitePlayer->GetMana());
					}
					else
					{
						m_WhitePlayer->SetMana(-damage);
					}
				}
				m_ControlState = ATTACK_PHASE;
			}
			if (e.key.keysym.sym == SDLK_4)
			{
				if (m_ControlState == POWER4)
				{
					m_ControlState = ATTACK_PHASE;
				}
				else
				{
					std::cout << "State: power 4" << std::endl;
					m_ControlState = POWER4;
					const std::vector<std::vector<std::shared_ptr<Case>>>& cases = board->GetCases();
					// Player needs to have enough Mana
					if (m_WhitePlayer->GetMana() >= 4 && m_WhitePlaying ||
						m_BlackPlayer->GetMana() >= 4 && !m_WhitePlaying)
					{
						for (int i = 0; i < cases.size(); i++)
						{
							for (int j = 0; j < cases[i].size(); j++)
							{
								std::shared_ptr<Piece> piece = cases[i][j]->GetPiece();
								// If conditions are met in any case of the board, cases are highlighted
								if (piece != nullptr && piece->GetColor() == m_WhitePlaying && piece->GetHP() > 0)
								{
									cases[i][j]->SetHighlight(true);
								}
							}
						}
					}

				}
			}

			if (e.key.keysym.sym == SDLK_5)
			{
				if (m_ControlState == POWER5)
				{
					m_ControlState = ATTACK_PHASE;
				}
				else
				{
					std::cout << "State: power 5" << std::endl;
					m_ControlState = POWER5;
					const std::vector<std::vector<std::shared_ptr<Case>>>& cases = board->GetCases();
					// Player needs to have enough Mana
					if (m_WhitePlayer->GetMana() >= 9 && m_WhitePlaying ||
						m_BlackPlayer->GetMana() >= 9 && !m_WhitePlaying)
					{
						for (int i = 0; i < cases.size(); i++)
						{
							for (int j = 0; j < cases[i].size(); j++)
							{
								std::shared_ptr<Piece> piece = cases[i][j]->GetPiece();
								// If conditions are met in any case of the board, cases are highlighted
								if (piece != nullptr && piece->GetColor() == !m_WhitePlaying && piece->GetHP() > 0)
								{
									cases[i][j]->SetHighlight(true);
								}
							}
						}
					}
				}
			}
#pragma endregion		

			if (e.key.keysym.sym == SDLK_x)
			{
				_case = nullptr;
				board->SetHighlightFalse();

				if (m_ControlState == ATTACK_PHASE)
				{
					int x = 0;
					int y = 0;
					SDL_GetMouseState(&x, &y);
					std::shared_ptr<Vector2> Pos = std::make_shared<Vector2>(x, y);
					std::shared_ptr<Piece>& currentPiece = board->GetCase(Pos->GetJ(), Pos->GetI())->GetPiece();

					if (currentPiece != nullptr &&
						currentPiece->GetColor() == !m_WhitePlaying &&
						currentPiece->GetCanSpell() == true)
					{
						// Gets all targets available for spell
						availableSpellDest = board->GetCase(Pos->GetJ(), Pos->GetI())->GetPiece()->SpellTarget(Pos->GetJ(), Pos->GetI(), board->GetCases());

						if (availableSpellDest.size() > 0)
						{
							_case = board->GetCase(Pos->GetJ(), Pos->GetI());
							for (int i = 0; i < availableSpellDest.size(); i++)
							{
								// Highlights all possibilities
								board->GetCase(availableSpellDest[i]->GetI(), availableSpellDest[i]->GetJ())->SetHighlight(true);
							}
							m_ControlState = SPELL_PHASE;
						}
					}
				}
				else if (m_ControlState == SPELL_PHASE)
				{
					m_ControlState = ATTACK_PHASE;
				}
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

			if (_case != nullptr && m_ControlState != SPELL_PHASE)
			{
				_case->GetRect().x = x - 50;
				_case->GetRect().y = y - 50;
			}

			std::shared_ptr<Vector2> Pos = std::make_shared<Vector2>(x, y);

			// This whole condition shows all UI at runtime using ETextType enum
			if (x > 0 && x < 800 && y < 800 && y > 0)
			{
				m_MouseSensor = board->GetCase(Pos->GetJ(), Pos->GetI());
				if (m_MouseSensor->GetPiece())
				{
					// Shows all stats or information to UI (right of board)
					Texts::m_Texts[Texts::ETextType::Hp].text = "HP: " + std::to_string(m_MouseSensor->GetPiece()->GetHP());
					Texts::m_Texts[Texts::ETextType::Damage].text = "Attack: " + std::to_string(m_MouseSensor->GetPiece()->GetDamage());
					Texts::m_Texts[Texts::ETextType::Armor].text = "Armor: " + std::to_string(m_MouseSensor->GetPiece()->GetArmor());
					Texts::m_Texts[Texts::ETextType::PowerText].text = m_MouseSensor->GetPiece()->GetSpellText();
					Texts::m_Texts[Texts::ETextType::Power].text = m_MouseSensor->GetPiece()->GetCanSpell() ? "Power: Available" : "Power: Unvailable";
					Texts::m_Texts[Texts::ETextType::Player1].text = "Player 1 Mana: " + std::to_string(m_WhitePlayer->GetMana());
					Texts::m_Texts[Texts::ETextType::Player2].text = "Player 2 Mana: " + std::to_string(m_BlackPlayer->GetMana());
					Texts::m_Texts[Texts::ETextType::Playing].text = m_WhitePlaying ? "Playing: White" : "Playing: Black";
				}
				else
				{
					// if no piece is under Mouse hover, stats are hidden. (they would stay in place without this part)
					Texts::m_Texts[Texts::ETextType::Hp].text = "HP: ";
					Texts::m_Texts[Texts::ETextType::Damage].text = "Attack: ";
					Texts::m_Texts[Texts::ETextType::Armor].text = "Armor: ";
					Texts::m_Texts[Texts::ETextType::Power].text = "";
					Texts::m_Texts[Texts::ETextType::PowerText].text = "";
				}
			}
		}

		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			// When no spell is triggered, game works normally
			if (m_ControlState == ATTACK_PHASE)
			{
				int x = 0;
				int y = 0;
				SDL_GetMouseState(&y, &x);
				std::shared_ptr<Vector2> Pos = std::make_shared<Vector2>(x, y);

				_case = board->GetCase(Pos->GetI(), Pos->GetJ());

				// Need to find a Piece and it has to be the right color depending on turn
				if (_case->GetPiece() != nullptr && _case->GetPiece()->GetColor() == !m_WhitePlaying)
				{
					// This provides the diffrent moves the player can make with this Piece
					availableMoves = _case->GetPiece()->Move(Pos->GetI(), Pos->GetJ(), board->GetCases());

					for (int i = 0; i < availableMoves.size(); i++)
					{
						board->GetCase(availableMoves[i]->GetI(), availableMoves[i]->GetJ())->SetHighlight(true);
					}
				}
				else
				{
					_case = nullptr;
				}
			}
			// Spell Phase is when a unit has activated its spell
			else if (m_ControlState == SPELL_PHASE)
			{
				int x = 0;
				int y = 0;
				SDL_GetMouseState(&y, &x);
				std::shared_ptr<Vector2> Pos = std::make_shared<Vector2>(x, y);

				const bool isHighlight = board->GetCase(Pos->GetI(), Pos->GetJ())->GetHighlight();

				if (isHighlight == true)
				{
					// These 3 spells require to make change in cases selected.
					_case->GetPiece()->CastSpell(board, board->GetCase(Pos->GetI(), Pos->GetJ()));
					// Bishop destroys itself and the other
					if (_case->GetPiece() != nullptr && _case->GetPiece()->GetPieceType() == Piece::Fou)
					{
						_case->GetPiece() = nullptr;
					}
					// Peon swaps with other unit
					else if (_case->GetPiece() != nullptr && _case->GetPiece()->GetPieceType() == Piece::Pion)
					{
						std::swap(_case->GetPiece(), board->GetCase(Pos->GetI(), Pos->GetJ())->GetPiece());
					}
					// Knight needs to go to available case
					else if (_case->GetPiece() != nullptr && _case->GetPiece()->GetPieceType() == Piece::Cheval)
					{
						board->GetCase(Pos->GetI(), Pos->GetJ())->GetPiece() = _case->GetPiece();
						_case->GetPiece() = nullptr;
					}
				}
				m_ControlState = ATTACK_PHASE;
				board->SetHighlightFalse();

				_case = nullptr;
			}

			else if (m_ControlState == POWER1)
			{
				int x = 0;
				int y = 0;
				SDL_GetMouseState(&x, &y);
				std::shared_ptr<Vector2> Pos = std::make_shared<Vector2>(x, y);
				std::shared_ptr<Piece>& currentPiece = board->GetCase(Pos->GetJ(), Pos->GetI())->GetPiece();
				if (board->GetCase(Pos->GetJ(), Pos->GetI())->GetHighlight())
				{
					currentPiece->SetCanSpell(true);
					// Mana is decreased depending on player
					if (m_WhitePlayer->GetMana() >= 1 && m_WhitePlaying)
					{
						m_WhitePlayer->SetMana(-1);
					}
					else if (m_BlackPlayer->GetMana() >= 1 && !m_WhitePlaying)
					{
						m_BlackPlayer->SetMana(-1);
					}
				}
				// After spell, all units highlighted are turned off and attack phase returns
				const std::vector<std::vector<std::shared_ptr<Case>>>& cases = board->GetCases();
				for (int i = 0; i < cases.size(); i++)
				{
					for (int j = 0; j < cases[i].size(); j++)
					{
						cases[i][j]->SetHighlight(false);
					}
				}
				m_ControlState = ATTACK_PHASE;
			}

			else if (m_ControlState == POWER2)
			{
				int x = 0;
				int y = 0;
				SDL_GetMouseState(&x, &y);
				std::shared_ptr<Vector2> Pos = std::make_shared<Vector2>(x, y);
				std::shared_ptr<Piece>& currentPiece = board->GetCase(Pos->GetJ(), Pos->GetI())->GetPiece();
				if (board->GetCase(Pos->GetJ(), Pos->GetI())->GetHighlight())
				{
					currentPiece->SetArmor(0); // Armor of targeted unit is set to 0
					// Mana is decreased depending on player
					if (m_WhitePlayer->GetMana() >= 2 && m_WhitePlaying)
					{
						m_WhitePlayer->SetMana(-2);
					}
					else if (m_BlackPlayer->GetMana() >= 2 && !m_WhitePlaying)
					{
						m_BlackPlayer->SetMana(-2);
					}
				}
				// After spell, all units highlighted are turned off and attack phase returns
				const std::vector<std::vector<std::shared_ptr<Case>>>& cases = board->GetCases();
				for (int i = 0; i < cases.size(); i++)
				{
					for (int j = 0; j < cases[i].size(); j++)
					{
						cases[i][j]->SetHighlight(false);
					}
				}
				m_ControlState = ATTACK_PHASE;
			}

			else if (m_ControlState == POWER3)
			{
				/*if (m_WhitePlayer->GetMana() >= 3 && m_WhitePlaying)
				{
					m_WhitePlayer->SetMana(-3);
					m_BlackPlayer->SetMana(-3);
				}
				else if (m_BlackPlayer->GetMana() >= 3 && !m_WhitePlaying)
				{
					m_BlackPlayer->SetMana(-3);
					m_WhitePlayer->SetMana(-3);
				}
				m_ControlState = ATTACK_PHASE;*/
				// Permet de jouer 2 fois
				// Mana cost = ??
			}

			else if (m_ControlState == POWER4)
			{
				int x = 0;
				int y = 0;
				SDL_GetMouseState(&x, &y);
				std::shared_ptr<Vector2> Pos = std::make_shared<Vector2>(x, y);
				std::shared_ptr<Piece>& currentPiece = board->GetCase(Pos->GetJ(), Pos->GetI())->GetPiece();
				if (board->GetCase(Pos->GetJ(), Pos->GetI())->GetHighlight())
				{
					currentPiece->SetDamage(5); // Does 5 dmg to enemy
					// Mana is decreased depending on player
					if (m_WhitePlayer->GetMana() >= 4 && m_WhitePlaying)
					{
						m_WhitePlayer->SetMana(-4);
					}
					else if (m_BlackPlayer->GetMana() >= 4 && !m_WhitePlaying)
					{
						m_BlackPlayer->SetMana(-4);
					}

					if (currentPiece->GetHP() <= 0)
					{
						currentPiece = nullptr;
					}
				}
				// After spell, all units highlighted are turned off and attack phase returns
				const std::vector<std::vector<std::shared_ptr<Case>>>& cases = board->GetCases();
				for (int i = 0; i < cases.size(); i++)
				{
					for (int j = 0; j < cases[i].size(); j++)
					{
						cases[i][j]->SetHighlight(false);
					}
				}
				m_ControlState = ATTACK_PHASE;
			}

			else if (m_ControlState == POWER5)
			{
				int x = 0;
				int y = 0;
				SDL_GetMouseState(&x, &y);
				std::shared_ptr<Vector2> Pos = std::make_shared<Vector2>(x, y);
				std::shared_ptr<Piece>& currentPiece = board->GetCase(Pos->GetJ(), Pos->GetI())->GetPiece();
				if (board->GetCase(Pos->GetJ(), Pos->GetI())->GetHighlight())
				{
					// Boosts stats of targeted ally
					currentPiece->SetArmor(currentPiece->GetArmor() + 9);
					currentPiece->AttackGain(9);
					currentPiece->HPGain(9);

					// Mana is decreased depending on player
					if (m_WhitePlayer->GetMana() >= 9 && m_WhitePlaying)
					{
						m_WhitePlayer->SetMana(-9);
					}
					else if (m_BlackPlayer->GetMana() >= 9 && !m_WhitePlaying)
					{
						m_BlackPlayer->SetMana(-9);
					}
				}
				// After spell, all units highlighted are turned off and attack phase returns
				const std::vector<std::vector<std::shared_ptr<Case>>>& cases = board->GetCases();
				for (int i = 0; i < cases.size(); i++)
				{
					for (int j = 0; j < cases[i].size(); j++)
					{
						cases[i][j]->SetHighlight(false);
					}
				}
				m_ControlState = ATTACK_PHASE;
			}

		}
		else if (e.type == SDL_MOUSEBUTTONUP)
		{
			board->SetHighlightFalse();
			if (m_ControlState == ATTACK_PHASE)
			{
				if (_case != nullptr)
				{
					int x = 0;
					int y = 0;
					SDL_GetMouseState(&y, &x);
					std::shared_ptr<Vector2> Pos = std::make_shared<Vector2>(x, y);
					for (int i = 0; i < availableMoves.size(); i++)
					{

						if (Pos->GetI() == availableMoves[i]->GetI() &&
							Pos->GetJ() == availableMoves[i]->GetJ())
						{
							SaveMove(_case, Pos); // Saves the move in the Save.txt file

							std::shared_ptr<Piece> targetedPiece = board->GetCase(Pos->GetI(), Pos->GetJ())->GetPiece();
							if (targetedPiece != nullptr)
							{
								_case->GetPiece()->Attack(targetedPiece);
								if (targetedPiece->GetHP() <= 0)
								{
									board->GetCase(Pos->GetI(), Pos->GetJ())->GetPiece() = _case->GetPiece();
									_case->GetPiece() = nullptr;
								}
							}
							else
							{
								board->GetCase(Pos->GetI(), Pos->GetJ())->GetPiece() = _case->GetPiece();
								_case->GetPiece() = nullptr;
							}
							SwitchTurn(board);
						}
					}
					_case->Reset();
					_case = nullptr;
				}
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

// This is to Increase mana to players and to switch player's turn
void Controls::SwitchTurn(const std::shared_ptr<Board>& board)
{
	if (m_WhitePlaying)
	{
		m_WhitePlayer->IncreaseMana();
	}
	else
	{
		m_BlackPlayer->IncreaseMana();
	}

	const std::vector<std::vector<std::shared_ptr<Case>>>& cases = board->GetCases();
	for (int i = 0; i < cases.size(); i++)
	{
		for (int j = 0; j < cases[i].size(); j++)
		{
			std::shared_ptr<Piece> piece = cases[i][j]->GetPiece();
			// Need to check if all piece are gone and stop the game
		}
	}

	m_WhitePlaying = !m_WhitePlaying; // When a piece is dropped to another spot, the player's turn is done (bool)
}