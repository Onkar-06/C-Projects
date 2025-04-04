//Simple To-do list manager 
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& taskDescription) {
        tasks.emplace_back(taskDescription);
        cout << "Task added: " << taskDescription << endl;
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks in the list." << endl;
            return;
        }

        cout << "To-Do List:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". [" << (tasks[i].completed ? "X" : " ") << "] " << tasks[i].description << endl;
        }
    }

    void markTaskAsCompleted(int taskIndex) {
        if (taskIndex < 1 || taskIndex > tasks.size()) {
            cout << "Invalid task number." << endl;
            return;
        }
        tasks[taskIndex - 1].completed = true;
        cout << "Task marked as completed: " << tasks[taskIndex - 1].description << endl;
    }

    void removeTask(int taskIndex) {
        if (taskIndex < 1 || taskIndex > tasks.size()) {
            cout << "Invalid task number." << endl;
            return;
        }
        cout << "Removing task: " << tasks[taskIndex - 1].description << endl;
        tasks.erase(tasks.begin() + (taskIndex - 1));
    }
};

int main() {
    ToDoList todoList;
    int choice;
    string taskDescription;

    do {
        cout << "\n=== To-Do List Manager ===" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "===========================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To ignore the newline character after the choice input

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                getline(cin, taskDescription);
                todoList.addTask(taskDescription);
                break;
            case 2:
                todoList.viewTasks();
                break;
            case 3:
                int taskToComplete;
                cout << "Enter task number to mark as completed: ";
                cin >> taskToComplete;
                todoList.markTaskAsCompleted(taskToComplete);
                break;
            case 4:
                int taskToRemove;
                cout << "Enter task number to remove: ";
                cin >> taskToRemove;
                todoList.removeTask(taskToRemove);
                break;
            case 5:
                cout << "Exiting the To-Do List Manager. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}