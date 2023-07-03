#include "Position.h"

Position::Position(int x, int y)
{
    setX(x);
    setY(y);
}

bool Position::isEqual(Position position) const
{
    return this->x == position.getX() && this->y == position.getY();
}

int Position::getX() const
{
    return this->x;
}

void Position::setX(int x)
{
    if (x >= 0) {
        this->x = x;
    }
    else {
        this->x = 0;
    }
}

int Position::getY() const
{
    return this->y;
}

void Position::setY(int y)
{
    if (y >= 0) {
        this->y = y;
    }
    else {
        this->y = 0;
    }
}

std::string Position::toString()
{
    return "(" + std::to_string(getX()) + ", " + std::to_string(getY()) + ")";
}

double Position::distance(Position position)
{
    double dx = (double)this->getX() - (double)position.getX();
    double dy = (double)this->getY() - (double)position.getY();
    return sqrt((dx * dx) + (dy * dy));
}

void Position::move(int dx, int dy)
{
    setX(getX() + dx);
    setY(getY() + dy);
}
