#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int TotalSum = 0;
        for(int i = 0;i<n;i++){
            TotalSum += nums[i];
        }

        int leftSum = 0;
        int rightSum = 0;
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum += nums[i];
            leftSum = sum - nums[i];
            rightSum = TotalSum - sum;
            if(leftSum == rightSum){
                return i;
            }
        }
        return -1;
    }
};

int main() {
    // Example Inputs
    vector<int> nums1 = {2, 3, -1, 8, 4}; // Expected Output: 3
    vector<int> nums2 = {1, -1, 4};       // Expected Output: 2
    vector<int> nums3 = {2, 5};           // Expected Output: -1

    // Create an object of the Solution class
    Solution solution;

    // Test Case 1
    cout << "Pivot Index for nums1: " << solution.pivotIndex(nums1) << endl;

    // Test Case 2
    cout << "Pivot Index for nums2: " << solution.pivotIndex(nums2) << endl;

    // Test Case 3
    cout << "Pivot Index for nums3: " << solution.pivotIndex(nums3) << endl;

    return 0;
}
