#if !defined(GIGASECOND_H)
#define GIGASECOND_H

#include "boost/date_time/posix_time/posix_time.hpp"

namespace gigasecond {
    static const long GIGASECOND = 1000000000;

    boost::posix_time::ptime advance(boost::posix_time::ptime start_time);
}  // namespace gigasecond

#endif // GIGASECOND_H