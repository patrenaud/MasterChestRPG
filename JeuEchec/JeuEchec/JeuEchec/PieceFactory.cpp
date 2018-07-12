#include "PieceFactory.h"
#include "Pion.h"
#include "Tour.h"
#include "Fou.h"
#include "Reine.h"
#include "Cheval.h"
#include "Roi.h"

PieceFactory::PieceFactory()
{
}


PieceFactory::~PieceFactory()
{
}

Piece* PieceFactory::CreatePiece(const Piece::PieceType a_PieceType, const bool is_Black)
{
	switch (a_PieceType)
	{
	case Piece::PieceType::Pion:
		return new Pion(is_Black);

	case Piece::PieceType::Tour:
		return new Tour(is_Black);

	case Piece::PieceType::Cheval:
		return new Cheval(is_Black);

	case Piece::PieceType::Fou:
		return new Fou(is_Black);

	case Piece::PieceType::Reine:
		return new Reine(is_Black);

	case Piece::PieceType::Roi:
		return new Roi(is_Black);
	}
}
