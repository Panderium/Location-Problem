cmake_minimum_required(VERSION 3.13)
project(Location_Problem)

set(CMAKE_CXX_STANDARD 17)

add_executable(Location_Problem main.cpp strategy/Strategies.h strategy/ApproximateStrategy.cpp strategy/ExactStrategy.cpp utils/Parse.h utils/Parse.cpp model/Map.cpp model/Map.h model/Place.cpp model/Place.h strategy/Node.cpp strategy/Node.h model/Solution.cpp model/Solution.h)