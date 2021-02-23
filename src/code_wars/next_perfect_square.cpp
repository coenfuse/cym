// Complete the findNextSquare method that finds the next integral perfect squ-
// are after the one passed as a parameter. Recall that an integral perfect sq-
// uare is an integer n such that sqrt(n) is also an integer.
// If the parameter is itself not a perfect square then -1 should be returned.
// You may assume the parameter is positive.
// For example : findNextSquare(625) --> returns 676
//               findNextSquare(114) --> returns -1 since 114 is not a perfect

#include <iostream>
#include <math.h>

// The following is the boilerplate code given in the question

long int findNextSquare(long int sq) {
  if(sq > 0){
   double root = sqrtf(sq);
   long root_floor = long(root);
   if(double(root - root_floor) == 0.0)
       return long ((root + 1) * (root + 1));        // Cleaner approach : long(pow(root + 1, 2))
  }
  return -1;
}

// Just for local test purposes

int main(){
    std::cout << findNextSquare(-1);
    return 0;
}

// ISSUES
// 1. Excessive type conversion
// 2. Doesn't work with root datatype as float
// 3. Too complicated?

// CONCEPT
// Consider a pair of adjacent perfect squares.
// Let 144 and 169 be our cases. Both have roots as 12 and 13 respectively.
// Square root of any integer b/w 144 & 169 will be a float val b/w 12 & 13.
// Converting root into long will round it of to its nearest floor inteager
// removing any decimal digits that were present in the process.
// If the difference between the floor and actual root is not equal to 0.0
// Then it means the number wasn't a perfect square.

// For example;
// Take 155, its root is 12.4498
// The floor of root is 12
// Difference between floor and root is 0.4498, that is not equal to 0.0
// Thus, it is not a perfect square.

// Take 169, its root is 13.0000
// The floor of root is 13
// Difference between floor and root is 0.0.
// Thus, it is a perfect square.

// SIMPLER VARIANT
// long int q = (long int) pow(sq, 0.5);
// return q * q == sq ? pow(q + 1, 2) : -1;