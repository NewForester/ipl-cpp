#if !defined(ROBOT_NAME_H)
#define ROBOT_NAME_H

#include <chrono>
#include <cstdio>
#include <random>
#include <string>

namespace robot_name {
    using namespace std;

    class robot {
    public:
        robot(): robot_name(newName()) {}

        string name(void) const {
            return robot_name;
        }

        void reset(void) {
            robot_name = newName();
        }
    private:
        string robot_name;

        static string newName() {
            static default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());

            static uniform_int_distribution<int> distribution(1, 26 * 26 * 1000);

            char name[8];

            int rn = distribution(generator);

            sprintf(name, "%c%c%03d", makeLetter(rn / 1000 / 26), makeLetter(rn / 1000), rn % 1000);

            return string(name);
        }

        static char makeLetter(int nn) {
            return nn % 26 + 'A';
        }
    };
}

#endif

//
//  This solution generates one random number from the same sequence for each
//  robot name.  This way there is no need to keep track of names already used.
//  It also seems to me to be necessary to create the RNG once and only once
//  which I have done by declaring things static.  I hope this aspect of C++
//  has not changed since I last used it.
//
//  The students had a poor grasp of what this exercise was asking for (as
//  opposed to what it could test for).  It asks of random names but can only
//  check for (limited) uniqueness.
//
//  One student used the read time clock and some magic.  He sort of guaranteed
//  uniqueness and didn't need the magic.  Two used C++ random number generator
//  but all the rest used the C rand() function, which has a number of drawbacks.
//  However, all needed 5 random numbers to create a new name.  This might still
//  be random but you loose the guarantee of uniqueness of a PRNG so need to check
//  for duplicates.
//
//  Furthermore, for many each instance of robot has is own random number
//  sequence with nothing to say it isn't the same for all of instances.  Code
//  the guarantees uniqueness by retrying might pass the tests but at higher and
//  higher cost as the number of robots increases.
//
//  Not all solutions had a uniqueness check but those that did either used a
//  unique set and count (apparently the same cost as find) or a vector and
//  find.  The student made a meal of this one and I'm not sure why.
//
//  At least the uniqueness checks appeared to use a common (aka static)
//  collection of names.
//
