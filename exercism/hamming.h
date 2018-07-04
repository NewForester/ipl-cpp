#if !defined(HAMMING_H)
#define HAMMING_H

#include <stdexcept>

namespace hamming {
    int compute(const char *A, const char *B) {
        int     distance = 0;

        while (*A && *B)
            distance += *A++ != *B++;

        if (*A || *B)
            throw std::domain_error("strands have different lengths");

        return distance;
    }
}

#endif

//
//  Nice and simple solution.  Who needs the string class ?
//
//  It looks like all the others went with the string class.  In the case of
//  these test cases, means a conversion.  The strings were passed by value.
//
//  Otherwise, they all tested on length equality first, used a for loop and
//  referenced the data in the strings using indexes.
//
//  There was even a reference "In C++17 you can do this ..." so I guess my C code looks
//  old and tired.
//
