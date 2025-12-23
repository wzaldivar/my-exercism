#include "gigasecond.h"

namespace gigasecond {
    boost::posix_time::ptime advance(boost::posix_time::ptime start_time){
        return start_time + boost::posix_time::seconds(GIGASECOND);
    }
}  // namespace gigasecond
