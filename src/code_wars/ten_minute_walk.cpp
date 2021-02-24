// You live in the city of Cartesia where all roads are laid out in a perfect 
// grid. You arrived ten minutes too early to an appointment, so you decided to
// take the opportunity to go for a short walk. The city provides its citizens 
// with a Walk Generating App on their phones -- everytime you press the button
// it sends you an array of one-letter strings representing directions to walk
// (eg. ['n', 's', 'w', 'e']). You always walk only a single block for each le-
// tter (direction) and you know it takes you one minute to traverse one city 
// block, so create a function that will return true if the walk the app gives
// you will take you exactly ten minutes (you don't want to be early or late!)
// and will, of course, return you to your starting point. Return false otherwise.

// What a stupid Walk Generating App that is. Pukes!

#include <iostream>
#include <vector>
#include <algorithm>

// The following is the boilerplate code given in the question

bool isValidWalk(std::vector<char> walk) {

    if(walk.size() == 10){                       // The path is only valid if it takes exactly 10 minutes

        // Transforming whole list into lowercase. Important before sorting. O(N)
        std::transform(walk.begin(), walk.end(), walk.begin(), ::tolower);

        // Scanning walk path for invalid directions. O(N)
        // Also scanning for balanced directions. O(N)
        // There should be equal number of East and West directions.
        // Similarly for North and South directions.

        // We increment N_S if 'n' direction is found and decrement if 's' is found.
        // We increment W_E if 'w' direction is found and decrement if 'e' is found
        int N_S = 0, W_E = 0;

        for(char direction : walk){
            switch (direction)
            {
            case 'n': ++N_S;
                break;
            case 's': --N_S;
                break;
            case 'w': ++W_E;
                break;
            case 'e': --W_E;
                break;
            default:
                return false;           // If control gets here, it means an invalid direction is encountered.
            }
        }

        // For balanced directions. Both directional pairs should be 0. Negating as required.
        return !(N_S && W_E);
    }
    return false;                       // Default return value
}

// Just for local test purposes

int main(){
    isValidWalk({'e','w','e','w','n','s','n','s','e','w'}) ? std::cout << "Valid Walk" : std::cout << "Invalid Walk";
    return 0;
}

// NOTE
// The program can be executed in lower space complexity using less variables
// and small data types. But that was affecting the readability of the code.
// So I kept it this way.