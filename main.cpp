#include <iostream>
#include "strategy/Strategies.h"
#include "utils/Parse.h"



int main() {
    Parse p;
    Map m;
    m = p.Parser();
    //methode exact
    m.set_strategy(new ExactStrategy());
    m.apply_methode();

    //methode approché
    m.set_strategy(new ApproximateStrategy());
    m.apply_methode();
   // p.Parser();
    return 0;
}