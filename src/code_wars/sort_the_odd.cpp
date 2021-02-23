// You will be given an array of numbers. You have to sort the odd numbers in
// ascending order while leaving the even numbers at their original positions.
// For example : [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]  =>  [1, 8, 3, 6, 5, 4, 7, 2, 9, 0]

#include <iostream>                 // Basic I/O
#include <vector>                   // Data Containers
#include <algorithm>                // For Sorting

// The following is the boilerplate code given in the question

class Kata
{
public:
    std::vector<int> sortArray(std::vector<int> array)
    {
        std::vector<size_t> odd_index;
        std::vector<int> odd_values;
        
        size_t index = 0;

        for(auto each : array){                     // Scanning for odd values
            if(each % 2 != 0){
                odd_index.push_back(index);         // Adding the indexes
                odd_values.push_back(each);         // Adding the odd values. Trivial, will remove.
                index++;                            // Updating index
            }
            else{
                index++;                            // Just skip the index
            }
        }

        std::sort(odd_values.begin(), odd_values.end());    // Sorting the odd values. In place.
        index = 0;                                  // Resetting the counter

        for(auto each : odd_index){
            array[each] = odd_values[index];         // Emplacing the values from sorted vector into required array
            index++;                                 //Updating index
        }

        return array;
    }
};

// Just for local test purposes

int main(){

    Kata OBJ;
    std::vector<int> sorted_array = OBJ.sortArray({9, 8, 7, 6, 5, 4, 3, 2, 1, 0});

    for(auto each : sorted_array)
        std::cout << each << ", ";

    return 0;
}