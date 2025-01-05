#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
    vector<int>& preSum;

    NumArray(vector<int>& nums) : preSum(nums) {
        for (int i = 1; i < preSum.size(); ++i)
            preSum[i] += preSum[i - 1];
    }

    int sumRange(int left, int right) {
        if (left == 0) return preSum[right];
        return preSum[right] - preSum[left - 1];
    }
};

int main() {
    // Example input array
    vector<int> nums = {1, 2, 3, 4, 5};

    // Create NumArray object
    NumArray numArray(nums);

    // Example queries
    cout << "Sum of range [0, 2]: " << numArray.sumRange(0, 2) << endl; // Output: 6 (1 + 2 + 3)
    cout << "Sum of range [1, 4]: " << numArray.sumRange(1, 4) << endl; // Output: 14 (2 + 3 + 4 + 5)
    cout << "Sum of range [2, 2]: " << numArray.sumRange(2, 2) << endl; // Output: 3 (3)

    return 0;
}