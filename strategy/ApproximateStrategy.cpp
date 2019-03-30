//
// Created by panderium on 19-03-29.
//
#include "../model/Place.h"
#include "Strategies.h"
void ApproximateStrategy::execute(std::vector<Solution> places) {
}

float ApproximateStrategy::calc_f_obj( Solution sol) {
    float f_obj = 0;
    for(int i =0; i< sol.get_distance.size(); i++){
        f_obj += pl.calculate_distance(sol[i]);
    }
    return f_obj;
}
