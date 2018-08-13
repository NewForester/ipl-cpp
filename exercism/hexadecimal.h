#if !defined(HEXADECIMAL_H)
#define HEXADECIMAL_H

#include <algorithm>
#include <cctype>
#include <string>
#include <utility>

namespace hexadecimal {
    using outcome = std::pair<bool, int>;

    const std::string hexdigits = "0123456789abcdef";

    int convert(const std::string &ss) {
        auto result = std::accumulate(ss.begin(), ss.end(), outcome(true, 0),
            [] (outcome sofar, char hex) {
                const size_t xigit = hexdigits.find(tolower(hex));

                sofar.first &= (xigit != std::string::npos);
                sofar.second = (sofar.second << 4) + xigit;

                return sofar;
            });

        return result.first ? result.second : 0;
    }
}

#endif

//
//  This solution drops the recursion and uses std::accumulate instead.  It
//  uses std::pair to return an error and so avoid throwing and catching an
//  exception.  I know, very go.
//
