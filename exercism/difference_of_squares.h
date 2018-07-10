#if !defined(DOS_H)
#define DOS_H

#include <algorithm>
#include <functional>
#include <numeric>

namespace squares {
    int square_of_sums(int nn) {
        int numbers[nn];

        std::iota(numbers, numbers + nn, 1);

        int sum = std::accumulate(numbers, numbers + nn, 0, std::plus<int>());

        return sum * sum;
    }

    int sum_of_squares(int nn) {
        int numbers[nn];

        std::iota(numbers, numbers + nn, 1);

        std::transform(numbers, numbers + nn, numbers, numbers, std::multiplies<int>());

        return std::accumulate(numbers, numbers + nn, 0, std::plus<int>());
    }

    int difference(int nn) {
        return square_of_sums(nn) - sum_of_squares(nn);
    }
}

#endif

//
//  This solution respects the instruction to:
//
//        "Try to use standard C++11 facilities in preference to writing your
//         own low-level algorithms or facilities by hand."
//
//  What a waste.
//
