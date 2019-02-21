//
// Created by panderium on 21/02/19.
//

#ifndef LOCATION_PROBLEM_TRUCK_H
#define LOCATION_PROBLEM_TRUCK_H

class truck {
public:
    truck();

    ~truck();

    int load(int quantity);

    int unload(int quantity);


private:
    int payload;
    const int max_payload = 50;
};

#endif //LOCATION_PROBLEM_TRUCK_H
