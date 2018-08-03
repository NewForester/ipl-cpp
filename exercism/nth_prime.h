#if !defined(PRIME_H)
#define PRIME_H

#include <algorithm>
#include <stdexcept>
#include <vector>

namespace prime {
    int nth(int nth) {
        if (nth <= 0)
            throw std::domain_error("need a positive ordinal");

        std::vector<int> primes;
        primes.push_back(2);

        for (int candidate = 3; nth > primes.size(); candidate += 2)
            if (!std::any_of(primes.begin(), primes.end(), [candidate] (int prime) {return candidate % prime == 0;}))
                primes.push_back(candidate);

        return primes.back();
    }
}

#endif

//
//  This solution is compact because it uses a lambda function.
//
//  The solutions examined showed considerable variety.  Not all represented
//  attempts to be efficient.
//
//  A couple of solutions used a template so avoiding having to decide how big
//  the parameter to nth is.  A couple used a static vector of primes so that
//  repeated calls would be fast but their solutions were not thread safe.
//
//  Internally there was some fiddling with the starting conditions, some like
//  mine so they need only consider odd numbers, one so they could estimate
//  the number of candidates they would need to consider.
//
//  Most built up a list of primes, as mine does.  These use a vector and don't
//  reserve any space in order to avoid reallocation overhead.
//
//  One went for a sieve of Eratosthenes and used boost::dynamic_bitset and one
//  solution using the "Wheel Sieve" with no memory of primes already seen.
//
//  I am intrigued enough to want to try benchmarking this.
//
