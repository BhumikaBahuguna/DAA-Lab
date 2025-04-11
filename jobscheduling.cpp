#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Job {
    int id;
    int deadline;
    int profit;
};
// Sort by descending profit
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}
int jobScheduling(vector<Job>& jobs, int& totalProfit) {
    sort(jobs.begin(), jobs.end(), compare);
    int n = jobs.size();
    // Find maximum deadline to define time slots
    int maxDeadline = 0;
    for (const auto& job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }
    vector<int> slot(maxDeadline + 1, -1);  // -1 means free slot
    totalProfit = 0;
    int count = 0;
    for (const auto& job : jobs) {
        // Try to find a free slot before or on job.deadline
        for (int t = job.deadline; t > 0; t--) {
            if (slot[t] == -1) {
                slot[t] = job.id;
                totalProfit += job.profit;
                count++;
                break;
            }
        }
    }
    return count;
}
int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;
    vector<Job> jobs(n);
    cout << "Enter job id, deadline, and profit for each job:\n";
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }
    int totalProfit = 0;
    int totalJobs = jobScheduling(jobs, totalProfit);
    cout << "Total jobs done: " << totalJobs << endl;
    cout << "Total profit earned: " << totalProfit << endl;
    return 0;
}
