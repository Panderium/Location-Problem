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
Solution ApproximateStrategy::tournoi(Solution s1, Solution s2) {
    if(calc_f_obj(s1)<calc_f_obj(s2)){
        return s1;
    }else{
        return s2;
    }
}
Solution ApproximateStrategy::croisement(Solution parent1, Solution parent2) {
    Solution res;
    std::vector<int> masque;
    int i = rand_a_b(1,parent1.getPlaces().size()-1);
    std::vector<Place> pl;
    for(int j=0; j<i; j++) {
        int n =rand_a_b(0, parent1.getPlaces().size());
        if (is_in(masque,n)){
            masque.push_back(n);
        }
    }
    for(int j=0; j < masque.size(); j++) {
        pl.push_back(parent1.get_place_by_indice(masque[j]));
    }
    //TODO remplir avec le parent2
    /**for(int i=0; i< parent2.getPlaces().size();i++){
    }**/
    //TODO trouver la ville manquante
    //TODO calc distance
        res.setPlaces(pl);
        return res;
}

//getters et setters
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
int ApproximateStrategy::getNb_iteration() const {
    return nb_iteration;
}
void ApproximateStrategy::setNb_iteration(int nb_iteration) {
    ApproximateStrategy::nb_iteration = nb_iteration;
}

bool ApproximateStrategy::is_in(std::vector<int> tab, int e) {
    for(int i=0; i<tab.size();i++){
        if(tab[i]==e){
            return true;
        }
    }
    return false;
}
