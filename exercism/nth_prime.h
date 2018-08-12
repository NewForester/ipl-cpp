#if !defined(PRIME_H)
#define PRIME_H

#include <stdexcept>

namespace prime {
    bool isPrime(int candidate) {
       for (int base = 5; base * base <= candidate; base += 6)
            for (int factor : {base, base + 2})
                if (candidate % factor == 0)
                    return candidate == factor;

        return true;
    }

    int nth(int nth) {
        if (nth <= 0)
            throw std::domain_error("need a positive ordinal");
        if (--nth == 0)
            return 2;
        if (--nth == 0)
            return 3;

        for (int base = 5; ; base += 6)
            for (int candidate : {base, base + 2})
                if (isPrime(candidate))
                    if (--nth == 0)
                        return candidate;
    }
}

#endif

//
//  The test case that sought the 10001 prime was used as a benchmark.
//
//  The previous iteration was used as a starting point:  ~1.5s.
//
//  Reserving the vector seemed to slow things down.  Using std::list instead
//  of std::vector really slowed things down: ~5s.  Replacing the use of
//  std::any_of with a lamdba also seemed to slow things a little.
//
//  Adding the square optimisation improved matters considerably:  ~30 ms.  All
//  further fiddling made no signficant difference.
//
//  This much faster version still used std::vector but I was fascinated by
//  someone's use of 6n±1.  This considers two candidates per iteration and so
//  tends to run fast but more significant was the claim that it was as fast as
//  std::vector solutions without the memory overhead.
//
//  This seems to be the case for the solution above.  Adding a std::vector
//  back in made no difference.  This was suprising.  Perhaps for much, much
//  larger primes the situation would change but perhaps this will always win
//  if it is small enough to fit into L1 cache memory.
//
