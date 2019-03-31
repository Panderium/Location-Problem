//
// Created by camil on 30/03/2019.
//

#include "Solution.h"

const std::vector<float> &Solution::getDistance() const {
    return distance;
}

void Solution::setDistance(const std::vector<float> &distance) {
    Solution::distance = distance;
}

const std::vector<Place> &Solution::getPlaces() const {
    return places;
}

void Solution::setPlaces(const std::vector<Place> &places) {
    Solution::places = places;
}

const Place &Solution::getSolution() const {
    return solution;
}

void Solution::setSolution(const Place &solution) {
    Solution::solution = solution;
}

float & Solution::get_dist_by_indice(int ind) {
    std::vector<float> dist = getDistance();
    return dist[ind];
}

Place Solution::get_place_by_indice(int ind) {
    std::vector<Place> places = getPlaces();
    return places[ind];
}

void Solution::add_distance(float f) {
    distance.push_back(f);
}

bool Solution::is_in(std::vector<Place> pls, Place pl) {
    for(int i=0; i<pls.size();i++){
        if(pls[i] == pl){
            return true;
        }
    }
    return false;
}

