// You get an array of numbers, return the sum of all of the positives ones.
// Example [1,-4,7,12] => 1 + 7 + 12 = 20
// Note: if there is nothing to sum, the sum is default to 0.

#include <iostream>
#include <vector>

// The following is the boilerplate code given in the question

int positive_sum (const std::vector<int> arr){
    int sum = 0;
    for(int value : arr){
        if(value >= 0)
            sum += value;
    }
    return sum;
}

// Just for local test purposes

int main(){
    std::cout << positive_sum({-1,2,3,4,-5});    // Should return : 9
    return 0;
}