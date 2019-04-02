#include <iostream>
#include "strategy/Strategies.h"
#include "utils/Parse.h"

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Utilisation du programme : " << argv[0] << " <dataset>" << std::endl;
        return 1;
    }
    std::cout << argv[1] << std::endl;
    ifstream fichier(argv[1]);
    Map m;
    Place p;
    if (fichier) {
        Place ville;
        string ligne;
        int num;
        float f;
        getline(fichier, ligne);
        while (getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
        {//getline(fichier, ligne);
            int z = ligne.find(',');
            int i = z;
            string tamp = ligne.substr(0, z);
            num = std::stoi(tamp);
            ville.setM_num_ville(num);

            z = ligne.find(',', i + 1);
            tamp = ligne.substr(i + 1, z);
            f = std::stof(tamp);
            ville.setM_latitude(f);

            i = z;
            z = ligne.find(',', i + 1);
            tamp = ligne.substr(i + 1, z);
            f = std::stof(tamp);
            ville.setM_longitude(f);

            i = z;
            i = ligne.find(',', i + 3);
            tamp = ligne.substr(i + 1, ligne.length() - 1);
            num = std::stoi(tamp);
            ville.setM_besoin(num);
            m.add_place(ville);
        }
        fichier.close();
    } else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    auto places = m.getM_places();
    /* for (Place place : places)
         place.print();*/
    std::cout << "Choix de la méthode : e - Exacte, a - Approchée" << std::endl;
    char input;
    cin >> input;
    if (input == 'e') {
        m.setM_strategy(new ExactStrategy());
        std::cout << "Déroulement de la méthode exacte..." << std::endl;
    } else {
        m.setM_strategy(new ApproximateStrategy());
        std::cout << "Déroulement de la méthode approchée..." << std::endl;
    }

    m.execut_strategy();

    return 0;
}
