//
// Created by panderium on 21/02/19.
//

#ifndef LOCATION_PROBLEM_PLACE_H
#define LOCATION_PROBLEM_PLACE_H

#include <string>
#include "../utils/location.h"

class Place {
public:
    Place();

    Place(std::string name, location loc);

    float calculate_distance(Place place);

    const std::string &getM_name() const;

    const location &getM_loc() const;

    int getM_num_ville() const;

    float getM_latitude() const;

    float getM_longitude() const;

    char getM_type() const;

    int getM_besoin() const;

    void setM_name(const std::string &m_name);

    void setM_loc(const location &m_loc);

    void setM_num_ville(int m_num_ville);

    void setM_latitude(float m_latitude);

    void setM_longitude(float m_longitude);

    void setM_type(char m_type);

    void setM_besoin(int m_besoin);

    ~Place();

private:
    std::string m_name;
    location m_loc;
    int m_num_ville;
    float m_latitude;
    float m_longitude;
    char m_type;
    int m_besoin;


};

#endif //LOCATION_PROBLEM_PLACE_H
