#if !defined(SCRABBLE_SCORE_H)
#define SCRABBLE_SCORE_H

#include <cctype>
#include <string>
#include <vector>

namespace scrabble_score {
    using namespace std;

    const vector<pair<const string, const int>> scores = {
        {"A, E, I, O, U",   1},
        {"L, N, R, S, T",   1},
        {"D, G",            2},
        {"B, C, M, P",      3},
        {"F, H, V, W, Y",   4},
        {"K",               5},
        {"J, X",            8},
        {"Q, Z",           10},
    };

    int score_letter(char letter) {
        for (auto score : scores)
            if (score.first.find(toupper(letter)) != string::npos)
                return score.second;

        return 0;
    }

    int score(const char *word) {
        int sum = 0;

        for (auto letter : std::string(word))
            sum += score_letter(letter);

        return sum;
    }
}

#endif

//
//  This solution is as simple as it gets without restructuring the scores.
//
//  I used a representation of the scores as in the read me.  Most solutions
//  had this restructured so they could use a map, which is faster but probably
//  uses more memory.  A couple flattened the map to an C array and used
//  straight table lookup.
//
//  Most has subroutines but in some it was hidden in a lambda.  This was
//  typical of those that used accumulate() instead of an outer loop.
//
//  The version of this exercise did not define what happens if a letter is
//  not one of the 26.  Some solutions would return 0 by accident.
//
