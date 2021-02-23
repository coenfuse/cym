// An anagram is the result of rearranging the letters of a word to produce a new word (see wikipedia).
// Note: anagrams are case insensitive
// Complete the function to return true if the two arguments given are anagrams of each other; return false otherwise.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// The following is the boilerplate code given in the question

bool isAnagram(std::string test, std::string original){
  
    if(test.length() == original.length()){             // If the strings aren't equal in length, then they are definitely not an Anagram.

        // Converting whole string into lowercase. O(N). Important.

        for(size_t index = 0; index < test.length(); index++){
            test[index] = std::tolower(test[index]);
            original[index] = std::tolower(original[index]);
        }

        // Alternative Code
        // std::transform(original.begin(), orignal.end(), original.begin(), ::to_lower);
        // std::transform(test.begin(), test.end(), test.end(), ::to_lower);

        // Sorting the strings to reduce look-up times later. O(logN)

        std::sort(test.begin(), test.end());
        std::sort(original.begin(), original.end());

        return original == test;                    // It compares both strings iteratively.
    }
    return false;                                   // Default return value.
}

// Just for local test purposes

int main(){
    if(isAnagram("Twoo", "WooT"))
        std::cout << "It is an Anagram";
    else
        std::cout << "It is not an Anagram";
    return 0;
}