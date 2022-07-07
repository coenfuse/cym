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
#include <map>
#include <set>


std::vector<int> two_sum(const std::vector<int> arr, const int target)
{
    std::vector<int> indices;
    std::map<int, std::set<int>> table;

    // Fill the map with values and index pair, this is required during searches
    for(int i = 0; i < arr.size(); i++)
    {
        // Check if value is already present in the map. If it is present then
        // it means we've found duplicate value. So we just add the new index to
        // its indexes list.
        // If the object is not found, then we create a new {value:index_list}
        // pair. So, if the initial array was like this, [1,4,3,1,4,2,3,4]
        // the map would look like:
        // 1 : {0}
        // 2 : {5}
        // 3 : {2,6}
        // 4 : {1,4,7}
        if(table.find(arr[i]) != table.end())
            table[arr[i]].insert(i);
        else
            table.insert({arr[i], {i}});
    }

    // Linear scan for complement pairs
    for(int i = 0; i < arr.size(); i++)
    {
        auto complement = target - arr[i];                                     

        // Find complement in table
        if(table.find(complement) != table.end())                               
        {
            auto index_list = table[complement];                               
            
            // If more than one complements are present, check if the current index
            // is in the list or not. If it is, remove it first (avoid duplicate
            // indexes) and then take the first index from the list
            if(index_list.size() > 1)
            {
                if(index_list.find(i) != index_list.end())
                    index_list.erase(index_list.find(i));                       

                indices = {i, *(index_list.begin())};                           
            }
            // else set the first value from index list as the complement index
            // given it is not as same as the current index (avoid duplicate index)
            else
            {
                if(*(index_list.begin()) != i)
                    indices = {i, *(index_list.begin())};                           
            }
        }
        else
            continue;

        // pairs have been found, exit
        if(!indices.empty())
            break;
    }

    return indices;
}


// Driver code
int main(void)
{
    auto output = two_sum({3,2,4}, 6);

    std::cout << output[0] << std::endl;
    std::cout << output[1] << std::endl;

    return 0;
}