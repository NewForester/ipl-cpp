#if !defined(SERIES_H)
#define SERIES_H

#include <algorithm>
#include <stdexcept>
#include <string>
#include <vector>

namespace series {
    std::vector<int> digits(const char *sequence) {
        std::vector<int> digits;

        for (auto digit : std::string(sequence))
            digits.push_back(digit - '0');

        return digits;
    }

    std::vector<std::vector<int>> slice(const char *sequence, int chunks) {
        std::vector<std::vector<int>> slices;

        std::vector<int> dv = digits(sequence);

        int count = dv.size() - chunks + 1;

        if (count <= 0)
            throw std::domain_error("unable to slice");

        for (auto it = dv.begin(); count--; ++it) {
            std::vector<int> slice(chunks);

            std::copy_n(it, chunks, slice.begin());

            slices.push_back(slice);
        }

        return slices;
    }
}

#endif

//
//  This exercise has an unclear readme.  The C++ test case however are simple.
//
//  This straight forward exercise for which I have hoping the one obvious
//  solution would emerge from the other solutions examined.  It did not.
//
//  All solutions used a two function approach (except one that had an unused
//  implementation).
//
//  For the first function, some used transform, the majority, a loop like mine.
//  None of the loop solutions made any attempt to create a vector of the right
//  size to hold the result and none attempted to do the transformation in place.
//  Those that used transform were at least obliged to reserve enough space.
//
//  For the second function, some reserved enough space for the outer vector
//  but none (except myself) reserved space for the inner vectors.  The data
//  was copied used either push_back or emplace_back.  I used copy_n for
//  emphasis.
//
//  The choice seemed to be a) create a slice vector and use push_back or b)
//  use emplace_back and pass it iterators defining the slice.  The second,
//  majority, solution appears the more processor efficient and requires less
//  temporary state.
//
//  Not apparent on the first pass was that those who used the first function
//  piecemeal used emplace_back while the minority who did use their first
//  function piecemeal used push back.  This has implications for the memory
//  required.
//
