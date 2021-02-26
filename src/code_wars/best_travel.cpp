// John and Mary want to travel between a few towns A, B, C ... Mary has on a
// sheet of paper a list of distances between these towns. ls = [50, 55, 57, 58, 60].
// John is tired of driving and he says to Mary that he doesn't want to drive
// more than t = 174 miles and he will visit only 3 towns.
// Which distances, hence which towns, they will choose so that the sum of the
// distances is the biggest possible to please Mary and John?

// Example:
// With list ls and 3 towns to visit they can make a choice between:
// [50,55,57],[50,55,58],[50,55,60],[50,57,58],[50,57,60],[50,58,60],[55,57,58],
// [55,57,60],[55,58,60],[57,58,60].

// The sums of distances are then: 162, 163, 165, 165, 167, 168, 170, 172, 173, 175.
// The biggest possible sum taking a limit of 174 into account is then 173 and
// the distances of the 3 corresponding towns is [55, 58, 60].

// The function chooseBestSum will take as parameters t
// (maximum sum of distances, integer >= 0),
// k (number of towns to visit, k >= 1) and ls (list of distances, all distances
// are positive or null integers and this list has at least one element).
// The function returns the "best" sum ie the biggest possible sum of k distances
// less than or equal to the given limit t, if that sum exists, or otherwise
// nil, null, None, Nothing, depending on the language.

// With C++, C, Rust, Swift, Go, Kotlin, Dart return -1.

#include <iostream>
#include <vector>
#include <functional>           // std::greater
#include <algorithm>            // std::sort
#include <map>                  

// Boilerplate code given in the question

class BestTravel
{
public:
    static int chooseBestSum(int t, int k, std::vector<int>& ls){

        // This one uses Greedy Approach. It doesn't give overall best solution.

        #define max_distance t
        #define max_cities k
        #define list ls

        if(max_distance >= 0 && max_cities >= 1){

            std::sort(list.begin(), list.end(), std::greater<int>());    // Sorting in descending
            int distance_sum = 0;
            int city_count = 0;

            for(int each : list){
                if(city_count < max_cities){
                    distance_sum += each;
                    if(distance_sum > max_distance){
                        distance_sum -= each;
                        continue;
                    }
                    else
                        city_count++;
                }
                else
                    break;
            }

            return distance_sum;

        }

        return -1;
    }

    static int chooseBestSumDynamic(int t, int k, std::vector<int>& ls){

        // This one will use dynamic programming. It gives overall best result.

        #define max_distance t;
        #define max_cities k
        #define dist_list ls

        std::map< int, std::vector<int> > combinations;

        // If combination size is 3 and combination pool is A,B,C,D then,
        // The possible combinations of max_size = pool.size() are :

        // A,B,C,D,                     (4^1 = 4 pairs of Length 1)
        // AA,AB,AC,AD,                 (4^2 = 16 pairs of Length 1)
        // BA,BB,BC,BD,
        // CA,CB,CC,CD,
        // DA,DB,DC,DD,
        // AAA,AAB,AAC,AAD,             (4^3 = 64 pairs of Length 3)
        // ABA,ABB,ABC,ABD,
        // ACA,ACB,ACC,ACD,
        // ADA,ADB,ADC,ADD,
        // BAA,BAB,BAC,BAD
        // ...
        // AAAA,AAAB,AAAC,AAAD,         (4^4 = 256 pairs of Length 4)
        // AABA,AABB,AABC,AABD,
        // ...
        // DDDA,DDDB,DDDC,DDDD
        
        // Total pairs (here) = 256 + 64 + 16 + 4 = 340
        // In our case, we need a set of unique combinations of size = 3.
        // From above, we can see the pattern. 4^3 combination group is our
        // domain. So a general case would be:
        // pool.size() ^ required_combination_length.

        // In terms of the problem, it would be:
        // list.size() ^ max_cities

        // Furthermore, we need unique combinations as there are many overlapping
        // combinations in a set.
        // So out of 64 combinations, we need to remove all the pairs having
        // repeated characters in itself. For example : AAB, ABA, BAA, etc.
        // After that we also need to remove one of the combination from duplicate
        // pairs present in the set. For example : ABC,ACB,BAC,BCA,CAB,CBA are all
        // similar to each other. So we need to retain only one of them.
        // This should be doable by sorting each pair and adding them in a unique
        // set.

        // Then we'd be left with only unique pairs. From that we can then choose
        // the solution closest to our required constraints.

        // Filling combinations


        int sum = 0;

        for(;;);

    }
};


// Local main function

int main(){
    std::vector<int> distance_map = {50, 55, 56, 57, 58};
    std::cout << BestTravel::chooseBestSum(163, 3, distance_map);
    return 0;
}