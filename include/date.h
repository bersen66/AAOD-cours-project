#ifndef FINAL_DATE_H
#define FINAL_DATE_H

#include <string>

#define JANUARY     1
#define FEBRUARY    2
#define MARCH       3
#define APRIL       4
#define MAY         5
#define JUNE        6
#define JULY        7
#define AUGuST      8
#define SEPTEMBER   9
#define OCTOBER     10
#define NOVEMBER    11
#define DECEMBER    12


struct Year {
    int value;
    explicit Year(int value) : value(value) {}
    bool IsLeap() const { return (value % 4 == 0 && (value % 400 == 0 || value % 100 != 0)); }
};
struct Month {
    int value;
    explicit Month(int value) : value(value) {}
};
struct Day {
    int value;
    explicit Day(int value) : value(value) {}
};

class Date {
private:
    const Year year;
    const Month month;
    const Day day;
    void IsCorrect() const;
public:
    explicit Date(Year y, Month m, Day d);

    bool operator<(const Date &date) const;

    bool operator>(const Date &date) const;

    bool operator>=(const Date &date) const;

    bool operator<=(const Date &date) const;

    bool operator==(const Date &date) const;

    bool operator!=(const Date &date) const;

    [[nodiscard]] std::string ToString(char separator = '-') const;

    friend std::ostream& operator << (std::ostream& out, const Date& date);
};


Date ParseDate(std::istringstream& is);

#ifdef DEBUGMODE
void TestLogicOperators();
void TestParseDate();
#endif

#endif //FINAL_DATE_H