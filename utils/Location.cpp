//
// Created by panderium on 21/02/19.
//

#include "Location.h"

Location::Location() = default;

Location::Location(int x, int y) {
    this->x = x;
    this->y = y;
}

int Location::getX() {
    return this->x;
}

void Location::setX(int x) {
    this->x = x;
}

int Location::getY() {
    return this->y;
}

void Location::setY(int y) {
    Location::y = y;
}

Location::~Location() = default;
