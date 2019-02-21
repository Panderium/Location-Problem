//
// Created by panderium on 21/02/19.
//

#ifndef LOCATION_PROBLEM_HEADQUATER_H
#define LOCATION_PROBLEM_HEADQUATER_H


#include <string>
#include "../utils/utils.h"

class headquater {
public:
    headquater();

    headquater(std::string name);

    ~headquater();

    location getLocation();

    void setLocation(location loc);

private:
    std::string name;
    location loc;
};

#endif //LOCATION_PROBLEM_HEADQUATER_H
