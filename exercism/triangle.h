#if !defined(TRIANGLE_H)
#define TRIANGLE_H

#include <stdexcept>

namespace triangle {
    enum {
        equilateral = 3,
        isosceles   = 1,
        scalene     = 0,
    };

    int kind(float a, float b, float c) {
        if (a > b)
            return kind(b, a, c);

        if (b > c)
            return kind(a, c, b);

        if (a <= 0.0)
            throw(std::domain_error("all sides must be positive"));

        if (a + b < c)
            throw(std::domain_error("triangle inequality"));

        return (a == b) + (b == c) + (c == a);
    }
}

#endif

//
//  This solution uses recursion to keep things simple.
//
//  An interesting set of solutions suggesting these guys have a degree of
//  sophistication missing on other tracks.
//
//  This track leaves it to the programmer to define the enum.  No one set the
//  values so separate determination of equilateral, isosceles and scalene was
//  required.  All named their enum and returned a value of that type.
//
//  Half sorted the lengths but none used recursion.  A couple used STL sort
//  and a couple used STL swap.
//
//  It seems these solutions were for an older versions of the problem, which a
//  fourth value indicating the lengths did not represent a triangle and a
//  throw to indicate a zero triangle but not degenerate triangles.
//
//  It was the solutions that used both the fourth value and the throw that
//  amused me.
//
//  Only one solution used helper routines:  these lead to duplication.  One
//  maverick solution defined their own template routines just for fun.
//
