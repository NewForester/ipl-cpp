#if !defined(TRINARY_H)
#define TRINARY_H

#include <utility>

namespace trinary {
    using couple = std::pair<int, int>;

    couple recurse(const char *trinary) {
        switch (*trinary) {
            case '\0':  return couple(0, 1);
            case '0':   break;
            case '1':   break;
            case '2':   break;
            default:    return couple(0, 0);
        }

        auto result = recurse(trinary + 1);

        int increment = result.second * (*trinary - '0');

        return couple(result.first + increment, result.second * 3);
    }

    int to_decimal(const char *trinary) {
        recurse(trinary).first;
    }
}

#endif

//
//  This solution is based on the solution to the binary exercise.
//
//  The variety showed by the solution examined suggested there is no obvious
//  approach to solving this or students did not take the exercise seriously.
//
//  Odd because it is so simple.  Some took an imperative approach, other used
//  STL.  None used recursion.
//
//  One of the imperative solutions really did make the problem look simple so
//  one has to wonder why the others were faffing around with pow() and too
//  many local variables.
//
//  Thw STL (aka functional) solutions looked ugly, thanks to C++ syntax, and
//  needed two passes - any_of for validation and accumulate for evaluation.
//
//  It is said the functional approach is "describe what to do, not how to do".
//  However, the solutions here show that the simple, trivial, lambda functions
//  describe 'how', not 'what', in great detail.  The rest, be it 'for' or
//  'accumulate' is boiler plate, just very different boiler plate.
//
