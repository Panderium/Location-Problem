//
// Created by camil on 26/03/2019.
//

#include "Parse.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
Map Parse::Parser(){
    Map data;
    ifstream fichier("C:/Users/camil/Documents/Polytech/UQAC/trimestre 2/Algorithmique/Location-Problem/data.txt");

    if(fichier, ios::in)
    {
        Place ville;
        string s;
        while(getline(fichier,s)){
            int i = 0;
            int z = s.find(',');
            string tamp = s.substr(0, z);
            //faire les sets
            ville.set_num_ville(std::stoi(tamp));
            i = z;
            vector<string> tampon;
            while(i < s.length()) { // boucle jusqu'Ã  la fin de la ligne
                z = s.find(',',i);
                if( z >= s.length())
                { // pas de vigule trouvee, on en est donc au dernier élement
                    tamp =(s.substr(i,s.length()-1-i));
                    //faire les sets
                    ville.set_besoin(std::stoi(tamp));
                    i = s.length();
                    break;
                }
                else
                { // il y a plusieurs effets secondaires Ã  traiter encore
                    tampon.push_back(s.substr(i, z));
                    i = z;    // on fait avancer i de la taille de la chaine + l'espace et la virgule
                }

            }
        ville.set_latitude(std::strtof(tampon[0].c_str(),0));
        ville.set_longitude(std::strtof(tampon[1].c_str(),0));
            cout << ville.get_num_ville() << endl;
            //cout << effects[i] << endl;
            //cout << effects[i] << endl;
        tampon.clear();
        }
    data.add_place(ville);
    }
    fichier.close();
    return data;
}