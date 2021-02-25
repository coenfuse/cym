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

    // Understand by this logic :
    // Given directions are, North -> East -> South -> West
    // Technically you are just outlining a square and your displacement is zero.
    // But previous logic just compares adjacent directions, not overall direction.
    // To actually give the most efficient path, one needs to count all the possib-
    // le directional pairs, eliminate them and just return the unpaired directions

    // Furthermore, The order of reduced directions doesn't matter because the res-
    // ultant vector and displacement will be the same. That is, both paths :
    // North -> East & East -> North will land you in the same place. North-East

    // Also, the analysis can be done on the stack itself, no need to create any
    // auxillary stack. Although it would lead to few more operations, it is space
    // efficient.

    static std::vector<std::string> LogicDirReduc(std::vector<std::string> &arr){

        short N_S_Disp = 0;      // North - South pair counter. +1 when North, -1 when South
        short W_E_Disp = 0;      // West - East pair counter. +1 when West, -1 when East

        for(std::string direction : arr){

            switch (direction[0])
            {
            case 'E':
            case 'e': --W_E_Disp;
                break;
            case 'W':
            case 'w': ++W_E_Disp;
                break;
            case 'N':
            case 'n': ++N_S_Disp;
                break;
            case 'S':
            case 's': --N_S_Disp;
            default:
                break;
            }

        }
        
        // If N_S_Disp is equals to :
        // 0 then, Resultant N_S movement is 0.
        // > 0 then, Resultant N_S movement is North.
        // < 0 then, Resultant N_S movement is South.

        // If W_E_Disp is equals to :
        // 0 then, Resultant W_E movement is 0.
        // > 0 then, Resultant W_E movement is West.
        // < 0 then, Resultant W_E movement is East.

        // Finally, the magnitude of both W_E_Disp & N_S_Disp can tell us the
        // final displacement of the path, and most efficient path to it.
        // Basically, with least number of steps.

        arr.clear();

        if(N_S_Disp != 0){

            if(N_S_Disp > 0)
                while(N_S_Disp != 0){
                    arr.push_back("NORTH");
                    N_S_Disp--;
                }
            else
                while(N_S_Disp != 0){
                    arr.push_back("SOUTH");
                    N_S_Disp++;
                }

        }

        if(W_E_Disp != 0){

            if(W_E_Disp > 0)
                while(W_E_Disp != 0){
                    arr.push_back("WEST");
                    W_E_Disp--;
                }
            else
                while (W_E_Disp != 0){
                    arr.push_back("EAST");
                    W_E_Disp++;
                }

        }

        return arr;
    }

};

// Just for local test purposes

int main(){

    std::vector<std::string> path = {"NORTH", "WEST", "SOUTH", "EAST"};
    DirReduction OBJ;

    std::vector<std::string> reduced_path = OBJ.dirReduc(path);         // Returns full path.
    std::vector<std::string> logical_path = OBJ.LogicDirReduc(path);    // Returns nothing.
    
    for(std::string direction : reduced_path)
        std::cout << direction << " -> ";
    std::cout << "END\n\n";

    for(std::string direction : logical_path)
        std::cout << direction << " -> ";
    std::cout << "END";

    return 0;
}