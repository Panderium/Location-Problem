//
// Created by panderium on 21/02/19.
//

#ifndef LOCATION_PROBLEM_STRATEGIES_H
#define LOCATION_PROBLEM_STRATEGIES_H

#include <iostream>
#include "../model/Map.h"

class Strategy {
public:
    Strategy() : { m_places = m_map->getM_places() };

    virtual void execute(Map *map) {
        m_map = map;
    };

protected:
    std::vector<Place> m_places
    Map *m_map;
};

class ApproximateStrategy : public Strategy {
public:
    ApproximateStrategy();

    void execute(Map *map) override;

private:


};

class ExactStrategy : public Strategy {
public:
    ExactStrategy();

    void execute(Map *map) override;


private:
    std::vector<std::vector<float>> m_matrix;

    void build_bb_matrix();

    void distances_with_others(const Place &place);
};

#endif //LOCATION_PROBLEM_STRATEGIES_H
