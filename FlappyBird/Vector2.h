#pragma once
#include <ostream>

struct Vector2
{
public:
	Vector2();
	Vector2(int x, int y);

	int getX();
	int getY();

	int setX(int x);
	int setY(int y);

	static const Vector2 zero;
	static const Vector2 one;

	bool operator==(const Vector2 &vector2);

	friend Vector2 operator+(const Vector2& vector2, const int& number);

	friend Vector2 operator*(const Vector2& vector2, const int& number);

	friend Vector2 operator+(const Vector2& first, const Vector2& second);

	friend Vector2 operator-(const Vector2& first, const Vector2& second);

	friend Vector2 operator-(const Vector2& vector2, const int& number);

	friend std::ostream& operator<<(std::ostream& os, const Vector2& vector2);

private:
	int x = 0;
	int y = 0;
};
