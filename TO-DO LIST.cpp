#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Task {
    string description;
    bool completed;
};

void addTask(vector<Task>& tasks, const string& description) {
    Task newTask = {description, false};
    tasks.push_back(newTask);
    cout << "Task added: " << description << endl;
}

void viewTasks(const vector<Task>& tasks) {
    cout << "Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description;
        if (tasks[i].completed) {
            cout << " (Completed)";
        } else {
            cout << " (Pending)";
        }
        cout << endl;
    }
}

void markTaskAsCompleted(vector<Task>& tasks, size_t index) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index].completed = true;
        cout << "Task marked as completed: " << tasks[index].description << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

void removeTask(vector<Task>& tasks, size_t index) {
    if (index >= 0 && index < tasks.size()) {
        cout << "Task removed: " << tasks[index].description << endl;
        tasks.erase(tasks.begin() + index);
    } else {
        cout << "Invalid task index." << endl;
    }
}

int main() {
    vector<Task> tasks;
    int choice;
    string taskDescription;
    size_t taskIndex;

    do {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, taskDescription);
                addTask(tasks, taskDescription);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                cout << "Enter the index of the task to mark as completed: ";
                cin >> taskIndex;
                markTaskAsCompleted(tasks, taskIndex - 1);
                break;
            case 4:
                cout << "Enter the index of the task to remove: ";
                cin >> taskIndex;
                removeTask(tasks, taskIndex - 1);
                break;
            case 5:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
