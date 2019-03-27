cmake_minimum_required(VERSION 3.13)
project(Location_Problem)

set(CMAKE_CXX_STANDARD 17)

add_executable(Location_Problem main.cpp strategy/strategies.h strategy/exact_strategy.cpp strategy/approximate_strategy.cpp model/place.cpp model/truck.cpp utils/utils.h utils/location.cpp model/road.cpp model/headquater.cpp model/headquater.h model/place.h model/road.h model/truck.h model/map.cpp model/map.h utils/Parse.cpp utils/Parse.h)