#include "common.h"

USESTD

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0, size = nums.size();
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        int maxSum = sum;
        for (int i = k; i < size; i++) {
            sum = sum - nums[i - k] + nums[i];
            maxSum = max(maxSum, sum);
        }

        return (float)maxSum / (float)k;
    }
};