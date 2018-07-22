#if !defined(RAINDROPS_H)
#define RAINDROPS_H

#include <string>
#include <vector>

namespace raindrops {
    std::vector<std::pair<int, const char *>> drops = {
        {3, "Pling"}, {5, "Plang"}, {7, "Plong"},
    };

    std::string convert(int nn) {
        std::string sounds;

        for (auto drop : drops)
            if (nn % drop.first == 0)
                sounds += drop.second;

        return sounds.empty() ? std::to_string(nn) : sounds;
    }
}

#endif

//
//  This solution works through a table so minimising hard-coded details.
//
//  The other solutions all used an unrolled loop but were very tidy.
//
//  One checked for the otherwise case first and so used two lots of tests.
//  Another used boost::lexical_cast to convert the number to a string.  Some
//  used stringstream and to_string().
//
