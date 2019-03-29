//
// Created by panderium on 19-03-29.
//

#ifndef LOCATION_PROBLEM_STRATEGIES_H
#define LOCATION_PROBLEM_STRATEGIES_H


#include <vector>
#include "../model/Place.h"
#include "Node.h"

class Strategy {
public:
    Strategy() {};

    virtual void execute(std::vector<Place> places) = 0;

    virtual ~Strategy() {};

protected:
};

class ApproximateStrategy : public Strategy {
public:
    ApproximateStrategy() : Strategy() {};

    void execute(std::vector<Place> places) override;

private:
};


class ExactStrategy : public Strategy {
public:
    ExactStrategy() : Strategy() {};

    void execute(std::vector<Place> places) override;

private:
    std::vector<std::vector<float>> m_matrix;

    void build_bb_matrix(std::vector<Place> places);

    std::vector<Node *> init_frontier(std::vector<Place> places);

    void branch();

    void bound();
};

#endif //LOCATION_PROBLEM_STRATEGIES_H
