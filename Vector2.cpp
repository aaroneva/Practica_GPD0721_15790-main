#include "Vector2.h"
#include "math.h"

void Vector2::SetX(float x)
{
    this->x = x;
}
void Vector2::SetY(float y)
{
    this->y = y;
}

float Vector2::GetX()
{
    return x;
}
float Vector2::GetY()

{
    return y;
}

Vector2 Vector2::operator+(Vector2 a)
{
    Vector2 suma;
    suma.SetX(x + a.GetX());
    suma.SetY(y + a.GetY());
    return suma;
}

Vector2 Vector2::operator-(Vector2 a)
{
    Vector2 res;
    res.SetX(x - a.GetX());
    res.SetY(y - a.GetY());
    return res;
}

Vector2 Vector2::operator*(float a) 
{
    Vector2 mult;
    mult.SetX(x * a);
    mult.SetY(y * a);
    return mult;
}
float  Vector2::operator*(Vector2 b2)
{
    float  mult;
    mult = x * b2.x + y * b2.y;
    return mult;
}

float Vector2::Norm()
{
    return sqrt((x * x) + (y * y));
}

Vector2 Vector2::Unit()
{
    Vector2 unit;
    unit.SetX(x/Norm());
    unit.SetY(y/Norm());
    return unit;
}
Vector2::Vector2() {
    x = 0;
    y = 0;
}
Vector2::Vector2(float x, float y) {
    this->x = x;
    this->y = y;
}


