// There is a bus moving in the city, and it takes and drop some people in each
// bus stop. You are provided with a list (or array) of integer arrays (or tup-
// les). Each integer array has two items which represent number of people get
// into bus (The first item) and number of people get off the bus (The second 
// item) in a bus stop. Your task is to return number of people who are still 
// in the bus after the last bus station (after the last array). Even though it
// is the last bus stop, the bus is not empty and some people are still in the
// bus, and they are probably sleeping there. Please keep in mind that the test
// cases ensure that the number of people in the bus is always >= 0. So the re-
// turn integer can't be negative. The second value in the first integer array
// is 0, since the bus is empty in the first bus stop.

#include <iostream>
#include <utility>
#include <vector>

// The following is the boilerplate code given in the question

unsigned int number(const std::vector<std::pair<int, int>>& busStops){

    unsigned int in_bus = 0;            // People in bus at starting

    for(auto pair : busStops){
        in_bus += pair.first;           // People who got in
        in_bus -= pair.second;          // People who got off
    }

    return in_bus;
  
}

// Just for local test purposes

int main(){
    
    unsigned int people_in_bus = number( { {3,0}, {9,1}, {4,8}, {12,2}, {6,1}, {7,8} } );   // Should be 21
    std::cout << people_in_bus << std::endl;
    return 0;

}