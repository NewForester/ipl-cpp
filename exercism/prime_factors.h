#if !defined(PRIME_FACTORS_H)
#define PRIME_FACTORS_H

#include <vector>

namespace prime_factors {
    std::vector<int> of(int nn) {
        std::vector<int> factors;

        for (int prime = 2; nn != 1; ++prime)
            for (; nn % prime == 0; nn /= prime)
                factors.push_back(prime);

        return factors;
    }
}
#endif

//
//  This solution recognises that smallest factor remaining must be prime.
//
//  This problem has a very simple solution:  determine the factors the
//  simplest possible way and that happens to means the factors are prime.
//  The simple solution is so simple that there is little execution time for
//  a more sophisticated solution to avoid.
//
//  There is no need for a list of primes or for boost::math::prime() (one
//  solution each).
//
//  The grounds for treating 2 as a special case is weak: you need extra code
//  and all you avoid is nn % prime half the time.
//
//  The grounds for using prime * prime > nn for early loop termination seem
//  stronger.  However, extra "What is this doing ?" code is required, the
//  square adds (significantly here) to the loop overhead (so you want to treat
//  2 as a special case as well).  Worst, it is helpful only in the case where
//  there is a large factor (but potentially very helpful).
//
//  In other problems, one compares prime with the sqrt(nn) because the latter
//  needs evaluation only once.  Here is the need for revaluation for each
//  factor (ignoring duplicates).  The fewer the factors, the more attractive
//  this approach.
//
//  The final (actually first) is whether to use one loop or a double loop.
//  The single loop code is actually longer and does not add to the clarity.
//  Some might argue one loop intertwines two ideas.  It does but where in the
//  harm in such a simple exercise ?
//
//  No.  Stick to the simple approach:  it is, at worst, O(N**½) and no
//  amount of fiddling is going to make a lot of difference.
//
