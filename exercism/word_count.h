#if !defined(WORD_COUNT_H)
#define WORD_COUNT_H

#include <algorithm>
#include <cctype>
#include <map>
#include <regex>
#include <string>

namespace word_count {
    using namespace std;

    const regex match_word ("(\\w+|\\w+'\\w+)");

    map<string, int> words (string input) {
        map<string, int> wordMap;

        transform(input.begin(), input.end(), input.begin(), ::tolower);

        auto it_begin = sregex_iterator(input.begin(), input.end(), match_word);
        auto it_end = sregex_iterator();

        for (sregex_iterator it = it_begin; it != it_end; ++it)
            wordMap[(*it).str()] += 1;

        return wordMap;
    }
}

#endif

//
//  This solution uses regex to split words, which is what I had wanted to do
//  from the start but did not know how.
//
