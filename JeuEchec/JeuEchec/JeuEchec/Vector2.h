#pragma once
class Vector2
{
public:
	Vector2(int x, int y, bool isIndex = false);	
	~Vector2();

	const int GetX() { return m_x; }
	const int GetY() { return m_y; }
	const int GetI() { return m_i; }
	const int GetJ() { return m_j; }

private:
	int m_x;
	int m_y;
	int m_i;
	int m_j;
};


