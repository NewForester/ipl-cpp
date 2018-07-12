#if !defined(FOOD_CHAIN_H)
#define FOOD_CHAIN_H

#include <numeric>
#include <string>

namespace food_chain {
    using namespace std;

    const char *heads[] = {
        "fly.\n",
        "spider.\n"     "It wriggled and jiggled and tickled inside her.\n",
        "bird.\n"       "How absurd to swallow a bird!\n",
        "cat.\n"        "Imagine that, to swallow a cat!\n",
        "dog.\n"        "What a hog, to swallow a dog!\n",
        "goat.\n"       "Just opened her throat and swallowed a goat!\n",
        "cow.\n"        "I don't know how she swallowed a cow!\n",
        "horse.\n"      "She's dead, of course!\n",
    };

    const char *tails[] = {
        "She swallowed the cow to catch the goat.\n",
        "She swallowed the goat to catch the dog.\n",
        "She swallowed the dog to catch the cat.\n",
        "She swallowed the cat to catch the bird.\n",
        "She swallowed the bird to catch the spider that wriggled and jiggled and tickled inside her.\n",
        "She swallowed the spider to catch the fly.\n",
        "I don't know why she swallowed the fly. Perhaps she'll die.\n",
    };

    string &join(string &left, const char *right) {
        return left += right;
    }

    string verse(int which) {
        string recital = "I know an old lady who swallowed a ";

        if (which < 9 && which > 0)
            recital += heads[which - 1];

        if (which < 8 && which > 0)
            return accumulate(tails + 7 - which, tails + 7, recital, join);

        return recital;
    }

    string verses(int first, int last) {
        string recital;

        for(auto ii = first; ii <= last; ++ii)
            (recital += verse(ii)) += "\n";

        return recital;
    }
}

#endif

//
//  This solution uses lookup tables and the accumulate() algorithm.
//
//  There were two simple solutions that looked up verses in an array or
//  vector.  The others, like mine, sought to be clever.
//
//  The problem is how clever.  I baulked at the idea of adding special cases
//  to the code so I have the table tails[].  All the other clever solutions
//  used a more general form and then had to add special cases.
//
//  Mine is the only solution to use accumulate() in verse() - one used it in
//  verses().  All the other settled for string concatenation except for one,
//  which used a string stream.
//
//  Most solutions were significantly longer than this one.
//
