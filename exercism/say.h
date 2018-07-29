#if !defined(SAY_H)
#define SAY_H

#include <cstring>
#include <stdexcept>
#include <string>

namespace say {
    const char *units[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    const char *teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    const char *tens[] = {"zero", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    const char *suffix[] = {"", " thousand ", " million ", " billion "};

    std::string threeDigits(const char *digits) {
        std::string english;

        if (*digits != '0')
            (english = units[*digits - '0']) += " hundred ";

        switch (*++digits) {
            case '0':
                if (digits[1] == '0' && !english.empty())
                    return english;

                break;

            case '1':
                return english = teens[*++digits - '0'];

            default:
                english += tens[*digits - '0'];

                if (digits[1] == '0')
                    return english;

                english += "-";
        }

        return english + units[*++digits - '0'];
    }

    std::string allDigits(const char *digits, int threesCount) {
        std::string english;

        for (; threesCount--; digits += 3)
            if (threesCount == 0 && english.empty())
                english += threeDigits(digits);
            else if (strncmp(digits, "000", 3) != 0)
                english += threeDigits(digits) + suffix[threesCount];

        while (!english.empty() && english.back() == ' ')
            english.pop_back();

        return english;
    }

    std::string in_english(long long nn) {
        std::string number = std::to_string(nn);

        if (nn < 0)
            throw std::domain_error("can't say minus");

        if (nn >= 1e12)
            throw std::domain_error("can't say trillion");

        while (number.length() % 3 != 0)
            number.insert(0, 1, '0');

        return allDigits(number.data(), number.length() / 3);
    }
}

#endif

//
//  I fail to see why this is hard and no other exercises are.
//
//  The solution examined varied a lot in detail as you would expect.  Some
//  where very long;  mine was among the shortest, even with blank lines.
//
//  All had a 'deal with thousands' routine, some followed the read me and had
//  a hundreds and even a tens routine.  Not all stuck to strict power of 10.
//  That might have seemed a good idea at the time but it does not improve the
//  code's comprehensibility.
//
//  Most used lookup tables, some const char * others std::array.  A couple
//  used maps to handle some of the irregularities well.  There was some
//  criticism of the inefficiency of maps.
//
//  To assemble the result most used concatenation which means having to right
//  trim the final result.  Two actually used boost to do this.  Two wrote their
//  own join routine but neither used the boost routine.  Two used stringstreams
//  but I fail to see the point unless you are using a set of << overloads.
//
//  Most handled the special case of 0 at the top-level, which I approve of.
//  One went for what looks like a C++17 solution.  What is `impl` ?
//
//  The most variation seemed to be how to handle the higher orders.  I used
//  recursion and was not the only one.  This was derided, of course.  A couple
//  eschewed the loop altogether, which I approve of.
//
