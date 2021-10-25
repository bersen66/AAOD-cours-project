#include <string>
#include <time_keeper.h>
#include <task.h>

Task::Task(const TimeKeeper &deadline, const std::string &description)
        : deadline(deadline), description(description) {}

bool Task::operator<(const Task &rhs) const {
    return deadline < rhs.deadline;
}

bool Task::operator>(const Task &rhs) const {
    return rhs    < *this;
}

bool Task::operator<=(const Task &rhs) const {
    return !(rhs < *this);
}

bool Task::operator>=(const Task &rhs) const {
    return !(*this < rhs);
}

bool Task::operator==(const Task &rhs) const {
    return deadline == rhs.deadline &&
           description == rhs.description;
}

bool Task::operator!=(const Task &rhs) const {
    return !(rhs == *this);
}

Task ParseTask(std::istringstream& is) {
    TimeKeeper dl = ParseTime(is);
    std::string description;
    std::getline(is, description);
    return {dl, description};
}

std::ostream& operator<<(std::ostream& out, const Task& t) {
    out << "Deadline:" << t.deadline << " " << t.description;
    return out;
}