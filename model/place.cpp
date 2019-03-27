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

void place::set_longitude(float lon) {
    longitude = lon;
}
void place::set_latitude(float lat) {
    latitude = lat;
}
void place::set_besoin(int bes) {
    besoin = bes;
}
void place::set_num_ville(int num) {
    num_ville = num;
}

void place::set_type(char ty) {
    type = ty;
}
place::~place() = default;