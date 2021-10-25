#include <storage.h>
#include <fstream>
#include <sstream>

void Storage::LoadFromFile(const std::string &path) {
    std::fstream in(path);

    if (!in.is_open())
        throw std::runtime_error("Input file is not found, check the path:" + path);

    for (std::string line; getline(in, line);) {
        std::istringstream entry(line);
        Date temp_date = ParseDate(entry);
        Task temp_task = ParseTask(entry);
        Add(temp_date, temp_task);
    }

    in.close();
}

void Storage::Add(const Date &date, const Task &task) {
    data[date].insert(task);
}

Tasks Storage::GetDailyTasks(const Date &date) const {
    return data.at(date);
}

void Storage::RemoveTask(const Date &date, const Task &task) {
    if (data.count(date) == 0) {
        return;
    }
    data[date].erase(task);
    if (data[date].empty())
        data.erase(date);
}

void Storage::Clear() {
    data.clear();
}

void Storage::Write(std::ostream &out) const {
    for (const auto& [date, tasks] : data) {
        for (const auto& task : tasks) {
            out << date << " " << task.deadline << " " << task.description << "\n";
        }
    }
}

