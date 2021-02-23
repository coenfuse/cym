// Build a function that returns an array of integers from n to 1 where n>0.
// Example : n=5 >> [5,4,3,2,1]

#include <iostream>
#include <vector>

// The following is the boilerplate code given in the question

std::vector<int> reverseSeq(int n) {
  std::vector<int> reversed_sequence;
  while(n != 0){
      reversed_sequence.push_back(n);
      n--;
  }
  return reversed_sequence;
}

// Just for local test purposes

int main(){
    std::vector<int> reversed = reverseSeq(30);
    for(int value : reversed)
        std::cout << value << ", ";
    return 0;
}