#if !defined(ANAGRAM_H)
#define ANAGRAM_H

#include <algorithm>
#include <cctype>
#include <string>
#include <vector>

namespace anagram {
    using namespace std;

    string lowerLetters(string word) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);

        return word;
    }

    string sortLetters(string word) {
        sort(word.begin(), word.end());

        return word;
    }

    class anagram {
    public:
        explicit anagram(const string word): word (word),
            lowerWord (lowerLetters(word)), sortedWord (sortLetters(lowerWord)) {}

        bool isAnagram(const string word) const {
            const string candidate = lowerLetters(string(word));

            return candidate != lowerWord && sortLetters(candidate) == sortedWord;
        }

        vector<string> matches(const vector<string> candidates) const {
            std::vector<string> anagramlist;

            for (auto candidate : candidates)
                if (isAnagram(candidate))
                    anagramlist.push_back(candidate);

            return anagramlist;
        }

    private:
        const string word, lowerWord, sortedWord;
    };
}

#endif

//
//  Better, none of the awkwardness of the first.  Still 50 lines when the
//  best of the others are only about 40.
//
