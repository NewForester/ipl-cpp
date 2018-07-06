#if !defined(ANAGRAM_H)
#define ANAGRAM_H

#include <algorithm>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

namespace anagram {
    string tolowercase(string word) {
        string lower = string(word);

        transform (lower.begin(), lower.end(), lower.begin(),
            [] (char cc) {return tolower(cc);});

        return lower;
    }

    class anagram {
    public:
        anagram(const string word): word (word) {
            lower = tolowercase(word);

            sorted = string(lower);
            sort(sorted.begin(), sorted.end());
        }

    public:
        vector<string> matches(std::initializer_list<string> wordlist) const {
            auto anagramlist = new vector<string>;

            for_each (wordlist.begin(), wordlist.end(),
                [anagramlist, this] (const string word) {
                    string tmp = tolowercase(word);

                    if (tmp == this->lower)
                        return;

                    sort(tmp.begin(), tmp.end());

                    if (tmp.compare(this->sorted) == 0)
                        anagramlist->push_back(word);
                }
            );

            return *anagramlist;
        }

    private:
        const string word;
        string lower;
        string sorted;
    };
}

#endif

//
//  This solution seems so long and ugly compared with other languages.
//
//  Of the 8, 2 were just headers, one used find/erase, another just erase,
//  one was written in C (complete the malloc).  The other 3 were like mine
//  only better - shorter for a start.
//
//  They did not have the fight I had with a compiler and so were able to
//  present good code.  I will have to try again.
//
