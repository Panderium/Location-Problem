//
// Created by panderium on 21/02/19.
//

#include "place.h"

place::place() = default;

place::place(std::string name, location loc) {
    this->name = std::move(name);
    this->loc = loc;
}
float place::get_latitude(){
    return latitude;
}
float place::get_longitude(){
    return longitude;
}

location place::getLocation() {}

std::string place::getName() {}

int place::get_num_ville(){
    return  num_ville;
}
char place::get_type(){
    return type;
}
int place::get_besoin(){
    return besoin;
}


place::~place() = default;