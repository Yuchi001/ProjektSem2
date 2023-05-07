#include "Vector2.h"

#include <iostream>

const Vector2 Vector2::one = { 1,1 };
const Vector2 Vector2::zero = { 0,0 };

Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Vector2::getX()
{
	return this->x;
}

int Vector2::getY()
{
	return this->y;
}

int Vector2::setX(int x)
{
	this->x = x;
	return this->x;
}

int Vector2::setY(int y)
{
	this->y = y;
	return this->y;
}


bool Vector2::operator==(const Vector2& vector2)
{
	return vector2.x == x && vector2.y == y;
}

Vector2 operator+(const Vector2& vector2, const int& number)
{
	return { vector2.x + number, vector2.y + number };
}

Vector2 operator*(const Vector2& vector2, const int& number)
{
	return { vector2.x * number, vector2.y * number };
}

Vector2 operator+(const Vector2& first, const Vector2& second)
{
	return { first.x + second.x, first.y + second.y };

}

Vector2 operator-(const Vector2& vector2, const int& number)
{
	return { vector2.x - number, vector2.y - number };
}

Vector2 operator-(const Vector2& first, const Vector2& second)
{
	return { first.x - second.x, first.y - second.y };
}


std::ostream& operator<<(std::ostream& os, const Vector2& vector2)
{
	os << vector2.x << " " << vector2.y;
	return os;
}


