//
// Created by panderium on 19-03-29.
//
#include "../model/Place.h"
#include "Strategies.h"


void ApproximateStrategy::execute(std::vector<Solution> places) {
}

float ApproximateStrategy::calc_f_obj(Solution sol) {
    float f_obj = 0;
    for(int i =0; i< sol.getDistance().size(); i++){
        f_obj += sol.get_dist_by_indice(i);
    }
    return f_obj;
}

std::vector<Solution> ApproximateStrategy::generate_solutions(Map m) {
    for (int i=0; i< getNb_pop(); i++) {
        Solution sol;
        std::vector<Place> pla;
        int ind = rand_a_b(0, m.getM_places().size());
        sol.setSolution(m.get_place_by_indice(ind));
        pla = m.getM_places();
        sol.setPlaces(m.supp_place(sol.getSolution()));
        for(int j=0; j< sol.getPlaces().size();i++){
            sol.add_distance(sol.getSolution().calculate_distance(sol.get_place_by_indice(j)));
        }
    }
    return std::vector<Solution>();
}

float ApproximateStrategy::getP_mutation() const {
    return p_mutation;
}

void ApproximateStrategy::setP_mutation(float p_mutation) {
    ApproximateStrategy::p_mutation = p_mutation;
}

float ApproximateStrategy::getP_croissement() const {
    return p_croissement;
}

void ApproximateStrategy::setP_croissement(float p_croissement) {
    ApproximateStrategy::p_croissement = p_croissement;
}

int ApproximateStrategy::getNb_pop() const {
    return nb_pop;
}

void ApproximateStrategy::setNb_pop(int nb_pop) {
    ApproximateStrategy::nb_pop = nb_pop;
}
