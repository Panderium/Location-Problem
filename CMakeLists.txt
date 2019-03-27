cmake_minimum_required(VERSION 3.13)
project(Location_Problem)

set(CMAKE_CXX_STANDARD 17)

add_executable(Location_Problem main.cpp strategy/Strategies.h strategy/ExactStrategy.cpp strategy/ApproximateStrategy.cpp model/Place.cpp model/truck.cpp utils/location.h utils/location.cpp model/Headquater.cpp model/Headquater.h model/Place.h model/truck.h model/Map.cpp model/Map.h utils/Parse.cpp utils/Parse.h)