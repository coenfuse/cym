// We want to generate a function that computes the series starting from 0 and
// ending until the given number.

#include <iostream>
#include <string>

// The following is the boilerplate code given in the question

using namespace std;

class SequenceSum{
  int count;
  public:
  SequenceSum (int);
  string showSequence();
  
};

string SequenceSum::showSequence(){

    if(!count) return "0=0";
    else if(count < 0)  return to_string(count) + "<0";
    
    string sequence = "0";
    int sum = 0;
    
    for(int i = 1; i <=count; i++){
        sum += i;
        sequence += "+" + to_string(i);
    }

    sequence += " = " + to_string(sum);

    return sequence;
}

SequenceSum::SequenceSum (int c) {
  count = c;
}

// Just for local test purposes

int main(){

    SequenceSum OBJ(10);
    std::cout << OBJ.showSequence() << std::endl;
    return 0;

}