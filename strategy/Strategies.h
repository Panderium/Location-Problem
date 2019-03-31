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
    ApproximateStrategy();;

    int rand_a_b(int a, int b) {
        int n = rand() % (b - a) + a;
        return n;
    }

    void execute(std::vector<Place> places) override;

    float calc_f_obj(Solution sol);

    std::vector<Solution> generate_solutions(std::vector<Place> m);

    Solution tournoi(Solution s1, Solution s2);

    bool is_in(std::vector<int> tab, int e);

    Solution mutation(Solution s);

    Solution croisement(Solution s1, Solution s2);

    std::vector<Solution> selection_solutions(std::vector<Solution> parents, std::vector<Solution> enfants);



    const std::vector<Solution> &getPopulation() const;

    void setPopulation(const std::vector<Solution> &population);

//setters et getters
    float getP_mutation() const;

    void setP_mutation(float p_mutation);

    float getP_croissement() const;

    void setP_croissement(float p_croissement);

    int getNb_iteration() const;

    void setNb_iteration(int nb_iteration);

    int getNb_pop() const;

    void setNb_pop(int nb_pop);

    Solution get_place_by_indice(int ind);

private:
    std::vector<Solution> population;
    //Paramètres
    float p_mutation = 0.5;
    float p_croissement = 0.5;
    int nb_pop = 10;
    int nb_iteration = 100;
    Solution best;
public:
    const Solution &getBest() const;

    void setBest(const Solution &best);
};


class ExactStrategy : public Strategy {
public:
    ExactStrategy() : Strategy() {};

    void execute(std::vector<Place> places) override;

private:
    std::vector<std::vector<float> > m_matrix;

    std::vector<Node *> m_frontier;

    void build_bb_matrix(std::vector<Place> places);

    std::vector<Node *> init_frontier(std::vector<Place> places);


    int bb();

    bool one_left_places_is_not_empty();

    bool improve_bb(Node *pNode);
};

#endif //LOCATION_PROBLEM_STRATEGIES_H
