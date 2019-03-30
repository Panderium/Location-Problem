//
// Created by panderium on 19-03-29.
//

#ifndef LOCATION_PROBLEM_MAP_H
#define LOCATION_PROBLEM_MAP_H

#include <vector>
#include "Place.h"
#include "../strategy/Strategies.h"

class Map {
private:
    std::vector<Place> m_places;
    Strategy *m_strategy;
public:
    Map();

    Place get_place_by_indice(int ind);

    void add_place(Place p);

    const std::vector<Place> &getM_places() const;

    void setM_places(const std::vector<Place> &m_places);

    void setM_strategy(Strategy *m_strategy);

    void execut_strategy() const;

    std::vector<Place> supp_place(Place pl);

    ~Map() = default;


};


#endif //LOCATION_PROBLEM_MAP_H
