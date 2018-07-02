#if !defined(LEAP_H)
#define LEAP_H

namespace leap {
    bool is_leap_year(int year) {
        return ! (year % (year % 100 ? 4 : 400));
    }
}

#endif

//
//  This is classic bad boy C/C++.
//
//  One solution was completely off the wall.   Of the others,
//  all used the && || construction but most of those evaluated
//  three bools first.  Did I miss something.
//
