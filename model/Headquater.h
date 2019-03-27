//
// Created by panderium on 21/02/19.
//

#ifndef LOCATION_PROBLEM_HEADQUATER_H
#define LOCATION_PROBLEM_HEADQUATER_H


#include <string>
#include "../utils/location.h"

class Headquater {
public:
    Headquater();

    Headquater(std::string name);

    ~Headquater();

    location getLocation();

    void setLocation(location loc);

private:
    std::string name;
    location loc;
};

#endif //LOCATION_PROBLEM_HEADQUATER_H
