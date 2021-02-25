// A man was given directions to go from one point to another. The directions
// were "NORTH", "SOUTH", "WEST", "EAST". Clearly "NORTH" and "SOUTH" are oppo-
// site, "WEST" and "EAST" too.
// Going to one direction and coming back the opposite direction right away is
// a needless effort. Since this is the wild west, with dreadfull weather and
// not much water, it's important to save yourself some energy, otherwise you
// might die of thirst!
// How I crossed a mountainous desert the smart way.
// The directions given to the man are, for example, the following (depending
// on the language):
// [North, South, South, East, West, North, West]

// You can immediatly see that going "NORTH" and immediately "SOUTH" is not re-
// asonable, better stay to the same place! So the task is to give to the man a
// simplified version of the plan. A better plan in this case is simply:
// [West]

// Other examples:
// In ["NORTH", "SOUTH", "EAST", "WEST"], the direction "NORTH" + "SOUTH" is go-
// ing north and coming back right away.
// The path becomes ["EAST", "WEST"], now "EAST" and "WEST" annihilate each ot-
// her, therefore, the final result is [] (nil in Clojure).
// In ["NORTH", "EAST", "WEST", "SOUTH", "WEST", "WEST"], "NORTH" and "SOUTH"
// are not directly opposite but they become directly opposite after the reduc-
// tion of "EAST" and "WEST" so the whole path is reducible to ["WEST", "WEST"].

// Not all paths can be made simpler. The path ["NORTH", "WEST", "SOUTH", "EAST"]
// is not reducible. "NORTH" and "WEST", "WEST" and "SOUTH", "SOUTH" and "EAST"
// are not directly opposite of each other and can't become such. Hence the res-
// ult path is itself : ["NORTH", "WEST", "SOUTH", "EAST"].

// Write a function dirReduc which will take an array of strings and returns an
// array of strings with the needless directions removed (W<->E or S<->N side by
// side).

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>            // std::transform

// The following is the boilerplate code given in the question

class DirReduction
{
public:
    static std::vector<std::string> dirReduc(std::vector<std::string> &arr){

        std::vector<std::string> reduced_path_stack;
        std::string direction_complement;

        for(std::string direction : arr){

            std::transform(direction.begin(), direction.end(), direction.begin(), ::toupper);

            switch (direction[0])                               // Just comparing first character, reduces comparision time
            {
            case 'E': direction_complement = "WEST";
                break;
            case 'N': direction_complement = "SOUTH";
                break;
            case 'W': direction_complement = "EAST";
                break;
            case 'S': direction_complement = "NORTH";
                break;
            default:
                break;
            }

            // Stack is initially empty, so push the first direction.    
            if(reduced_path_stack.size() == 0){
                reduced_path_stack.push_back(direction);
                continue;
            }

            // Now we compare top of the stack with subsequent directions
            if(reduced_path_stack.back()[0] == direction_complement[0])     // Comparing just intial characters to reduce comparisions
                reduced_path_stack.pop_back();                              // If top matches with its complement, we pop
            else
                reduced_path_stack.push_back(direction);                    // Otherwise we push

        }

        return reduced_path_stack;
    }
};

// Just for local test purposes

int main(){

    std::vector<std::string> path = {"NORTH", "WEST", "SOUTH", "EAST"};
    DirReduction OBJ;

    std::vector<std::string> reduced_path = OBJ.dirReduc(path);     // Should return "west";
    
    for(std::string direction : reduced_path)
        std::cout << direction << " -> ";
    std::cout << "END";

    return 0;
}