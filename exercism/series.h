#if !defined(SERIES_H)
#define SERIES_H

#include <algorithm>
#include <cstring>
#include <stdexcept>
#include <vector>

namespace series {
    std::vector<int> digits(const char *sequence, size_t size = 0) {
        size = size ? size : strlen(sequence);

        std::vector<int> digits(size);

        std::transform(sequence, sequence + size, digits.begin(), [] (char digit) {return digit - '0';});

        return digits;
    }

    std::vector<std::vector<int>> slice(const char *sequence, int slice_size) {
        int count = strlen(sequence) - slice_size + 1;

        if (count <= 0)
            throw std::domain_error("unable to slice");

        std::vector<std::vector<int>> slices;

        for (auto sp = sequence; count--; ++sp)
            slices.push_back(digits(sp, slice_size));

        return slices;
    }
}

#endif

//
//  This solution replaces the loop in digits with std::transform and then
//  alters digits() so that it can be used directory from slice().
//
//  This avoid slice() converting the all the digits as a preliminary, which,
//  in C++, is potentially a large vector, at the expense of transforming
//  individual digits several times over.
//
