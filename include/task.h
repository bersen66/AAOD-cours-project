#ifndef COURS_TASK_H
#define COURS_TASK_H

#include <string>
#include <sstream>


#include "date.h"
#include "time_keeper.h"



struct Task {
    const TimeKeeper deadline;
    const std::string description;

    Task(const TimeKeeper &deadline, const std::string &description);
    bool operator<(const Task &rhs) const;
    bool operator>(const Task &rhs) const;
    bool operator<=(const Task &rhs) const;
    bool operator>=(const Task &rhs) const;
    bool operator==(const Task &rhs) const;
    bool operator!=(const Task &rhs) const;
    friend std::ostream& operator<<(std::ostream& out, const Task& t);
};

Task ParseTask(std::istringstream& is);

#endif //COURS_TASK_H
