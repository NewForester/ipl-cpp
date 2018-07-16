#if !defined(SOM_H)
#define SOM_H

#include <set>
#include <unordered_set>

namespace sum_of_multiples {
    int to(const std::set<int> &factors, int limit) {
        int sum = 0;

        std::unordered_set<int> multiples;
        for (auto factor : factors)
            for (int nn = factor; nn < limit; nn += factor)
                if (multiples.insert(nn).second)
                    sum += nn;

        return sum;
    }
}

#endif

//
//  This solution uses a set to ensure multiples are not counted twice.
//
//  This is a double loop so there is a choice as to which is the inner and
//  which is the outer.  The other eight solutions split half and half.  It
//  may depend of the choice of limit and the number of factors as to which
//  is the faster.
//
//  Those that loop on limit as the outer limit as simpler.  One used
//  find_if instead of the inner loop.
//
//  Those that loop on factors need to avoid or compensate for double counting
//  One appeared to duck this issue.  The two that did used accumulate() to sum
//  the multiples at the end.  In either case, using the set requires more
//  memory.
//
//  The odd one out looked a mess but was trying to use algebra to avoid the
//  inner loop.  It reminded me of my attempt at being too clever on the Python
//  track.
//
//  One sneaky point is that the factors are passed in from the tests as an
//  initialiser list.  Thus the factors could be declared as a set.  This, in
//  general avoid the need to handle duplication.  It also sorts the members.
//  One solution took advantage of this but that may be a presumption too far.
//
