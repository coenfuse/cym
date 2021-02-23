// In DNA strings, symbols "A" and "T" are complements of each other, as "C" a-
// nd "G". You have function with one side of the DNA (string, except for Hask-
// ell); you need to get the other complementary side. DNA strand is never emp-
// ty or there is no DNA at all (again, except for Haskell).
// For example : DNA_strand ("ATTGC") # return "TAACG"

#include <iostream>         // Basic I/O
#include <string>           // String Manipulation

// The following is the boilerplate code given in the question

std::string DNAStrand(const std::string& dna)
{
    std::string DNAcomplement;

    for(size_t i = 0; i < size_t(dna.size()); i++){         // Linear scanning the DNA string

        switch (dna[i])                                     // Switch table for complement characters
        {
        case 'a': DNAcomplement += 't';
            break;
        case 'A': DNAcomplement += 'T';
            break;
        case 't': DNAcomplement += 'a';
            break;
        case 'T': DNAcomplement += 'A';
            break;
        case 'g': DNAcomplement += 'c';
            break;
        case 'G': DNAcomplement += 'C';
            break;
        case 'c': DNAcomplement += 'g';
            break;
        case 'C': DNAcomplement += 'G';
            break;
        default:
            break;
        }

    }
  return DNAcomplement;
}

// Just for local test purposes

int main(){
    std::cout << DNAStrand("TAACG");
    return 0;
}