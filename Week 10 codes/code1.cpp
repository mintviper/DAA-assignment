#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    int start;
    int finish;
};

bool compare(Activity a1, Activity a2) {
    return a1.finish < a2.finish;
}

void maxNonConflictingActivities(vector<Activity>& activities) {
    sort(activities.begin(), activities.end(), compare);

    int n = activities.size();
    int prevFinish = activities[0].finish;
    int selected = 1;
    vector<int> selectedIndices;
    selectedIndices.push_back(0);

    for (int i = 1; i < n; i++) {
        if (activities[i].start >= prevFinish) {
            selected++;
            prevFinish = activities[i].finish;
            selectedIndices.push_back(i);
        }
    }

    cout << "Number of non-conflicting activities: " << selected << endl;
    cout << "Selected activities: ";
    for (int i = 0; i < selectedIndices.size(); i++) {
        cout << selectedIndices[i] + 1 << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;

    vector<Activity> activities(n);
    cout << "Enter starting times of activities: ";
    for (int i = 0; i < n; i++) {
        cin >> activities[i].start;
    }

    cout << "Enter finishing times of activities: ";
    for (int i = 0; i < n; i++) {
        cin >> activities[i].finish;
    }

    maxNonConflictingActivities(activities);

    return 0;
}
