//
// Created by panderium on 19-03-29.
//
#include <algorithm>
#include <iostream>
#include "Strategies.h"

void ExactStrategy::execute(std::vector<Place> places) {

    m_frontier.resize(places.size());
    m_frontier = init_frontier(places);
    bb();
}


std::vector<Node *> ExactStrategy::init_frontier(std::vector<Place> places) {
    std::vector<Node *> nodes;

    for (Place place : places) {
        //new Place(place.getM_name(), place.getM_loc(), place.getM_num_ville(), place.getM_latitude(),place.getM_longitude(), place.getM_type(), place.getM_besoin())
        Node *node = new Node(place, places, 0);
        node->remove_delivered_place(place);
        nodes.push_back(node);
    }
    return nodes;
}

int ExactStrategy::bb() {
    float bestSolution = std::numeric_limits<float>::infinity();
    int idxBestSolution = 0;
    for (int i = 0; i < m_frontier.size(); ++i) {

        if (m_frontier[i]->computeSolution(bestSolution)) {
            bestSolution = m_frontier[i]->getM_cost();
            idxBestSolution = i;
        }
    }
    std::cout << "Le quartier où sera implémenté l'école est le quartier numéro : "
              << m_frontier[idxBestSolution]->getPlace().getM_num_ville() << std::endl;
    std::cout << "La valeur de la fonction objective est : " << m_frontier[idxBestSolution]->getM_cost() << std::endl;

    return idxBestSolution;
}