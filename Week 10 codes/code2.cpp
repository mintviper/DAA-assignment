#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Task {
    int time;
    int deadline;
};

bool compare(Task t1, Task t2) {
    return t1.deadline < t2.deadline;
}

int maxTasks(vector<Task>& tasks) {
    sort(tasks.begin(), tasks.end(), compare);

    int maxTasksCompleted = 0;
    int currentTime = 0;

    for (int i = 0; i < tasks.size(); i++) {
        if (currentTime + tasks[i].time <= tasks[i].deadline) {
            maxTasksCompleted++;
            currentTime += tasks[i].time;
        }
    }

    return maxTasksCompleted;
}

int main() {
    int n;
    cout << "Enter the total number of tasks: ";
    cin >> n;

    vector<Task> tasks(n);
    cout << "Enter time taken and deadline for each task:\n";
    for (int i = 0; i < n; i++) {
        cin >> tasks[i].time;
    }

    for (int i = 0; i < n; i++) {
        cin >> tasks[i].deadline;
    }

    int maxCompleted = maxTasks(tasks);
    cout << "Maximum number of tasks that can be completed: " << maxCompleted << endl;

    return 0;
}
