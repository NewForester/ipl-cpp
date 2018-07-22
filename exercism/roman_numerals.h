#if !defined(ROMAN_H)
#define ROMAN_H

#include <algorithm>
#include <map>
#include <string>
#include <vector>

namespace roman {
    using namespace std;

    const vector<pair<int, map<char, char>>> powersOf10 = {
        {1000, {{'I', 'M'},}},
        { 100, {{'I', 'C'}, {'V', 'D'}, {'X', 'M'},}},
        {  10, {{'I', 'X'}, {'V', 'L'}, {'X', 'C'},}},
        {   1, {{'I', 'I'}, {'V', 'V'}, {'X', 'X'},}},
    };

    string convert(int nn) {
        string numerals;

        for (auto &pair : powersOf10)
            if (nn >= pair.first) {
                string num = vector<string>{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"} [nn / pair.first];

                transform(num.begin(), num.end(), num.begin(), [pair](char dd) {return pair.second.at(dd);});

                numerals += num;

                nn %= pair.first;
            }

        return numerals;
    }
}

#endif

//
//  This solution uses a lookup within a loop and a fanciful transform().
//
//  For me the solution to this problem is two stage:
//
//      a) choose an algorithm
//      b) implement the algorithm in C++
//
//  whereas for many problems a) is 'a no brainer choice' so the solution is
//  all about b).  Therefore I was surprised that most of the solutions
//  examined all used the same algorithm.  One was similar to mine and the
//  author admitted he had looked up the algorithm on-line.  There was one
//  original looking solution and the final solution used recursion.
//
//  The majority had a simple lookup table {"M", 1000}, {"CM", 900} ... a loop
//  to work through that and a while loop to produce XXX for thirty and so on.
//  I like the algorithm.  Much better than mine and no need to complicate
//  matters and further (although several did).
//
//  The solution similar to mine did not have the transform() and unrolled the
//  loop.  Made it look much simpler.  The original solution was close to the
//  problem statement and one would suggest using a look up table ...  The
//  recursion was an unrolling of the majority solution and introduced lots of
//  repetitive testing that the loop versions avoid.  A sort of match statement
//  gone too far.
//
//  There was some discussion of string concatenation.  Seems += was (almost)
//  always better than + but with GCC version 5 the internals are even better.
//  None (of the eight) used a stringstream.  No reason if all you are doing
//  is string concatenation.
//
//  There was discussion of the use of maps.  Apparently they are horribly
//  inefficient (and several map alternatives).  Reminds me of discussions
//  on other tracks of using complex data structures for a mere side-effect.
//  Somehow I thought, on other tracks, that small dicts were efficient but
//  I should be more careful.
//
