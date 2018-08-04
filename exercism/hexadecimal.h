#if !defined(HEXADECIMAL_H)
#define HEXADECIMAL_H

#include <cctype>
#include <string>
#include <utility>

namespace hexadecimal {
    using couple = std::pair<int, int>;

    const std::string hexdigits = "0123456789abcdef";

    couple recurse(const char *hex) {
        const int xigit = hexdigits.find(tolower(*hex));

        if (xigit == std::string::npos)
            return couple(0, *hex == '\0');

        const auto result = recurse(hex + 1);

        const int increment = result.second * xigit;

        return couple(result.first + increment, result.second * 16);
    }

    int convert(const char *hex) {
        recurse(hex).first;
    }
}

#endif

//
//  This solution follows the design of my binary and ternary solutions.
//
//  This is a job for std::accumulate and a simple lambda.  My preference is
//  for one that uses string::find but everyone did it the hard way, even the
//  solution that used string::find (the opposite) as validation.
//
//  The trouble with using std::accumulate is how to return 0 given invalid
//  input.  Both solutions threw and caught an exception.
//
//  Next option is whether to have a separate validation pass.  This is ok on
//  short strings (as here) especially if that simplifies the evaluation pass
//  (as it should).  A couple of solutions did this well and another badly.
//
//  One solution used the experimental nullopt which looks closer to my return
//  of pair<>.  These don't really help.
//
//  Finally, you can do both at once, in which case, you need only one loop, no
//  subroutine and you just return if you find an invalid character.
//
//  Odd no one tried a validation pass followed by std::accumulate.  Also odd
//  is that only one used isxdigit() for validation.
//
//  Two used math::pow but only one used << 4 to produce powers of 16.
//
