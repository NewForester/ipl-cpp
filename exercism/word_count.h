#if !defined(WORD_COUNT_H)
#define WORD_COUNT_H

#include <algorithm>
#include <cctype>
#include <map>
#include <string>

using namespace std;
using wordCountMap = map<string, int>;

namespace word_count {
    void updateMap(wordCountMap &wordMap, string key) {
        if (key.front() == '\'')
            key.erase(key.begin());

        if (key.back() == '\'')
            key.erase(key.end() - 1);

        if (key.length() != 0)
            wordMap[key] = wordMap[key] + 1;
    }

    wordCountMap words (string input) {
        wordCountMap wordMap;

        const auto letters = string("abcdefghijklmnopqrstuvwxyz'01234567890");

        transform(input.begin(), input.end(), input.begin(), ::tolower);

        size_t bpos = input.find_first_of(letters);
        size_t epos = input.find_first_not_of(letters, bpos);

        while (epos != string::npos) {
            updateMap(wordMap, input.substr(bpos, epos - bpos));

            bpos = input.find_first_of(letters, epos + 1);
            epos = input.find_first_not_of(letters, bpos);
        }

        if (bpos != string::npos)
            updateMap(wordMap, input.substr(bpos));

        return wordMap;
    }
}

#endif

//
//  This took longer to write that it should have.  The README said to use the
//  standard library instead of implementing your own low level routines.  What
//  standard library features ?  There is not even a split routine.  That led
//  me to look at using regex to split a string into a number of substrings.
//  It seems it won't do that but not after more faffing around because the old
//  compiler I have does not do them properly.
//
//  I was really curious about what other people did ...
//
//  One submitted only a header file; one used boost::split, another used a
//  sregex_iterator and my favourite used a string stream.  So half implemented
//  low level routines and tried four verbose ways of hiding this.
//
//  The boost::split solution also used boost::trim and was 37 lines  See
//  boot/algorithm/string.hpp.
//
//  The regex you would never guess.  It was 23 lines, partly because the regex
//  deals with the apostrophe problem.
//
//  The string stream solution was 38 lines but had to deal with the apostrophe
//  problem up top and left itself open to access off either end of the string.
//
