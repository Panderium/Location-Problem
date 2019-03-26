//
// Created by panderium on 21/02/19.
//

#ifndef LOCATION_PROBLEM_PLACE_H
#define LOCATION_PROBLEM_PLACE_H

#include <string>
#include "../utils/utils.h"

class place {
public:
    place();

    place(std::string name, location loc);

    ~place();

    std::string getName();

    location getLocation();
    float get_latitude();
    float get_longitude();
    int get_num_ville();
    char get_type();
    int get_besoin();


private:
    std::string name;
    location loc;
    int num_ville;
    float latitude;
    float longitude;
    char type;
    int besoin;


};

#endif //LOCATION_PROBLEM_PLACE_H
