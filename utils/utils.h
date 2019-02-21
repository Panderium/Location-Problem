//
// Created by panderium on 21/02/19.
//

#ifndef LOCATION_PROBLEM_UTILS_H
#define LOCATION_PROBLEM_UTILS_H


class location {
public:
    location();

    location(int x, int y);

    ~location();

    int getX();

    int getY();

    void setX(int x);

    void setY(int y);

private:
    int x;
    int y;
};

#endif //LOCATION_PROBLEM_UTILS_H
