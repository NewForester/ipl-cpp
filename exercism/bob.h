#if !defined(BOB_H)
#define BOB_H

#include <cctype>

namespace bob {
    bool isShouting(const char *pp) {
        bool alpha = false;

        for (; *pp; ++pp) {
            alpha |= isalpha(*pp);

            if (islower(*pp))
                break;
        }

        return alpha && ! *pp;
    }

    bool isQuestion(const char *pp) {
        bool question = false;

        for (; *pp; ++pp)
            if (! isspace(*pp))
                question = *pp == '?';

        return question;
    }

    bool isSilence(const char *pp) {
        for (; *pp; ++pp)
            if (! isspace(*pp))
                break;

        return ! *pp;
    }

    const char *hey(const char *prompt) {
        if (isShouting(prompt))
            return ("Whoa, chill out!");

        if (isQuestion(prompt))
            return ("Sure.");

        if (isSilence(prompt))
            return ("Fine. Be that way!");

        return "Whatever.";
    }
}

#endif

//
//  Another C solution in C++ that does not use the string class.
//
//  Everyone else used std:string as expected.  Their solution were not, on
//  the whole shorter than mine.  Two went as far as creating a whole class.
//
//  Many had helper routines with friendly names as I have.  Just as well
//  since often the contents of the routines were sadly not evident.
//
//  I saw use of routines with _copy as a suffix and also any_of.  It just
//  still seems that C++ source code is bloated and self-important.  Patience.
//
//  I could try this again with the string class but that is for another time.
//
