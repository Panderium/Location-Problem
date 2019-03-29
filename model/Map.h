//
// Created by panderium on 21/02/19.
//

#ifndef LOCATION_PROBLEM_MAP_H
#define LOCATION_PROBLEM_MAP_H


#include <vector>
#include "Place.h"
#include "Truck.h"
#include "Headquater.h"
#include "../strategy/Strategies.h"

class Map {
public:
    Map();

    virtual ~Map();

public:
    Map add_place(Place p);

    void set_strategy(Strategy *strat);

    void apply_methode();


    const std::vector<Place> &getM_places() const;

    const std::vector<Truck> &getM_trucks() const;

    const Headquater &getM_hq() const;

private:
    std::vector<Place> m_places;
    std::vector<Truck> m_trucks;
    Headquater m_hq;
    Strategy *m_strategy;
};


#endif //LOCATION_PROBLEM_MAP_H
