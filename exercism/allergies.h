#if !defined(ALLERGIES_H)
#define ALLERGIES_H

#include <string>
#include <map>
#include <unordered_set>

namespace allergies {
    const std::map<const char *, int> allergyMap = {
        {"eggs",        1 << 0},
        {"peanuts",     1 << 1},
        {"shellfish",   1 << 2},
        {"strawberries",1 << 3},
        {"tomatoes",    1 << 4},
        {"chocolate",   1 << 5},
        {"pollen",      1 << 6},
        {"cats",        1 << 7},
    };

    class allergy_test {
    public:
        explicit allergy_test(int score): testScore(score) {}

        bool is_allergic_to(const char *allergy) const {
            try {
                return allergyMap.at(allergy) & testScore;
            } catch (...) {
                return false;
            }
        }

        std::unordered_set<std::string> get_allergies(void) const {
            std::unordered_set<std::string> allergies;

            for (auto allergy : allergyMap)
                if (allergy.second & testScore)
                    allergies.insert(allergy.first);

            return allergies;
        }
    private:
        const int testScore;
    };
}

#endif

//
//  This solution assumes is_allergic_to can return an error
//
//  It is possible that this exercise is sufficiently simple that folk tried
//  experimenting to find a better way.
//
//  The test cases obliged the return of a std::unordered_set.  While I stored
//  the test score as is and converted to std::unordered_set on request, half
//  the solutions converted to std::unordered_set in the constructor.
//
//  For conversion I used a std::map as that is simple and obvious but std::map
//  has a bad reputation among C++ programmers so only two other solutions did
//  one of those went overboard with two.
//
//  I think the idea was one map to convert bits to names in get_allergies/0
//  and a second map to convert a names to a bits in is_allergic_to/1.  One
//  solution worked around the need for two maps by using a vector of pairs
//  and explicit loops.  That sounds good but my solution used a map in one
//  direction and a for loop to walk the loop in the other.
//
//  My conversion walked the map, not the test score, which, in the general
//  case, is the less efficient approach.
//
