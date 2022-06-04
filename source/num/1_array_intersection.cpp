// You are given two large arrays containing integers. Create an array containing
// of the given arrays.
// e.g [1,2,3,4,5] /\ [4,5,6,7,8] = [4,5]
// where '/\' referes to intersection    


#include <iostream>
#include <set>
#include <vector>

using arr_int = std::vector<int>;

arr_int arr_intersxn(arr_int arr_a, arr_int arr_b)
{
    arr_int intersection;

    // AVB = A + B - A/\B
    // AVB - (A + B) = A/\B

    // Creating AVB                                                             [1,2,3,4,5,6,7,8]
    std::set<int> avb;

    for(auto digit : arr_a)
        avb.insert(digit);

    for(auto digit : arr_b)
        avb.insert(digit);

    // Finding true_a & true_b. Isn't this called complement?
    // true_a = AVB - B                                                         [1,2,3]
    // true_b = AVB - A                                                         [6,7,8]

    arr_int true_a;
    {
        auto avb_copy = avb;

        for(auto digit : arr_b)
            avb_copy.erase(digit);

        for(auto digit : avb_copy)                                              // not necessary
            true_a.push_back(digit);
    }

    arr_int true_b;
    {
        auto avb_copy = avb;

        for(auto digit : arr_a)
            avb_copy.erase(digit);

        for(auto digit : avb_copy)                                              // not necessary
            true_b.push_back(digit);
    }

    // Subtract true_a and true_b from avb, you get a/\b
    {
        for(auto digit : true_a)
            avb.erase(digit);

        for(auto digit : true_b)
            avb.erase(digit);

        for(auto digit : avb)
            intersection.push_back(digit);                                      // not necessary
    }
    
    return intersection;
}


int main(void)
{
    auto ans = arr_intersxn({1,2,3,4,5}, {1,2,3,4,5});

    for(auto item : ans)
        std::cout << item << std::endl;

    return 0;
}