#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "date.h"
#include "time_keeper.h"
#include "task.h"
#include "storage.h"

using namespace std;


void ExecuteApp() {

    Storage st;
    const string backup = "backup.txt";

    try {
        st.LoadFromFile(backup);
    } catch (runtime_error e) {
        ofstream out(backup);
        out.close();
    }

    while (true) {
        string line;
        getline(cin, line);
        istringstream is(line);

        string command;
        is >> command;

        if (command == "END") {
            ofstream saveFile(backup, ios::trunc);
            st.Write(saveFile);
            saveFile.close();
            break;
        } else if (command == "LOAD") {
            string path;
            is >> path;
            try {
                st.LoadFromFile(path);
            } catch (exception &e) {
                cerr << e.what() << endl;
            }
        } else if (command == "ADD") {
            Date date = ParseDate(is);
            Task task = ParseTask(is);
            st.Add(date, task);
        } else if (command == "GET_DAILY") {
            Date date = ParseDate(is);
            try {
                Tasks tasks = st.GetDailyTasks(date);
                for (auto &task : tasks) {
                    cout << task << endl;
                }
            } catch (exception &e) {
                cerr << e.what() << endl;
            }

        } else if (command == "REMOVE") {
            Date date = ParseDate(is);
            Task task = ParseTask(is);
            st.RemoveTask(date, task);
        } else if (command == "WRITE") {
            string destFlag;
            is >> destFlag;
            if (destFlag == "-c") {
                st.Write(cout);
            } else if (destFlag == "-f") {
                string path;
                is >> path;
                ofstream out(path, ios::out);
                st.Write(out);
                out.close();
            }
        } else if (command == "CLEAR") {
            st.Clear();
        } else {
            cout << "Unknown command\n";
        }

    }
}

int main() {
    ExecuteApp();
}