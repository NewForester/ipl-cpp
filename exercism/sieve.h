#if !defined(SIEVE_H)
#define SIEVE_H

#include <cstring>
#include <vector>

namespace sieve {
    std::vector<int> primes(int nn) {
        std::vector<int> primes;

        bool sieve[nn /= 2];                    // ignore even numbers
        memset(sieve, 0, sizeof(sieve));

        primes.push_back(2);

        for (int ii = 1; ii < nn; ++ii)
            if (sieve[ii] == 0) {
                const int p = ii * 2 + 1;

                primes.push_back(p);

                for (int jj = (p * p)/2; jj < nn; jj += p)
                    sieve[jj] = 1;
            }

        return primes;
    };
}

#endif

//
//  This solution makes C++ look good.
//
//  Building the primes as the filter progresses (line 22) instead of in a
//  separate pass at the end makes the square optimisation moot.
//
//  My solution is a compromise.  You can, and one did, use the square root
//  optimisation so you need a second loop to pick up to big primes.  Most,
//  however had a sieve pass and then a copy-the-primes pass.
//
//  One remarked that you can guess the number of primes in the result but
//  had not looked the logarithmic solution up on the Internet.  That allows
//  the final result to be built without reallocation.
//
//  The data structure used to store the result varied:  I used a PoC array,
//  others used vector, list, set, vector<bool> and boost::dynamic_bitset.
//  While the last two may have been efficient in terms of memory they probably
//  didn't do so well execution time wise.
//
