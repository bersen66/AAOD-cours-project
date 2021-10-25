#include <sstream>
#include <iostream>
#include <iomanip>

#include "date.h"


Date::Date(Year y, Month m, Day d) : year(y), month(m), day(d) {
    IsCorrect();
}

// Можно ли без хардкода?
void Date::IsCorrect() const {
    std::stringstream errorInfo;
    if (year.value < 0) {
        errorInfo << "\ninvalid year value, expected natural value, has " << year.value;
        throw std::runtime_error(errorInfo.str());
    }
    if (month.value <= 0 || month.value > 12) {
        errorInfo << "invalid month value, expected value belongs to [1,12] interval, has " << month.value;
        throw std::runtime_error(errorInfo.str());
    }
    if (day.value <= 0 || day.value >= 32) {
        errorInfo << "invalid day value, expected value belongs to [1,31] interval, has " << day.value;
        throw std::runtime_error(errorInfo.str());
    }
    if (month.value == APRIL || month.value == JUNE ||
        month.value == SEPTEMBER || month.value == NOVEMBER) {
        if (day.value > 30) {
            errorInfo << "invalid day value, expected value belongs to [1,30] interval, has " << day.value;
            throw std::runtime_error(errorInfo.str());
        }
    }
    if (month.value == FEBRUARY) {

        if (year.IsLeap()) {
            if (day.value > 29) {
                errorInfo << "invalid day value, expected value belongs to [1,29] interval, has " << day.value;
                throw std::runtime_error(errorInfo.str());
            }
        } else if (day.value > 28) {
            errorInfo << "invalid day value, expected value belongs to [1,28] interval, has " << day.value;
            throw std::runtime_error(errorInfo.str());
        }
    }
}

std::string Date::ToString(char separator) const {
    std::stringstream stringstr;
    stringstr << std::setw(4) << std::setfill('0') << year.value << separator
              << std::setw(2) << std::setfill('0') << month.value << separator
              << std::setw(2) << std::setfill('0') << day.value;
    return stringstr.str();
}

bool Date::operator>=(const Date &date) const {
    return (*this) > date || (*this) == date;
}

bool Date::operator<=(const Date &date) const {
    return (*this) < date || (*this) == date;
}

bool Date::operator<(const Date &date) const {
    return this->ToString() < date.ToString();
}

bool Date::operator>(const Date &date) const {
    return !((*this) <= date);
}

bool Date::operator==(const Date &date) const {
    return (year.value == date.year.value)
           && (month.value == date.month.value)
           && (day.value == date.day.value);
}

bool Date::operator!=(const Date &date) const {
    return !((*this) == date);
}

std::ostream &operator<<(std::ostream &out, const Date &date) {
    out << date.ToString();
    return out;
}


Date ParseDate(std::istringstream& is) {
    int year, month, day;
    is >> year;
    is.ignore();
    is >> month;
    is.ignore();
    is >> day;
    return Date(Year(year), Month(month), Day(day));
}