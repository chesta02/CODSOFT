#include<iostream>
#include<vector>
#include<string>    
#include<algorithm>
using namespace std;
class ToDoList {
private:
    vector<string> tasks;
public:
    void addTask(const string& task) {
        tasks.push_back(task);
        cout << "Task added: " << task << endl;
    }

    void removeTask(const string& task) {
        auto it = find(tasks.begin(), tasks.end(), task);
        if (it != tasks.end()) {
            tasks.erase(it);
            cout << "Task removed: " << task << endl;
        } else {
            cout << "Task not found: " << task << endl;
        }
    }

    void displayTasks() const {
        if (tasks.empty()) {
            cout << "No tasks in the to-do list." << endl;
            return;
        }
        cout << "To-Do List:" << endl;
        for (const auto& task : tasks) {
            cout << "- " << task << endl;
        }
    }
    void clearTasks() {
        tasks.clear();
        cout << "All tasks cleared." << endl;
    }
    void markTaskCompleted(const string& task) {
        auto it = find(tasks.begin(), tasks.end(), task);
        if (it != tasks.end()) {
            cout << "Task completed: " << task << endl;
            tasks.erase(it);
        } else {
            cout << "Task not found: " << task << endl;
        }
    }
};
int main() {
    ToDoList myList;
    cout<<"Welcome to the To-Do List Application!" << endl;
    cout<<"Available commands: add , remove, display, clear, complete, exit" << endl;
    string command, task;
    while (true) {
        cout << "Enter command: ";
        cin >> command;
        if (command == "add") {
            cout << "Enter task to add: ";
            cin.ignore();
            getline(cin, task);
            myList.addTask(task);
        } else if (command == "remove") {
            cout << "Enter task to remove: ";
            cin.ignore();
            getline(cin, task);
            myList.removeTask(task);
        } else if (command == "display") {
            myList.displayTasks();
        } else if (command == "clear") {
            myList.clearTasks();
        } else if (command == "complete") {
            cout << "Enter task to mark as completed: ";
            cin.ignore();
            getline(cin, task);
            myList.markTaskCompleted(task);
        } else if (command == "exit") {
            cout << "Exiting the application.\n GOODBYE!" << endl;
            break;
        } else {
            cout << "Invalid command. Please try again." << endl;
        }
    }
    return 0;
}