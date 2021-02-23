// Complete the square sum function so that it squares each number passed into
// it and then sums the results together.
// For example, for [1, 2, 2] it should return 9 because 1^2 + 2^2 + 2^2 = 9.

#include <vector>
#include <iostream>

// The following is the boilerplate code given in the question

int square_sum(const std::vector<int>& numbers)
{   
    int sum = 0;
    for(int value : numbers)
        sum += value * value;
    return sum;
}

// Just for local test purposes

int main(){
    std::cout << square_sum({1,2,3,4,5,6,7,8,9,10});    // Should return : 385
    return 0;
}