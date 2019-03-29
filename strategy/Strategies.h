//
// Created by panderium on 21/02/19.
//

#ifndef LOCATION_PROBLEM_STRATEGIES_H
#define LOCATION_PROBLEM_STRATEGIES_H

#include <iostream>
#include "../model/Map.h"
#include "Node.h"
class Strategy {
public:
    Strategy() { m_places = m_map.getM_places() ;};

    virtual void execute(Map map) {
        m_map = map;
    };

protected:
    std::vector<Place> m_places;
    Map m_map;
};

class ApproximateStrategy : public Strategy {
public:
    ApproximateStrategy();

    void execute(Map *map) ;

private:


};

class ExactStrategy : public Strategy {
public:
    ExactStrategy();

    void execute(Map &map) ;


private:
    std::vector<std::vector<float>> m_matrix;

    void build_bb_matrix();

    std::vector<Node*> init_frontier();

    void branch();

    void bound();
};

#endif //LOCATION_PROBLEM_STRATEGIES_H
