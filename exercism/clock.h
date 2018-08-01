#if !defined(CLOCK_H)
#define CLOCK_H

#include <string>
#include <sstream>

namespace date_independent {
    class clock {
        explicit clock(int time) {
            while (time > 0)
                time -= 24 * 60;

            while (time < 0)
                time += 24 * 60;

            this->time = time;
        }

    public:
        static clock at(int hour, int minutes) {
            return clock(hour * 60 + minutes);
        }

        clock plus(int increment) const {
            return clock(time + increment);
        }

        operator std::string() const {
            std::stringstream time_string;

            time_string.fill('0');
            time_string.width(2);
            time_string << (time / 60);
            time_string << ':';
            time_string.width(2);
            time_string << (time % 60);

            return time_string.str();
        }
    private:
        int time;

    friend bool operator==(const clock, const clock);
    friend bool operator!=(const clock, const clock);
    };

    bool operator==(const clock lhs, const clock rhs) {
        return lhs.time == rhs.time;
    }

    bool operator!=(const clock lhs, const clock rhs) {
        return lhs.time != rhs.time;
    }
}

#endif

//
//  This solution uses a std::stringstream to format the time for printing.
//
//  I think there are two design decisions to make here.  One is to decide
//  on the internal representation, the second is whether to 'normalise' on
//  input (add etc) or normalise on output (print).
//
//  All but one of the other solutions examined chose to use two integers for
//  their internal representation and all chose to normalise on input.
//
//  I agree with the second but boy is string formatting a pain in C/C++.  One
//  solution used sprintf, four stringstream and three did it a hard way.
//
//  I disagree with using two integers internally.  If you choose to use one,
//  then objects are trivial and creating and returning them is simple.  It is
//  then natural to normalise in the constructor and everything else (add ...)
//  becomes really simple.
//
//  My first `while` should read `while (time > 24 * 60)` but otherwise fine.
//
