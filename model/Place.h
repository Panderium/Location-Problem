//
// Created by panderium on 19-03-29.
//

#ifndef LOCATION_PROBLEM_PLACE_H
#define LOCATION_PROBLEM_PLACE_H

#include <string>
#include <math.h>

class Place {
public:

    Place() = default;

    Place(const std::string &m_name, int m_num_ville, float m_latitude, float m_longitude,
          char m_type, int m_besoin);

    float calculate_distance(Place place) const;


    const std::string &getM_name() const;

    void setM_name(const std::string &m_name);


    int getM_num_ville() const;

    void setM_num_ville(int m_num_ville);

    float getM_latitude() const;

    void setM_latitude(float m_latitude);

    float getM_longitude() const;

    void setM_longitude(float m_longitude);

    char getM_type() const;

    void setM_type(char m_type);

    int getM_besoin() const;

    void setM_besoin(int m_besoin);

    void print();

    bool operator==(const Place &rhs) const {
        return rhs.getM_num_ville() == getM_num_ville();
    }

private:
    std::string m_name;
    int m_num_ville;
    float m_latitude;
    float m_longitude;
    char m_type;
    int m_besoin;
};


#endif //LOCATION_PROBLEM_PLACE_H
