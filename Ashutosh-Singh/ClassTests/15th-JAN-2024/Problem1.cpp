#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int firstOccurence(vector<int>& arr, int n, int k) {
        int s = 0;
        int e = n - 1;
        int ans = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (arr[mid] == k) {
                ans = mid;
                e = mid - 1; // Search on the left half
            } else if (arr[mid] < k) {
                s = mid + 1; // Search on the right half
            } else {
                e = mid - 1; // Search on the left half
            }
        }
        return ans;
    }

    int lastOccurence(vector<int>& arr, int n, int k) {
        int s = 0;
        int e = n - 1;
        int ans = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (arr[mid] == k) {
                ans = mid;
                s = mid + 1; // Search on the right half
            } else if (arr[mid] < k) {
                s = mid + 1; // Search on the right half
            } else {
                e = mid - 1; // Search on the left half
            }
        }
        return ans;
    }

    int searchdiff(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        int first = firstOccurence(nums, n, target);
        int second = lastOccurence(nums, n, target);
        return second - first + 1;
        
    }
};

int main() {
    int n, target;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }


    cout << "Enter the target value: ";
    cin >> target;

    Solution solution;
    int result = solution.searchdiff(nums, target);

    cout << "The number of occurrences of the target value in the array is: " << result << endl;

    return 0;
}
