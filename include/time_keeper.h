//
// Created by user on 23.09.2021.
//

#ifndef ALGO_TIME_H
#define ALGO_TIME_H

#include <iostream>

struct Hour {
    int value;
    explicit Hour(int val) : value(val % 24){};
};

struct Minute {
    int value;
    explicit Minute(int val) : value(val % 60){};
};

struct Second {
    int value;
    explicit Second(int val) : value(val % 60){};
};

class TimeKeeper {
public:

    int compare(const TimeKeeper& rhs) const;
    explicit TimeKeeper(const Hour &h, const Minute &m, const Second &s);

    bool operator<(const TimeKeeper &rhs) const;

    bool operator>(const TimeKeeper &rhs) const;

    bool operator<=(const TimeKeeper &rhs) const;

    bool operator==(const TimeKeeper &rhs) const;

    bool operator!=(const TimeKeeper &rhs) const;

    bool operator>=(const TimeKeeper &rhs) const;

    std::string ToString(char separator = ':') const;

    //friend std::istream& operator>>(std::istream& in, TimeKeeper& time);
    friend std::ostream& operator<<(std::ostream& in, const TimeKeeper& time);

private:
    const Hour h;
    const Minute m;
    const Second s;
};


TimeKeeper ParseTime(std::istringstream& is);

#endif //ALGO_TIME_H
