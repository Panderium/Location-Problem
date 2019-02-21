#include <utility>

//
// Created by panderium on 21/02/19.
//

#include "headquater.h"

headquater::headquater() {
    this->name = "\0";
}

headquater::headquater(std::string name) {
    this->name = std::move(name);
}

location headquater::getLocation() {
    return this->loc;
}

void headquater::setLocation(location loc) {
    this->loc = loc;
}

headquater::~headquater() = default;
