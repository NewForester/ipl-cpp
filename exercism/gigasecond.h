#if !defined(GIGASECOND_H)
#define GIGASECOND_H

#include "boost/date_time/posix_time/posix_time.hpp"

namespace gigasecond {
    using namespace boost::posix_time;

    ptime advance(ptime start) {
        return start + seconds(1000000000);
    }
}

#endif

//
//  This solution is as expected:  most trivial
//
//  Again the French speaker was off the wall.
//  All others are equivalent to mine but made heavy work of it.
//
