#if !defined(SAY_H)
#define SAY_H

#include <cstring>
#include <stdexcept>
#include <string>

namespace say {
    std::string &join(std::string &accumulator, const char *text, const char separator = ' ') {
        return (accumulator.empty() ? accumulator : accumulator += separator) += text;
    }

    std::string &hundreds(std::string &accumulator, long long nn) {
        const static char *numbers[] = {
            "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
            "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
            "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

        if (nn >= 100)
            join(join(accumulator, numbers[nn / 100]), "hundred");

        if ((nn %= 100) >= 20)
            if (nn % 10)
                join(join(accumulator, numbers[nn / 10 + 18]), numbers[nn % 10], '-');
            else
                join(accumulator, numbers[nn / 10 + 18]);
        else if (nn)
            join(accumulator, numbers[nn]);

        return accumulator;
    }

    std::string in_english(long long nn) {
        if (nn == 0)
            return "zero";

        if (nn < 0)
            throw std::domain_error("can't say minus");

        if (nn >= 1e12)
            throw std::domain_error("can't say trillion");

        const static char *suffix[] = {"thousand", "million", "billion"};

        std::string english;

        long long radix = 1e9;
        for (int count = 3; count--; nn %= radix, radix /= 1000)
            if (nn >= radix)
                join(hundreds(english, nn / radix), suffix[count]);

        hundreds(english, nn);

        return english;
    }
}

#endif

//
//  This solution uses the number without conversion to a string.
//  This means is has to decode from 'left-to-right' but it allows
//  for a number of 'optimisations' some of which were inspired by
//  the other solutions examined.  Even with my join() routine, the
//  result is shorter, in terms of lines, by about 20%.
//
