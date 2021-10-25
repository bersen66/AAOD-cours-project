//
// Created by user on 23.09.2021.
//

#ifndef COURS_STORAGE_H
#define COURS_STORAGE_H

#include <map>
#include <set>

#include "date.h"
#include "task.h"

using Tasks = std::set<Task>;

class Storage {
private:
    std::map<Date, Tasks> data;
public:
    void LoadFromFile(const std::string& source);
    void Add(const Date& date, const Task& task);
    Tasks GetDailyTasks(const Date& date) const;
    void RemoveTask(const Date& date, const Task& task);
    void Write(std::ostream& out) const;
    void Clear();
};
#endif //COURS_STORAGE_H
