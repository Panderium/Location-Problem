//
// Created by panderium on 21/02/19.
//

#ifndef LOCATION_PROBLEM_TRUCK_H
#define LOCATION_PROBLEM_TRUCK_H

class Truck {
public:
    Truck();

    ~Truck();

    int load(int quantity);

    int unload(int quantity);

    float getM_autonomy() const;

    void setM_autonomy(float m_autonomy);

private:
    int m_payload;
    const int m_max_payload = 50;
    float m_autonomy;
};

#endif //LOCATION_PROBLEM_TRUCK_H
