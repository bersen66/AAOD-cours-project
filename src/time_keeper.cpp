#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

#include "time_keeper.h"

/**
 * @returns relation identifier
 * 1 if lhs > rhs,
 * 0 if lhs == rhs,
 * -1 lhs < rhs
*/
int TimeKeeper::compare(const TimeKeeper& rhs) const {
    int lhs_seconds_val = h.value * 3600 + m.value * 60 + s.value;
    int rhs_seconds_val = rhs.h.value * 3600 + rhs.m.value * 60 + rhs.s.value;

    if (lhs_seconds_val == rhs_seconds_val)
        return 0;
    if (lhs_seconds_val < rhs_seconds_val)
        return -1;
    return 1;
}

TimeKeeper::TimeKeeper(const Hour &h, const Minute &m, const Second &s) : h(h), m(m), s(s) {}

bool TimeKeeper::operator<(const TimeKeeper &rhs) const {
    return compare(rhs) == -1;
}

bool TimeKeeper::operator>(const TimeKeeper &rhs) const {
    return rhs < *this;
}

bool TimeKeeper::operator<=(const TimeKeeper &rhs) const {
    return !(rhs < *this);
}

bool TimeKeeper::operator>=(const TimeKeeper &rhs) const {
    return !(*this < rhs);
}

bool TimeKeeper::operator==(const TimeKeeper &rhs) const {
    return compare(rhs) == 0;
}

bool TimeKeeper::operator!=(const TimeKeeper &rhs) const {
    return !(rhs == *this);
}


std::string TimeKeeper::ToString(char separator) const {
    std::stringstream out;
    out << std::setw(2) << std::setfill('0') << h.value << separator
        << std::setw(2) << std::setfill('0') << m.value << separator
        << std::setw(2) << std::setfill('0') << s.value;
    return out.str();
}



TimeKeeper ParseTime(std::istringstream& is) {
    int hour, minute, second;
    is >> hour;
    is.ignore();
    is >> minute;
    is.ignore();
    is >> second;
    return TimeKeeper{Hour(hour), Minute(minute), Second(second)};
}

std::ostream& operator<<(std::ostream& in, const TimeKeeper& time) {
    in << time.ToString();
    return in;
}

