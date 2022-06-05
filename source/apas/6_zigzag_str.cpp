// The string "ABCDEFGHIJKLM" is written in a zigzag pattern on a given number of
// rows like this:
//
// A     G     M
// B   F H   L
// C E   I K
// D     J
// 
// And then read line by line as: "AGMBFHLCEIKDJ"
//
// Write a code that will take a string and make this conversion given a number
// of depth: string convert(string base, int depth)
//
// e.g
// base = "ABCDEFGHIJKLMOP", depth = 3
// output = "AEIMBDFHJLNPCGKO"
//
// base = "ABCDEFGHIJKLMOP", depth = 4
// output = "AGMBFHLNCEIKODJP"

#include <iostream>
#include <string>

std::string zigzag(std::string base, unsigned int depth, bool is_base_str = true)
{   
    if ((depth <= 1) || (base.length() <= 1))
        return base;

    std::string this_lvl_str;

    size_t jmp_amt = 1 + (depth - 2) * 2;                                       // A.P., A = a+(n-1)d
    jmp_amt++;                                                                  // We need to get the element after jmp_amt. Thus, jmp_amt++

    if (is_base_str)
    {
        for(int i = 0; i < base.length(); i += jmp_amt)
            if(i < base.length())
                this_lvl_str += base[i];
    }
    else
    {
        int i = 0;
        while(i < base.length())
        {
            this_lvl_str += base[i];

            if(i + jmp_amt < base.length())
              this_lvl_str += base[i + jmp_amt];

            i += jmp_amt + 1;
        }
    }

    // The following has a limitation, this process only works if the string has
    // all unique characters. Can be fixed using absolute indexes instead of 
    // characters to remove from the string 

    for(auto each_char : this_lvl_str)
        if(base.find(each_char) != std::string::npos)
            base.erase(base.find(each_char), 1);

    return this_lvl_str + zigzag(base, --depth, false);
}

int main(void)
{
    std::cout << zigzag("ABCDEFGHIJKLM", 4) << std::endl;
}



// I am sure that i'll be forgetting how I solved this problem (nearly) minutes 
// after I close down the editor. So here is the recap,
//
// Consider a string "ABCDEFGHIJKLMNOP" which we need to zig-zag with depth = 4
// A zigzag string would then look like this;
// 
//                  A     G     M
//                  B   F H   L N
//                  C E   I K   O
//                  D     J     P
// 
// which when read line by line will produce
//
//                  A     G     M   -> AGM
//                  B   F H   L N   -> BFHLN
//                  C E   I K   O   -> CEIKO
//                  D     J     P   -> DJP
// 
// which when concatenated, gives us; AGMBFHLNCEIKODJP
//
// The naive approach would be to create a 2D array with some aribitary length
// and height equal to depth and then fill it in a zig-zag pattern by computing
// the array indexes. Once the array is filled, then read it line by line ignor-
// ing the empty indexes and creating the final 'zig-zag' string. 
// The problem with this approach is in the memory wastage, the empty indexes do
// occupy a memory even though they don't contain any value. In the above D4 zig
// zag we see its memory requirement as 4 x 10 x 1 byte = 40 bytes out of which
// 12 bytes are just empty spaces.
// Furthermore, computing the indexes for filling the characters is cumbersome,
// prone to several errors and hard to debug.
//
// We require a lean solution that is easy to debug and light in memory.
// Our first priority should then be to break the problem into small problems.
// Solve each of them and add them upto for the solution of the bigger problem.
// Basically, Dynamic Programming.
//
// Let's start by exploring the problem deeply this time.
// 
// 1. Consider the same string "ABCDEFGHIJKLMNOP" now with a depth = 1
//    A zigzag string would then look like this; 
// 
//                  ABCDEFGHIJKLMNOP    -> ABCDEFGHIJKLMNOP
//
//    Since, depth (a scalar, non-zero quantity) is one. Our string stays the 
//    same as the original
//
// 2. Conside the same string again now with a depth = 2
//    A zigzag string would then look like this;
//
//                  A C E G I K M O     -> ACEGIKMO
//                  B D F H J L N P     -> BDFHJLNP
//
//    A linear scanned zigzag would then look like ACEGIKMOBDFHJLNP
//
// 3. Finally we zigzag the same string with depth = 3
//    We get,
//
//                  A   E   I   M       -> AEIM
//                  B D F H J L N P     -> BDFHJLNP
//                  C   G   K   O       -> CGKO
//
//    A linear scanned zigzag would then look like AEIMBDFHJLNPCGKO
//
//
// With three different types of answer for 4 different depths, we should now
// try finding a pattern in the answer. If found, we can then try to create a 
// generic formula which would directly give us the computed string.
//
// So, the string = "ABCDEFGHIJKLMNOP"
//     
//   - With depth = 1 we get "ABCDEFGHIJKLMNOP"
//     Observation; here the string stays the same
//
//   - With depth = 2 we get "ACEGIKMOBDFHJLNP"
//     OBSERVATION; here two strings (starting with A and B respectively) are 
//     concatenated together followed by skipping 1 character. i.e In original
//     string after A we have B and after B we have C and so on. After zigzag,
//     we get string composed of chars A,C,E,G,I,K, skipping chars B,D,F,H,J, in
//     between them which are appended afterwards. So at depth = 2, jump is 1.
//     Illustrated,
//           ___     ___     ___     __
//          |   |   |   |   |   |   |   |
//          A B C D E F G H I J K L M N O P
//            |___|   |___|   |___|   |___|
//     
//     * And in the same analogy when depth <= 1, jump is 0. 
//
//   - With depth = 3 we get "AEIMBDFHJLNPCGKO"
//     OBSERVATION; here we notice a jump of 3 characters at the top layer and
//     then concatenation of start-end of jumped substrings. Illustrated,
//           _______         _______
//          |       |       |       |
//          |   *   |   *   |   *   |   *
//          A B C D E F G H I J K L M N O P
//            |___|   |___|   |___|   |___|
//
//   - With depth = 4 we get "AGMBFHLNCEIKODJP"
//     OBSERVATION; here we notice a jump of 5 characters at the top layer and
//     then concatenation of start-end of jumped substrings. Illustrated,
//           ___________             ______
//          |           |           |
//          |    ___    |           |    __
//          |   |   |   |           |   | 
//          A B C D E F G H I J K L M N O P
//            |   *   |   |   *   |   |   *
//            |_______|   |_______|   |____
//
//
// Now we have a pattern identified, we can now try solving the problem by brea-
// king it into smaller parts.
// If we had a string as "ABCDEFG" and we want to zigzag it with depth = 4
// then according to the above illustration we'd get, AGBFCED
//
//           ___________-----------> AG (1) 
//          |           |
//          |    ___ ---|----------> CE (3)
//          |   |   |   |
//          A B C D E F G
//            |   *---|------------> D  (4)
//            |_______|------------> BF (2)
//
// This can be verified by drawing the zigzag as follows,
//          
//          A     G      -> AG (1) 
//          B   F        -> BF (2)
//          C E          -> CE (3)
//          D            -> D  (4)
//
// From the original string, "ABCDEFGHIJKLMNOP" we took a substring "ABCDEFG" and
// got it solved. Now we are going to break it up further and while doing so,
// we notice that at every level we go down in zigzag, the depth decreases. i.e
//
//          A     G      -> L1 - A & G are 5 chars apart in og string, here
//          B   F        -> L2 - B & F are 3 chars apart in og string
//          C E          -> L3 - C & E are 1 char apart in og string
//          D            -> L4 - D is a single character
//
// So by reverse look-up in the relation of depth to jumps, we realise,
// L1 is created when depth = 4
// L2 is created when depth = 3
// L3 is created when depth = 2
// L4 is created when depth = 1
//
//
// So, if have a problem that is nothing but a collection of smaller but SIMILAR
// problems. We use recursion.
// We take the base problem, break it into smaller problem and make a recursive
// call until we hit a base case (where we can't solve the problem further, here
// that is L4 where D is a single character)
// 
// So before getting into a pseudocode, we first need to determine our recursive
// tree, where we are going to explor how we break our problem into small chunks
// and then add them up from the top to obtain the final solution.
// Let's take the same string "ABCDEFGHIJKLMNOP" with depth = 4
//
//                   A B C D E F G H I J K L M N O P  -----> Base layer
//                     |       |   |       |   |   
//                     |       |   |       |   |   
//                     B C D E F   H I J K L   N O P  -----> Non-Base layer(s)
//                       |   |       |   |       |
//                       |   |       |   |       |
//                       C D E       I J K       O P
//                         |           |           |
//                         |           |           |  
//                         D --------- J ----------P--------> Base Case(s)
//
// So according to our tree, we need to start aggregating the answers from top-
// down. So here it is,
//
// L1 (ABCDEFGHIJKLMNOP)      -> gives us 'AGM' at depth = 4 (jumping 5 chars)
// 
// L2 (BCDEF)                 -> gives us 'BF' at depth = 3 (jumping 3 chars)
// L2 (HIJKL)                 -> gives us 'HL' at depth = 3 (jumping 3 chars)
// L2 (NOP)                   -> gives us 'N'  at depth = 3 (jumping 3 chars)
//
// L3 (CDE)                   -> gives us 'CE' at depth = 2 (jumping 1 char)
// L3 (IJK)                   -> gives us 'IK' at depth = 2 (jumping 1 char)
// L3 (OP_)                   -> gives us 'O'  at depth = 2 (jumping 1 char)
//
// L4 (D)                     -> gives us 'D' at depth = 1 (no jumps)
// L4 (J)                     -> gives us 'J' at depth = 1 (no jumps)
// L4 (P)                     -> gives us 'P' at depth = 1 (no jumps)
//
// Now all we need is to add the solutions from each level from with its sibling
// and move up (or down, depending on where you started). So here we get,
//
// zigzag_string = AGM + (BF + HL + N) + (CE + IK + O) + (D + J + P)
//               = AGMBFHLNCEIKODJP
//
// Now this process and aggregation would look very similar to just drawing a
// zigzag and reading it line by line. Nothing out of the box here, but what this
// tree helps us with is in identifying the recursive levels and how depth and
// string are manipulated at each level which weren't clear before. So now let's
// tackle each essential parameter one by one.
//
// DEPTH & JUMP : At every level we notice that the Depth gets reduced by one.
//                and using this depth value, we can compute the number of chars
//                we need to jump to get our next character. Early on we discov-
//                ered a pattern in Depth to Jump amount which is recalled below
//
//                                  if depth = 0 then jump = 0
//                                  if depth = 1 then jump = 0
//                                  if depth = 2 then jump = 1
//                                  if depth = 3 then jump = 3
//                                  if depth = 4 then jump = 5
//
//                Here we notice the jump amount is always an odd number with d-
//                ifference of 2 to its adjacent values. This pattern can now be
//                easily denoted by a simple A.P. equation:
//
//                                  Jump = 1 + (Depth - 2) * 2      -------- (1)
//
// BASE LAYER   : Refers to very first layer that is processed and broken further
//                upon first call of the zigzag method. The logical difference
//                difference between the first layer and all the subsequent lay-
//                ers comes from how we process it.
//                Taking the same string "ABCDEFGHIJKLMNOP" again at depth 4, we
//                get a string AGM from our base layer. How did we get it? Just
//                start from first character (here, A), jump the indexes as told
//                by the eq. (1) and read the next character. So, read A, jump 5
//                land at F, read the next G, jump 5 land at L, read the next M.
//                This is the only time we have to worry about the base layer.
//                
// NON-BASE LAYER : Now that we our base layer computed, we need to parse the
//                rest of the characters in the string. The rest of the chars can
//                then be obtained by removing the string AGM from OG string.
//                Here that gives us, BCDEFHIJKLNOP.
//                Since this we've got on this layer from the base layer, the
//                depth has also reduced by 1 giving us depth = 3 and thereby,
//                the jump amount is also 3.
//                Now notice the string we have, BCDEFHIJKLNOP.
//                If we processed it the same way we did with the base layer,
//                we'd get BFKP. (Start from B, jump 3 places and select next)
//                But what we needed was BFHLN as shown in our tree above.
//                For that we need to break this string into groups from places
//                where we had our first layer. So our string now looks like,
//                BCDEF-HIJKL-NOP. And now we need to do our jump operations
//                in each group.
//                So selecting first char then jumping 3 chars to select next char
//                in group BCDEF gives us BF. (Selected B, skipped CDE, got F)
//                Similarly for other groups we get,
//                group(HIJKL) -> HL
//                group(NOP)   -> N     (Since after N we skip 3 chars and got null)
//                
//                Now combining results from 3 group gives us the correct answer
//                of BFHLN = BF + HL + N
//                This layer is now processed. Befoer going to next layer below
//                we need to first remove the chars of this layer result from
//                OG string to prevent duplicate processing. So,
//                BCDEFHIJKLNOP - BFHLN = CDEIJKOP, which is then processed with
//                depth level 2 (Remember, we minus depth by 1 every layer go)
//                
//                Processing CDEIJKOP with depth = 2 gives us CEIKO.
//                This leaves us with just D,J and P which are just base cases
//                and returned as it is.
//                
//
// With all the points in place, we can now proceed to write a pseudocode for it
/*

string zigzag(string base, int depth, bool is_base_layer)
{
    // handle base cases
    if base.length() <= 1 OR depth <= 1
        return base

    // Find number of characters to jump at this depth
    int jump_amt = 1 + (depth - 2) * 2

    // Accomodate for the index of character you want select AFTER jumping
    int jump_amt = jump_amt + 1

    // Make space for results at this level
    string this_lvl_str

    // Compute the string depending on if this is a base layer or not
    if is_base_layer
    {
        for(index = 0; index < base.length; index += jmp_amt)
            this_lvl_str += base[index]
    }
    else
    {
        for(index = 0; index < base.length())
        {
            this_lvl_str += base[index]
            
            index = index + jmp_amt

            this_lvl_str += base[index]

            index++;
        }
    }

    // Erase this level's answer from string to avoid double processing
    for each_char in this_lvl_str
        base.erase(each_char)

    // make a recursive call with -1 depth and is_base_layer flag set to false
    return this_lvl_str + zigzag(base, --depth, false)
}

*/