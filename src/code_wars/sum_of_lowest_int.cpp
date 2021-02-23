// Create a function that returns the sum of the two lowest positive numbers g-
// iven an array of minimum 4 positive integers. No floats or non-positive int-
// egers will be passed.
// For example, when an array is passed like [19, 5, 42, 2, 77], the output sh-
// ould be 7.
// Array [10, 343445353, 3453445, 3453545353453] should return 3453455.

#include <iostream>
#include <algorithm>
#include <vector>

// The following is the boilerplate code given in the question

long sumTwoSmallestNumbers(std::vector<int> numbers)
{
    std::sort(numbers.begin(), numbers.end());
    return (numbers[0] + numbers[1]);
}

// Just for local test purposes

int main(){
    std::cout << sumTwoSmallestNumbers({5, 8, 12, 19, 22});    // Returns 13
    return 0;
}