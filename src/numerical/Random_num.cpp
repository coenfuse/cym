// Generates n distinct random number within given limit.
// Generated numbers together give the sum equal to upper limit of the condition.

#include <iostream>
#include <algorithm>        // std::find
#include <vector>
#include <ctime>

std::vector<int> foo(int upper_limit, int numbers){

    std::vector<int> memo;

    while(numbers > 0){                                         // Recursion Controller

        srand((unsigned int)time(NULL));                    // Random seed
        int guess = 0;
    
        while(true){
            guess = rand() % upper_limit;
            if (guess <= 1) continue;
            if(std::find(memo.begin(), memo.end(), guess) != memo.end())
                continue;                                        // Already guessed, guess again
            else{
                memo.push_back(guess);
                break;
            }
        }

        upper_limit -= guess;                          // New Upper limit
        if (upper_limit <= 2) break;
        numbers--;
    }

    return memo;

}

int main(){
    std::cout << "Running" <<std::endl;
    std::vector<int> test;

    test = foo(100, 10);
    int sum = 0;

    for(auto each : test){
        std::cout << each << ", ";
        sum += each;
    }
    std::cout << "\nSum : "<< sum << std::endl;
}