#if !defined(DNA_COUNT_H)
#define DNA_COUNT_H

#include <map>
#include <stdexcept>
#include <string>

namespace dna {
    using namespace std;

    bool valid(char nucleotide) {
        if (string("ATCG").find(nucleotide) == string::npos)
            throw(invalid_argument("invalid nucleotide"));

        return true;
    }

    void count_nucleotides(const char *strand, map<char, int> &counts) {
        for(auto nucleotide : string("ATCG"))
            counts[nucleotide] = 0;

        for(auto nucleotide : string(strand))
            if (valid(nucleotide))
                counts[nucleotide] += 1;
    }

    class counter {
    public:
        explicit counter(const char *strand) {
            count_nucleotides(strand, counts);
        }

        int count(char nucleotide) const {
            if (valid(nucleotide))
                return counts.at(nucleotide);
        }

        map<char, int> nucleotide_counts(void) const {
            return counts;
        };

    private:
        map<char, int> counts;
    };
}

#endif

//
//  This includes a throw from the constructor, which used to be frowned upon.
//
//  The other solutions may have been the oldest on the track.  All different,
//  none astonishingly more appealing than mine.  None used helper functions.
//
//  A fair number used an (older ? but perhaps clearer) form of for-loop:
//
//    for each (char c in input)
//
//  Some used an initialiser list to initialise the map, one doing so in the
//  constructor's initialiser list.  Once initialised, you can do a find on
//  in to 'validate' nucleotides.
//
//  Several used just plain counts[nucleotide]++.
//
//  Several used counts.at() to produce exceptions (an earlier version where
//  no one cares about the message perhaps).  One did this in a try block,
//  caught the exception and raised another with the correct message.
//
//  A couple used iterators explicitly and one subscripts.
//
//  There was some discussion about throwing in a constructor but is was
//  centred on doing this properly rather than not at all.
//
//  There was also some discussion of the efficiency of passing in a string.  I
//  think I was the only one to use const char *.
//
