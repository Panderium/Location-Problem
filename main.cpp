#include <iostream>
#include "strategy/Strategies.h"
#include "utils/Parse.h"

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
    ifstream fichier("C:/Users/camil/Documents/Polytech/UQAC/trimestre 2/Algorithmique/Location-Problem/data.txt");
    Map m;
    Place p;
    if(fichier){
        Place ville;
        string ligne;
        int num;
        float f;
        getline(fichier, ligne);
        while(getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
        {//getline(fichier, ligne);
            int z = ligne.find(',');
            int i = z;
            string tamp = ligne.substr(0, z);
            num = std::stoi(tamp);
            ville.setM_num_ville(num);

            z = ligne.find(',',i+1);
            tamp = ligne.substr(i+1, z);
            f = std::stof(tamp);
            ville.setM_latitude(f);

            i = z;
            z = ligne.find(',',i+1);
            tamp = ligne.substr(i+1, z);
            f = std::stof(tamp);
            ville.setM_longitude(f);

            i = z;
            i = ligne.find('dp,',i+1);
            tamp =ligne.substr(i+1,ligne.length()-1);
            num = std::stoi(tamp);
            ville.setM_besoin(num);
            m.add_place(ville);
        }
    fichier.close();
    }
    else
        cerr << "Impossible d'ouvrir le fichier !" << endl;

    //methode exact
    m.set_strategy(new ExactStrategy());
    m.apply_methode();

    //methode approché
    m.set_strategy(new ApproximateStrategy());
    m.apply_methode();
    // p.Parser();

    return 0;
}
