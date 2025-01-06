#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n + 1, 0);

        for (const auto& booking : bookings) {
            int first = booking[0];  
            int last = booking[1];   
            int seats = booking[2];

            diff[first - 1] += seats;    
            if (last < n) {
                diff[last] -= seats;   
            }
        }

        vector<int> result(n, 0);
        int runningSum = 0;
        for (int i = 0; i < n; ++i) {
            runningSum += diff[i];
            result[i] = runningSum;
        }

        return result;
    }
};

int main() {
    // Sample input
    vector<vector<int>> bookings = {
        {1, 2, 10},
        {2, 3, 20},
        {2, 5, 25}
    };
    int n = 5;

    // Create an instance of the Solution class
    Solution solution;

    // Call the function
    vector<int> result = solution.corpFlightBookings(bookings, n);

    // Print the result
    cout << "Result: ";
    for (int seats : result) {
        cout << seats << " ";
    }
    cout << endl;

    return 0;
}
