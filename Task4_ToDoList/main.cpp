#include <iostream>
#include <vector>

using namespace std;

struct Task {
    string name;
    bool completed;
};

vector<Task> tasks;

void addTask() {
    Task t;
    cin.ignore();

    cout << "\nEnter task: ";
    getline(cin, t.name);

    t.completed = false;
    tasks.push_back(t);

    cout << "Task added successfully!\n";
}

void viewTasks() {
    if (tasks.empty()) {
        cout << "\nNo tasks available.\n";
        return;
    }

    cout << "\n------ TO-DO LIST ------\n";

    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". ";

        if (tasks[i].completed)
            cout << "[Completed] ";
        else
            cout << "[Pending] ";

        cout << tasks[i].name << endl;
    }
}

void markCompleted() {
    int num;

    viewTasks();

    if (tasks.empty())
        return;

    cout << "\nEnter task number to mark as completed: ";
    cin >> num;

    if (num >= 1 && num <= tasks.size()) {
        tasks[num - 1].completed = true;
        cout << "Task marked as completed!\n";
    } else {
        cout << "Invalid task number!\n";
    }
}

void deleteTask() {
    int num;

    viewTasks();

    if (tasks.empty())
        return;

    cout << "\nEnter task number to delete: ";
    cin >> num;

    if (num >= 1 && num <= tasks.size()) {
        tasks.erase(tasks.begin() + num - 1);
        cout << "Task deleted successfully!\n";
    } else {
        cout << "Invalid task number!\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n====== TO-DO LIST MANAGER ======\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;

            case 2:
                viewTasks();
                break;

            case 3:
                markCompleted();
                break;

            case 4:
                deleteTask();
                break;

            case 5:
                cout << "\nThank you for using the To-Do List Manager!\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
