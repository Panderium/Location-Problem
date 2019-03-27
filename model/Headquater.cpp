#include <utility>

//
// Created by panderium on 21/02/19.
//

#include "Headquater.h"

Headquater::Headquater() {
    this->name = "\0";
}

Headquater::Headquater(std::string name) {
    this->name = std::move(name);
}

location Headquater::getLocation() {
    return this->loc;
}

void Headquater::setLocation(location loc) {
    this->loc = loc;
}

Headquater::~Headquater() = default;
