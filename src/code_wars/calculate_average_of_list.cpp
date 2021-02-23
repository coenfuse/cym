// Write a program that calculates the average of the values present in a list.

#include <vector>
#include <iostream>

// The following is the boilerplate code given in the question

double calcAverage(const std::vector<int>& values){
  double average = 0.0;
  for(int each : values)
    average += each;
  return average / values.size();
}

// Just for local test purposes

int main(){
    std::cout << calcAverage({22,22,24,15,12,18,22,14,24,23,29,19,22,20,26});   // Should return : 20.8
    return 0;
}
