// You are given two non-empty linked lists representing two non-negative integ-
// ers. The digits are stored in reverse order and each of their nodes contain
// a single digit. Add the two numbers and return it as linked list.
// You may assume the two numbers do not contain any leading zero, except the
// number 0 itself.
//
// eg; input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//    output: 7 -> 0 -> 8
// explaination: 342 + 465 = 807

#include <iostream>
#include <list>
#include <math.h>

using ilist = std::list<int>;
using llint = long long int;

llint cus_pow(llint base, llint pow)
{
    if (pow < 0)
        return 0;

    if (pow == 0) 
        return 1;

    llint ans = base;
    
    while(pow != 1)
    {
        ans = ans * base;
        pow--;
    }

    return ans;
}

llint list_to_num(ilist l)
{
    int power = 0;
    int num = 0;

    for(auto digit : l)
    {
        num += digit * cus_pow(10, power);
        power++;
    }

    return num;
}

ilist num_to_list(llint n)
{
    ilist ans;

    // convert num to string
    auto num_str = std::to_string(n);

    // then pull each character digit and store into list as inteager
    for (auto each_digit_char : num_str)
        ans.push_front(each_digit_char - '0');                                   // In ASCII nums start from 48, so minus each_digit_char from '0'=48 and get int equivalent. 

    return ans;
}

ilist add_two_nums(ilist a, ilist b)
{
    auto num_a = list_to_num(a);
    auto num_b = list_to_num(b);

    std::cout << num_a << std::endl;
    std::cout << num_b << std::endl;
    std::cout << num_a + num_b << std::endl;

    return num_to_list(num_a + num_b);
}


// driver code
int main(void)
{
    auto ans = add_two_nums({2,4,3}, {5,6,4});

    for (auto digit : ans)
        std::cout << digit << std::endl;

    return 0;
}