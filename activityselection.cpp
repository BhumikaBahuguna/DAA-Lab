#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Custom comparator to sort by end time
bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int maxActivities(vector<pair<int, int>>& activities) {
    // Sort activities based on end time
    sort(activities.begin(), activities.end(), compare);

    int count = 1; // At least one activity can always be selected
    int last_end = activities[0].second;

    for (int i = 1; i < activities.size(); i++) {
        // If start time of current activity is after or at the end of last selected activity
        if (activities[i].first >= last_end) {
            count++;
            last_end = activities[i].second;
        }
    }

    return count;
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    vector<pair<int, int>> activities(n);

    cout << "Enter start and end times of activities:\n";
    for (int i = 0; i < n; i++) {
        cin >> activities[i].first >> activities[i].second;
    }

    int result = maxActivities(activities);
    cout << "Maximum number of non-overlapping activities: " << result << endl;

    return 0;
}
