//
// Created by panderium on 19-03-29.
//

#ifndef LOCATION_PROBLEM_STRATEGIES_H
#define LOCATION_PROBLEM_STRATEGIES_H

#include <cstdlib>
#include <time.h>
#include <vector>
#include "../model/Place.h"
#include "../model/Solution.h"

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

    int rand_a_b(int a, int b){
        int n =rand()%(b-a)+a;
        return n;}

    float calc_f_obj(Solution sol);

    std::vector<Solution> generate_solutions(Map m);

    Solution mutation();

    Solution croisement();

    std::vector<Solution> selection_solutions(std::vector<Solution> population);

    void execute(std::vector<Solution> places) ;

    float getP_mutation() const;

    void setP_mutation(float p_mutation);

    float getP_croissement() const;

    void setP_croissement(float p_croissement);

    int getNb_pop() const;

    void setNb_pop(int nb_pop);

private:
    //Paramètres
    float p_mutation = 0.5;
    float p_croissement = 0.5;
    int nb_pop = 10;
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
