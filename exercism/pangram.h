#if !defined(PANGRAM_H)
#define PANGRAM_H

#include <algorithm>
#include <cctype>
#include <string>

namespace pangram {
    const std::string lewand = "zqxjkvbpygfwmucldrhsnioate";      // least common letter first, most common last

    bool is_pangram(const std::string text) {
        return std::all_of(lewand.begin(), lewand.end(),
            [text] (int letter) {
                return std::any_of(text.begin(), text.end(),
                    [letter] (int character) {
                        return tolower(character) == letter;
                    });
            });
    }
}

#endif

//
//  This is my classic solution where algorithm trumps language idiom.
//
//  In comparison with the other solutions examined, my solution is not
//  longer in terms of lines but it looks dense.
//
//  5 of the solutions used a bit mask.  Two of them used std::bitset and
//  two of them stopped early.
//
//  1 used boost and needed more header files than lines of code.  I could not
//  understand it since I don't know boost but that is no reason to describe
//  it as complex.  I guess the problem does not require the power of boost.
//
//  2 used a letter count and one was spoilt by using std::min_element to 'make
//  it more compact'.
//
//  Mine remains unsatisfactory because of the C++ overblown syntax and I'd
//  prefer the bitset solutions if it weren't for the extra state involved.
//
