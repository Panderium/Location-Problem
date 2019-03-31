//
// Created by panderium on 19-03-29.
//
#include "../model/Place.h"
#include "Strategies.h"
#include <iostream>


void ApproximateStrategy::execute(std::vector<Place> places) {
    srand(time(NULL));
    setPopulation(generate_solutions(places));
    for(int ite = 0;ite < getNb_iteration();ite++) {
        std::vector<Solution> enfants;
        for (int i = 0; i < getNb_pop(); i++) {
            int k = rand_a_b(0, getNb_pop() - 1);
            int j = rand_a_b(0, getNb_pop() - 1);
            enfants.push_back(croisement(getPopulation()[k], getPopulation()[j]));
        }
        setPopulation(selection_solutions(enfants, getPopulation()));
    }

}

float ApproximateStrategy::calc_f_obj(Solution sol) {
    float f_obj = 0;
    for (int i = 0; i < sol.getDistance().size(); i++) {
        f_obj += sol.get_dist_by_indice(i);
    }
    return f_obj;
}

std::vector<Solution> ApproximateStrategy::generate_solutions(std::vector<Place> m) {
    Solution tamp;
    tamp.setPlaces(m);
    for (int i = 0; i < getNb_pop(); i++) {
        Solution sol;
        std::vector<Place> pla;
        int ind = rand_a_b(0, tamp.getPlaces().size());
        sol.setSolution(tamp.get_place_by_indice(ind));
        pla = tamp.getPlaces();
        sol.setPlaces(tamp.supp_place(sol.getSolution()));
        for (int j = 0; j < sol.getPlaces().size(); i++) {
            sol.add_distance(sol.getSolution().calculate_distance(sol.get_place_by_indice(j)));
        }
    }
    return std::vector<Solution>();
}

Solution ApproximateStrategy::tournoi(Solution s1, Solution s2) {
    if (calc_f_obj(s1) < calc_f_obj(s2)) {
        if(calc_f_obj(s1)<calc_f_obj(getBest())) {
            setBest(s1);
        }
        return s1;
    } else {
        if(calc_f_obj(s2)<calc_f_obj(getBest())) {
            setBest(s2);
        }
        return s2;
    }
}

Solution ApproximateStrategy::croisement(Solution parent1, Solution parent2) {
    Solution res;
    std::vector<int> masque;
    int i = rand_a_b(1, parent1.getPlaces().size() - 1);
    std::vector<Place> pl;
    if (parent1.getSolution() == parent2.getSolution()) {
        return parent1;
    } else {
        for (int j = 0; j < i; j++) {
            int n = rand_a_b(0, parent1.getPlaces().size());
            if (is_in(masque, n)) {
                masque.push_back(n);
            }
        }
        for (int j = 0; j < masque.size(); j++) {
            pl.push_back(parent1.get_place_by_indice(masque[j]));
        }
        //TODO remplir avec le parent2
        int taille = parent2.getPlaces().size() - masque.size() + 1;
        for (int i = 0; i < taille; i++) {
            if (res.is_in(pl, parent2.get_place_by_indice(i))) {
                taille = taille + 1;
            } else {
                pl.push_back(parent2.get_place_by_indice(i));
            }
        }
        //trouver la ville manquante
        for (int i = taille; i < parent2.getPlaces().size(); i++) {
            if (!res.is_in(res.getPlaces(), parent2.get_place_by_indice(i))) {
                res.setSolution(parent2.get_place_by_indice(i));
            }
        }
        bool test = res.is_in(res.getPlaces(), res.getSolution());
        res.setPlaces(pl);
        // calcul de la distance
        for (int j = 0; j < res.getPlaces().size(); i++) {
            res.add_distance(res.getSolution().calculate_distance(res.get_place_by_indice(j)));
        }
        if (test) {
            std::cout << "erreur dans le croisement" << std::endl;
        }
        return res;

    }
}

std::vector<Solution> ApproximateStrategy::selection_solutions(std::vector<Solution> parents, std::vector<Solution> enfants) {
    std::vector<Solution> new_pop;
    for (int i = 0; i < getNb_pop(); i++) {
        //tournoi(enfant, enfant);
        new_pop.push_back(tournoi(enfants[i], enfants[i + 1]));
        //tournoi(parent, parent);
        new_pop.push_back(tournoi(parents[i], parents[i + 1]));
        //add in new_pop;
        i = i + 2;
    }
    return new_pop;
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

bool ApproximateStrategy::is_in(std::vector<int> tab, int e) {
    for (int i = 0; i < tab.size(); i++) {
        if (tab[i] == e) {
            return true;
        }
    }
    return false;
}

int ApproximateStrategy::getNb_iteration() const {
    return nb_iteration;
}

void ApproximateStrategy::setNb_iteration(int nb_iteration) {
    ApproximateStrategy::nb_iteration = nb_iteration;
}

const std::vector<Solution> &ApproximateStrategy::getPopulation() const {
    return population;
}

void ApproximateStrategy::setPopulation(const std::vector<Solution> &population) {
    ApproximateStrategy::population = population;
}

Solution ApproximateStrategy::get_place_by_indice(int ind) {
    std::vector<Solution> sol = getPopulation();
    return sol[ind];
}

ApproximateStrategy::ApproximateStrategy() : Strategy() {}

const Solution &ApproximateStrategy::getBest() const {
    return best;
}

void ApproximateStrategy::setBest(const Solution &best) {
    ApproximateStrategy::best = best;
}



