// ROT13 is a simple letter substitution cipher that replaces a letter with the
// letter 13 letters after it in the alphabet. ROT13 is an example of the
// Caesar cipher.

// Create a function that takes a string and returns the string ciphered with
// Rot13. If there are numbers or special characters included in the string,
// they should be returned as they are. Only letters from the latin/english al-
// phabet should be shifted, like in the original Rot13 "implementation".

#include <string>
#include <iostream>

// The following is the boiler-plate code given in the question

std::string rot13(std::string msg)
{
    const short rot13 = 13;
    std::string rot13_string;

    for(unsigned char alphabet : msg){

        // The character is in lowercase
        if(alphabet >= 'a' && alphabet <= 'z'){

            // Calculating the absolute Rot13 value by jumping 13 places in the ASCII table
            unsigned char rot13_char = (unsigned char)(alphabet + rot13);

            // Wrapping rot13_char if it exceeds English alphabetic limit
            if(rot13_char > 'z')
                rot13_string += 'a' + (rot13_char - 'z') - 1;           
            else
                rot13_string += rot13_char;

            // rot13_string += 'a' + (rot13_char - 'z') - 1;
            // 'a' is the starting index for wrapping.
            // (rot13_char - 'z') gives the number that needs to be wrapped around
            // -1 is done because wrapping number is calculated using z, when it should've been
            // the character after 'z'. But I retained the 'z' just for readability purposes.
        
        }

        // The character is in uppercase
        else if(alphabet >= 'A' && alphabet <= 'Z'){

            unsigned char rot13_char = (unsigned char)(alphabet + rot13);
            if(rot13_char > 'Z')
                rot13_string += 'A' + (rot13_char - 'Z') - 1;
            else
                rot13_string += rot13_char;
        }

        // The character is not an alphabet. So, no change.
        else
            rot13_string += alphabet;   // No alteration, just adding to the final string.
    }

    return rot13_string;
}

// Just for local testing

int main(){

    std::cout << rot13("Te%T") << std::endl;    // Returns : "grfg"
    return 0;
}

// BEST SOLUTION : Stolen
/*

  for(auto& x : msg) 
    if (islower(x)) x = 'a'+(x-'a'+13)%26; 
    else if(isupper(x)) x = 'A'+(x-'A'+13)%26;
  return msg;

*/