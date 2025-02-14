#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int MAX_TASKS = 100;

struct Task {
    char description[100];
    bool completed;
};


void addTask() {
    ofstream file("tasks.txt", ios::app);
    if (!file) {
        cout << "Error opening file!\n";
        return;
    }

    Task newTask;
    cin.ignore();  
    cout << "Enter task description: ";
    cin.getline(newTask.description, 100);
    newTask.completed = false;
    file << newTask.description << "|Not Done\n";  
    file.close();
    cout << "Task added successfully!\n";
}

int loadTasks(Task tasks[]) {
    ifstream file("tasks.txt");
    if (!file) {
        return 0;
    }

    int count = 0;
    while (file.getline(tasks[count].description, 100, '|')) {  
        char status[10];
        file.getline(status, 10);  
        tasks[count].completed = (strcmp(status, "Done") == 0); 
        count++;
        if (count >= MAX_TASKS) break; 
    }
    file.close();
    return count;
}


void viewTasks() {
    Task tasks[MAX_TASKS];
    int count = loadTasks(tasks);

    if (count == 0) {
        cout << "No tasks available.\n";
        return;
    }

    cout << "To-Do List:\n";
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". [" << (tasks[i].completed ? "Done" : "Not Done") << "] "
            << tasks[i].description << "\n";
    }
}

void saveTasks(Task tasks[], int count) {
    ofstream file("tasks.txt");
    if (!file) {
        cout << "Error saving tasks!\n";
        return;
    }

    for (int i = 0; i < count; i++) {
        file << tasks[i].description << "|" << (tasks[i].completed ? "Done" : "Not Done") << "\n";
    }
    file.close();
}

void removeTask() {
    Task tasks[MAX_TASKS];
    int count = loadTasks(tasks);

    if (count == 0) {
        cout << "No tasks to remove.\n";
        return;
    }

    viewTasks();
    int index;
    cout << "Enter task number to remove: ";
    cin >> index;

    if (index < 1 || index > count) {
        cout << "Invalid task number!\n";
        return;
    }

    for (int i = index - 1; i < count - 1; i++) {
        strcpy_s(tasks[i].description, tasks[i + 1].description); 
        tasks[i].completed = tasks[i + 1].completed;
    }

    count--; 
    saveTasks(tasks, count);
    cout << "Task removed successfully!\n";
}

void markCompleted() {
    Task tasks[MAX_TASKS];
    int count = loadTasks(tasks);

    if (count == 0) {
        cout << "No tasks available.\n";
        return;
    }

    viewTasks();
    int index;
    cout << "Enter task number to mark as completed: ";
    cin >> index;

    if (index < 1 || index > count) {
        cout << "Invalid task number!\n";
        return;
    }

    tasks[index - 1].completed = true;  
    saveTasks(tasks, count);
    cout << "Task marked as completed!\n";
}

int main() {
    int choice;
    do {
        cout << "\nTo-Do List Menu:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Remove Task\n";
        cout << "4. Mark Task as Completed\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addTask(); break;
        case 2: viewTasks(); break;
        case 3: removeTask(); break;
        case 4: markCompleted(); break;
        case 5: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
