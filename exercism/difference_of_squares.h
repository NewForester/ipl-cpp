#if !defined(DOS_H)
#define DOS_H

namespace squares {
    int square_of_sums(int nn) {
        int sum = nn * (nn + 1) / 2;

        return sum * sum;
    }

    int sum_of_squares(int nn) {
        return nn * (nn + 1) * (2 * nn + 1) / 6;
    }

    int difference(int nn) {
        return square_of_sums(nn) - sum_of_squares(nn);
    }
}

#endif

//
//  This is the algebraic solution.  I've no idea how to do it in C++.
//
//  Well it seems no one else does.  Half the solutions were C for loops;
//  2 used (semi) algebraic solutions, one uses casts and one submitted
//  only a header file.  What a waste.
//
