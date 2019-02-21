//
// Created by panderium on 21/02/19.
//

#include "utils.h"

location::location() = default;

location::location(int x, int y) {
    this->x = x;
    this->y = y;
}

int location::getX() {
    return this->x;
}

void location::setX(int x) {
    this->x = x;
}

int location::getY() {
    return this->y;
}

void location::setY(int y) {
    location::y = y;
}

location::~location() = default;
