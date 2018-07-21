#if !defined(GAINS_H)
#define GAINS_H

namespace grains {
    unsigned long long square(int square) {
        return 1ULL << --square;
    }

    unsigned long long total(void) {
        return 0xffffffffffffffff;
    }
}

#endif

//
//  This solution uses algrebra, not STL, expressions.
//
//  The problem sort of suggests two routiness that loop.  While the first is
//  quite often replaced by pow() - which may be relatively slow - the second
//  is less often replaced by the constant.
//
//  Here less that half used pow() and more than half used the constant.  There
//  was only one used a for loop to sum and another used recursion.  While the
//  constant was expressed 6 different ways.
//
//  I feel that if a binary (aka bit-wise) solution isn't immediately obvious
//  to the reader then they are not really a programmer so I am puzzled by the
//  apparent desire to complicate matters.
//
//  There was some (silly) discussion of what would happen on a 128-bit machine
//  so I guess my constant should have had ULL attached to add a double
//  guarantee that there would be no sign extension on such an imaginary machine.
//
