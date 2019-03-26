//
// Created by camil on 26/03/2019.
//

#include "Parse.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
Parse::Parse(int argc, char **argv){
    ifstream fichier("data.txt");

    if(fichier, ios::in)
    {
        place ville;
        string s;
        while(getline(fichier,s)){
            int i = 0;
            int z = s.find(',');
            string tamp = s.substr(0, z);
            //faire les sets
            //ville.set_num_ville(tamp);
            i = z;
            vector<string> tampon;
            while(i < s.length()) { // boucle jusqu'Ã  la fin de la ligne
                z = s.find(',',i);
                if( z >= s.length())
                { // pas de vigule trouvee, on en est donc au dernier élement
                    tamp =(s.substr(i,s.length()-1-i));
                    //faire les sets
                    //ville.set_besoin(tamp);
                    break;
                }
                else
                { // il y a plusieurs effets secondaires Ã  traiter encore
                    tampon.push_back(s.substr(i, z));
                    //cout << effects[i] << endl;
                    i = z;    // on fait avancer i de la taille de la chaine + l'espace et la virgule
                }

            }
       // ville.set_latitude(tampon[0]);
       //ville.set_longitude(tampon[0]);

        }
    //data.places.push_back(ville);
    }
    fichier.close();

}