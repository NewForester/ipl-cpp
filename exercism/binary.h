#if !defined(BINARY_H)
#define BINARY_H

#include <utility>

namespace binary {
    using couple = std::pair<int, int>;

    couple recurse(const char *binary) {
        switch (*binary) {
            case '\0':  return couple(0, 1);
            case '0':   break;
            case '1':   break;
            default:    return couple(0, 0);
        }

        auto result = recurse(binary + 1);

        return couple(result.first + (*binary == '1') * result.second, result.second << 1);
    }

    int convert(const char *binary) {
        recurse(binary).first;
    }
}

#endif

//
//  This solution uses recursion to process the string right to left.
//
//  Ignoring my recursive fancy, you need a loop over the input characters.
//  Everyone used a different way of expressing the loop.  The loop is either
//  forward or backwards.
//
//  With each iteration you calculate the term and add it to an accumulator.
//  For a forward loop, double the accumulator value and add 1 or 0.  For a
//  backward loop you need the last term:  shift by 1 and add or don't add it
//  to the accumulator.  Almost all solutions were more complicated.
//
//  This is a fold (or even reduce) with complications.  The need to detect an
//  error complicates matter and that is why I used recursion to give the effect
//  of a reverse iterator.  I need not have used recursion.
//
//  The one chap who did attempt to use the STL used accumulate() (good) but
//  the the error checking as a separate pass.  Oh dear.
//
