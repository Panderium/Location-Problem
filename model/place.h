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
    std::string get_type();
    int get_besoin();

    void set_latitude(float lat);
    void set_longitude(float lon);
    void set_num_ville(int num);
    void set_type(std::string type);
    void set_besoin(int bes);

private:
    std::string name;
    location loc;
    int num_ville;
    float latitude;
    float longitude;
    std::string type;
    int besoin;


};

#endif //LOCATION_PROBLEM_PLACE_H
