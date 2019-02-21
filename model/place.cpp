//
// Created by panderium on 21/02/19.
//

#include "place.h"

place::place() = default;

place::place(std::string name, location loc) {
    this->name = std::move(name);
    this->loc = loc;
}

location place::getLocation() {}

std::string place::getName() {}

place::~place() = default;