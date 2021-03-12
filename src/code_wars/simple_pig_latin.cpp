// Move the first letter of each word to the end of it, then add "ay" to the
// end of the word. Leave punctuation marks untouched.

// pigIt('Pig latin is cool'); // igPay atinlay siay oolcay
// pigIt('Hello world !');     // elloHay orldway !

#include <iostream>
#include <string>
#include <vector>

// Boilerplate code given in the question

std::string pig_it(std::string str)
{
  std::string const_append = "ay";
  std::string pigged_string;

  // Finding number of words present in the string.
  // It is done by counting the (white spaces + 1)

  size_t words = 0;
  for(char each : str){
    if(each == ' ')
      words++;
  }
  
  std::vector<std::string> word_list(words + 1);

  // Extracting words and filling into word list
  words = 0;                                  // Reusing the word index

  for(char each : str){
    if(each != ' '){
      word_list[words] += each;         // Concatenating characters from original string into word container until a white space isn't encountered.
      continue;
    }
    words++;
  }

  // Manipulating each word in the list
  for(auto each : word_list){
    each += each[0] + const_append;
    each.erase(0,1);                    // Erases the first character of the string we just appended at the end.
    //std::cout << each << std::endl;
    pigged_string += each + " ";
  }

  // Expected: equal to ". , vay ray llfay tuqyay qay"
  // Actual: ".ay ,ay vay ray llfay tuqyay qay"
  // Need no alteration whenever a special character is encountered.

  // Removing one extra space from the end of the string
  pigged_string.pop_back();

  return pigged_string;
}

// Local main function

int main(){
  std::cout << pig_it("Sarthak is kinda weird. Isn't it?");
  return 0;
}