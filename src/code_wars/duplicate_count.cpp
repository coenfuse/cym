// Write a function that will return the count of distinct case-insensitive al-
// phabetic characters and numeric digits that occur more than once in the inp-
// ut string. The input string can be assumed to contain only alphabets (both
// uppercase and lowercase) and numeric digits.

// For example
// "abcde" -> 0 # no characters repeats more than once
// "aabbcde" -> 2 # 'a' and 'b'
// "aabBcde" -> 2 # 'a' occurs twice and 'b' twice (`b` and `B`)
// "indivisibility" -> 1 # 'i' occurs six times

#include <string>
#include <algorithm>
#include <iostream>
#include <map>

// The following is the boilerplate code given in the question

size_t duplicateCount(const std::string& in); // helper for tests

size_t duplicateCount(const char* in)
{   
    // Implicit conversion to string and then lowercasing it. O(N)
    std::string aux_str = in;
    std::transform(aux_str.begin(), aux_str.end(), aux_str.begin(), ::tolower);
    
    // This map will contain ( character, frequency ) pair
    std::map<char, unsigned int> counter;              

    for(char character : aux_str){

            // If character in consideration is not found. Add it to the map with frequency 1.
            if(counter.find(character) == counter.end()){
                counter.insert(std::pair<char, unsigned int>(character, 1));
            }

            // Or else it means, there exists a copy of character in map already. Thus, increment its frequency by 1.
            else{
                ++counter[character];
            }
    }

    size_t duplicates_present = 0;      // This will count duplicates.

    for(auto pair : counter){           // Run for every pair of counter. O(N)
        if(pair.second > 1)             // Basically, if an character has of freq greater than 1, then it's a duplicate.
            duplicates_present++;
    }

    return duplicates_present;
}

// Just for local test purposes

int main(){
    std::cout << duplicateCount("Indivisibilities");
    return 0;
}

// BETTER SOLUTION
/*

std::size_t duplicateCount(const char* in) {
  std::unordered_map<char, unsigned> counts;
  for (const char* c = in; *c != '\0'; ++c) {
    ++counts[tolower(*c)];
  }
  return std::count_if(cbegin(counts), cend(counts), [](const auto& count) {
      return count.second > 1;
    });
}

*/