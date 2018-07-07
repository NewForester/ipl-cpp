#if !defined(ETL_H)
#define ETL_H

#include <cctype>
#include <map>
#include <vector>

namespace etl {
    std::map<char, int> transform(std::map<int, std::vector<char>> oldMap) {
        std::map<char, int> newMap;

        for (auto oldScore : oldMap)
            for (auto letter : oldScore.second)
                newMap.insert(std::pair<char, int>(tolower(letter), oldScore.first));

        return newMap;
    }
}

#endif

//
//  Another simple problem with a simple solution.
//  Installing Boost was something else.
//
//  Again, one submission was just a header.  The others, overall, had the same
//  shape as mine.  One or two had a couple of strange ideas.  The useful thing,
//  although not worth a second iteration, is that I could have expressed the
//  insertion into the map as:
//
//    newMap[tolower(letter)] = oldScore.first;
//
//  There were several ways the characters were converted to lower case.  It is
//  possible that std::tolower is more 'idiomatic' that ::tolower.  The smart
//  one looked like an attempt to make the conversion locale dependent.
//
