// There are two sorted array num1 and num2 of size m and n respectively.
// Find the median of the two sorted arrays. The overall run time complexity
// should be O(log(m+n))
// You may assume num1 and num2 cannot be both empty.
//
// eg;
// num1 = [1,3]
// num2 = [2]
// median = 2.0
//
// num1 = [1,2]
// num2 = [3,4]
// median = (2 + 3)/2 = 2.5

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using arr_int = std::vector<int>;

double arr_median(arr_int arr_a, arr_int arr_b)
{
    double median = 0;
    arr_int data;

    // Create a unique and sorted data var that contains both array elements 
    for(auto digit : arr_a)
        data.push_back(digit);

    for(auto digit : arr_b)
        data.push_back(digit);

    // sort the array
    std::sort(data.begin(), data.end());

    // Find middle point of data. 
    // If the size of data is an even number, take the average of two middlemost
    // elements, else return the middle item
    if(data.size() % 2 == 0)                             // checking even or odd
    {
        auto mid_a = data[int(data.size() / 2) - 1];
        auto mid_b = data[int(data.size() / 2)];

        median = (mid_a + mid_b) / 2.0;
    }
    else
        median = data[int(data.size() / 2)];            // find middle index, convert index to num then access data at that index

    return median;
}


int main(void)
{
    std::cout << arr_median({1,3}, {2,4}) << std::endl;

    return 0;
}