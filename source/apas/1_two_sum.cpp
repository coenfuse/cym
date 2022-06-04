// Given an array of integers, return indices of the two numbers such that they
// add up to a specific target.
// You may assume that each input would have exactly one solution, and you may
// not use the same element twice.
//
// e.g; Given num = [2,7,11,15], target = 9
// Since, num[0] + num[1] = 2 + 7 = 9
// return [0,1]

#include <iostream>
#include <vector>
#include <set>

std::vector<int> two_sum(const std::vector<int> arr, const int target)
{
    std::vector<int> indices;
    std::set<int> data_index;

    // Create a set in O(n) time to search for complements in O(1) time.
    for(auto item : arr)
        data_index.insert(item);

    // Find pairs by creating complements and searching them in index, if found
    // run a linear scan to find the index of the complement. Terminate the loop
    // there then.
    for(int i = 0; i < arr.size(); i++)                                         
    {
        auto complement = target - arr[i];
        
        if (data_index.find(complement) != data_index.end())                    
        {
            int j = i;
            
            for(; j < arr.size(); j++)                                          
                if (arr[j] == complement)
                    break;

            indices = {i, j};
        }
        else
            continue;

        if (!indices.empty())
            break;
    }

    return indices;
}


// Driver code
int main(void)
{
    auto output = two_sum({-9,5,0,18}, 9);

    std::cout << output[0] << std::endl;
    std::cout << output[1] << std::endl;

    return 0;
}