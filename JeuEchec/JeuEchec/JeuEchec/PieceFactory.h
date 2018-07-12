#pragma once
#include "Piece.h"

static class PieceFactory
{
public:
	PieceFactory();
	~PieceFactory();

	static Piece* CreatePiece(const Piece::PieceType a_PieceType, const bool is_Black);
};

