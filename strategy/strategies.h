//
// Created by panderium on 21/02/19.
//

#ifndef LOCATION_PROBLEM_STRATEGIES_H
#define LOCATION_PROBLEM_STRATEGIES_H


class strategy {
public:
    void execute();

private:
};

class approximate_strategy : strategy{
public:
    approximate_strategy();

    void execute();

    virtual ~approximate_strategy();

private:
};

class exact_strategy : strategy {
public:
    exact_strategy();

    void execute();

    virtual ~exact_strategy();

};

#endif //LOCATION_PROBLEM_STRATEGIES_H
