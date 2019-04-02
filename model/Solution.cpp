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
    for (auto i : pls) {
        if(i.getM_num_ville() == pl.getM_num_ville()){
            return true;
        }
    }
    return false;
}


void Solution::supp_place(Place pl) {

    //TODO peut être optimisé

    places.erase(std::remove(places.begin(), places.end(), pl), places.end());
    //std::vector<Place> res;
    //for(int i=0; i <getPlaces().size(); i++){
     //   if(pl.getM_num_ville() != get_place_by_indice(i).getM_num_ville()){
      //      res.push_back(get_place_by_indice(i));
      //  }
    //}

}