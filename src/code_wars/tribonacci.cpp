// Well met with Fibonacci bigger brother, AKA Tribonacci.
// As the name may already reveal, it works basically like a Fibonacci, but 
// summing the last 3 (instead of 2) numbers of the sequence to generate the
// next. And, worse part of it, regrettably I won't get to hear non-native
// Italian speakers trying to pronounce it :(
// So, if we are to start our Tribonacci sequence with [1, 1, 1] as a starting
// input (AKA signature), we have this sequence:
// [1, 1 ,1, 3, 5, 9, 17, 31, ...]
// But what if we started with [0, 0, 1] as a signature? As starting with [0, 1]
// instead of [1, 1] basically shifts the common Fibonacci sequence by once pl-
// ace, you may be tempted to think that we would get the same sequence shifted
// by 2 places, but that is not the case and we would get:
// [0, 0, 1, 1, 2, 4, 7, 13, 24, ...]

// Well, you may have guessed it by now, but to be clear: you need to create a
// fibonacci function that given a signature array/list, returns the first n e-
// lements - signature included of the so seeded sequence.
// Signature will always contain 3 numbers; n will always be a non-negative nu-
// mber; if n == 0, then return an empty array (except in C return NULL) and be
// ready for anything else which is not clearly specified ;)

#include <vector>
#include <iostream>

// Boiler plate code given in the question

std::vector<int> tribonacci(std::vector<int> signature, int n)
{
    std::vector<int> result;
    n -= signature.size();          // Weird Section, The Beginning

    if(n > 0){

        result = signature;

        while(n!=0){
            int last_index = result.size() - 1;
            result.push_back(result[last_index] + result[last_index - 1] + result[last_index - 2]);
            n--;
        }

        return result;
       
    }

    // Weird Section, The Happening

    if(n < 0)
        n += signature.size();

    result = signature;
    result.resize(n);

    // Weird Section, The Conclusion

    return result;
}

// Conceptualizing the tribonnaci sequence here. Naive approach.

int tribonacci(int n){
    if(n < 1) return 0;
    if(n == 1) return 0;
    if(n == 2) return 1;
    if(n == 3) return 1;
    return tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
}

// Just for local testing

int main(){

    std::vector<int> sequence = tribonacci({1,2,3},10);
    for(int each : sequence)
        std::cout << each << ", ";
    std::cout << "\n" << tribonacci(8);
    return 0;
}

// NOTE:
// push_back at every iteration is very inefficient. It would lead to many
// resizing calls. Instead, it would better to fix the returning vector's size
// in the beginning itself and then push into it. This would at-least reduce
// resizing overhead.
// Infact, why even use push_back then ? Just use the index to directly insert
// into. Can lead to very obscure code though.