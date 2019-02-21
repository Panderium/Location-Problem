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

private:
    std::string name;
    location loc;
};

#endif //LOCATION_PROBLEM_PLACE_H
