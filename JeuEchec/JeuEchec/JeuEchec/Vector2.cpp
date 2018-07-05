#include "Vector2.h"


Vector2::Vector2(int x, int y, bool isIndex)

{
	if (isIndex)
	{
		m_x = x * 100; // + 100
		m_y = y * 100; // + 100
		m_i = x;
		m_j = y;
	}
	else
	{
		m_x = x;
		m_y = y;
		m_i = (x) / 100; // + 100
		m_j = (y) / 100;  // + 100
	}
}

Vector2::~Vector2()
{
}