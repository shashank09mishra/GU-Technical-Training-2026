//704
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (target < nums[0] || target > nums[n - 1]) {
            return -1;
        }
        int min = 0, max = n - 1;
        while (min <= max) {
            int mid = min + (max - min) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                min = mid + 1;
            } else {
                max = mid - 1;
            }
        }
        return -1;
    }
};

//35
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};

//1351
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        for (const auto& row : grid) {
            for (int num : row) {
                if (num < 0) {
                    count++;
                }
            }
        }
        return count;
    }
};

//1608
class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        for (int x = 0; x <= n; x++) {
            if (countGreaterEqualOrX(nums, x) == x) {
                return x;
            }
        }
        return -1;
    }
    int countGreaterEqualOrX(const vector<int>& nums, int x) {
        int count = 0;
        for (const int& num : nums) {
            if (num >= x) {
                count++;
            }
        }
        return count;
    }
};

//1539
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int missing_count = arr[mid] - (mid + 1);
            if (missing_count < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return k + high + 1;
    }
};

//1337
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<pair<int, int>> strengths;
        for (int i = 0; i < m; ++i) {
            int left = 0, right = n;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (mat[i][mid] == 1) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            strengths.push_back({left, i});
        }
        sort(strengths.begin(), strengths.end());
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(strengths[i].second);
        }

        return result;
    }
};

//441
class Solution {
public:
    int arrangeCoins(int n) {
        long long left = 0, right = n;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long currRows = (mid * (mid + 1)) / 2; 
            
            if (currRows == n) {
                return mid; 
            } else if (currRows < n) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return right; 
    }
};

//278
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (isBadVersion(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left; 
    }
};

//367
class Solution {
public:
    bool isPerfectSquare(long long num) {
        long long min = 1;
        long long max = num;
        while (min <= max) {
            long long mid = min + (max - min) / 2;
            if (mid*mid == num) {
                return true;
            }
            if (mid*mid < num) {
                min = mid + 1;
            } else {
                max = mid - 1;
            }
        }
        return false;
    }
};

//69
class Solution {
public:
    int mySqrt(int x) {
        int min = 1;
        int max = x / 2;
        if(x == 0 || x == 1){
            return x;
        }
        while (min <= max){
            int mid = min + (max - min) / 2;
            if (mid <= x / mid) {
                min = mid + 1;
            } else {
                max = mid - 1;
            }
        }
        return max;
    }
};

//1552
class Solution {
public:
    bool isPossible(vector<int>& position, int m, int mid) {
        int last = position[0];
        int count = 1;

        for (int i = 1; i < position.size() && count < m; i++) {
            if (position[i] - last >= mid) {
                last = position[i];
                count++;
            }
        }

        return count >= m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 1;
        int high = position.back() - position.front();
        int res;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if (isPossible(position, m, mid)) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return res;
    }
};

//1011
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0, right = 0;
        for (int weight : weights) {
            left = max(left, weight);
            right += weight;
        }
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (possible(weights, mid, days)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    bool possible(vector<int>& weights, int capacity, int days) {
        int day = 1;
        int sum = 0;
        for (int weight : weights) {
            if (sum + weight > capacity) {
                day++;
                sum = weight;
            } else {
                sum += weight;
            }
        }
        return day <= days;
    }
        
};

//852
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] < arr[mid + 1]) {
                left = mid + 1; 
            } else {
                right = mid; 
            }
        }

        return left;
    }
};

//1283
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long sum = 0;
            for (int num : nums) {
                sum += (num + mid - 1) / mid;
            }
            if (sum <= threshold) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;

    }
};

//1760
class Solution {
public:
    bool isPossible(int x, int maxOperations, vector<int>& nums) {
        int operations = 0;
        for (int num : nums) {
            if (num > x) {
                operations += (num - 1) / x; 
            }
            if (operations > maxOperations) {
                return false;
            }
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int min = 1;
        int max = *max_element(nums.begin(), nums.end());
        int result = max;

        while (min <= max) {
            int mid = min + (max - min) / 2;
            if (isPossible(mid, maxOperations, nums)) {
                result = mid;
                max = mid - 1;
            } else {
                min = mid + 1;
            }
        }

        return result;
    }
};

//540
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || 
                (mid % 2 == 1 && nums[mid] == nums[mid - 1])) {
                left = mid + 1; 
            } else {
                right = mid; 
            }
        }

        return nums[left];
    }
};

//826
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobs;
        for (int i = 0; i < difficulty.size(); ++i) {
            jobs.emplace_back(difficulty[i], profit[i]);
        }
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());

        int maxProfit = 0, res = 0, i = 0;

        for (int w : worker) {
            while (i < jobs.size() && jobs[i].first <= w) {
                maxProfit = max(maxProfit, jobs[i].second);
                ++i;
            }
            res += maxProfit;
        }

        return res;
    }
};

//74
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] <= target && target <= matrix[i][n - 1]) {
                int left = 0, right = n - 1;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (matrix[i][mid] == target) {
                        return true;
                    } else if (matrix[i][mid] < target) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
            }
            if (target < matrix[i][n - 1]) {
                break;
            }
        }
        return false;
    }
};

//240
class Solution {
public:
   bool searchMatrix(vector<vector<int>>& matrix, int target) {
       if (matrix.empty() || matrix[0].empty()) {
           return false;
       }
       int m = matrix.size(), n = matrix[0].size();
       for (int i = 0; i < m; i++) {
           if (matrix[i][0] <= target && target <= matrix[i][n - 1]) {
               int left = 0, right = n - 1;
               while (left <= right) {
                   int mid = left + (right - left) / 2;
                   if (matrix[i][mid] == target) {
                       return true;
                   } else if (matrix[i][mid] < target) {
                       left = mid + 1;
                   } else {
                       right = mid - 1;
                   }
               }
           }

       }
       return false;
   }
};

//611
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        sort(nums.begin(), nums.end());
        vector<int> cnts(1001, 0);
        for (int i = 0; i < n; i++) cnts[nums[i]]++;
        for (int i = 0; i <= 1000; i++) {
            if (i > 0) cnts[i] += cnts[i - 1];
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] - 1 < 0) continue;
                ans += max(0, cnts[min(nums[i] + nums[j] - 1, 1000)] - (j + 1));
            }
        }
        return ans;
    }
};

//153
class Solution {
public:
    int findMin(vector<int>& nums) {
        return *min_element(nums.begin(), nums.end());
    }
};

//528
class Solution {
public:
    vector<int> prefixSums; 
    int totalSum;

    Solution(vector<int>& w) {
        int n = w.size();
        prefixSums.resize(n);
        prefixSums[0] = w[0];
        for (int i = 1; i < n; ++i) {
            prefixSums[i] = prefixSums[i - 1] + w[i];
        }
        totalSum = prefixSums[n - 1];
    }
    
    int pickIndex() {
        int target = rand() % totalSum + 1;
        int left = 0, right = prefixSums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (prefixSums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left; 
    }
};

//
