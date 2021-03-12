// UNSOLVED - NOT MINE 
// The aim of the kata is to decompose n! (factorial n) into its prime factors.
// Examples:
// n = 12; decomp(12) -> "2^10 * 3^5 * 5^2 * 7 * 11"
// since 12! is divisible by 2 ten times, by 3 five times, by 5 two times and
// by 7 and 11 only once.
// n = 22; decomp(22) -> "2^19 * 3^9 * 5^4 * 7^3 * 11^2 * 13 * 17 * 19"
// n = 25; decomp(25) -> 2^22 * 3^10 * 5^6 * 7^3 * 11^2 * 13 * 17 * 19 * 23
// Prime numbers should be in increasing order. When the exponent of a prime is
// 1 don't put the exponent.

// Notes : 
// the function is decomp(n) and should return the decomposition of n! into its
// prime factors in increasing order of the primes, as a string.
// factorial can be a very big number (4000! has 12674 digits, n can go from
// 300 to 4000).
// In Fortran - as in any other language - the returned string is not permitted
// to contain any redundant trailing whitespace: you can use dynamically
// allocated character strings.

#include <iostream>
#include <string>
#include <vector>

// Boilerplate code given in the question

std::string decomp(int n) {
  std::vector<int> seg(4000);
    for ( int j = 2; j <= n; j++ ) {
        int num = j;
        int i = 2;
        while ( num != 1 ) {
            while ( num % i == 0 ) {
                seg[i]++;
                num /= i;
            }
            i++;
        }
        if ( num ) seg[num]++;
    }
    
    std::string res;
    for ( int k = 2; k <= n; k++ ) {
        if ( seg[k] ) {
            if ( seg[k] == 1 ) res += std::to_string(k) + " * ";
            else res += std::to_string(k) + "^" + std::to_string(seg[k]) + " * ";
        
        }
    }
    return res.substr(0, res.size() - 3);
}

// Local main function here

int main(){
  std::cout << decomp(5);
  return 0;
}