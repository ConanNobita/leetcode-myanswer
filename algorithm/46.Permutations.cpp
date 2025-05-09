#include "common.h"

USESTD 

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        int size = nums.size();

        if (size == 0) {
            return result;
        }

        vector<int> newNums(size);
        vector<int> cache(size);
        vector<int> temp(size);

        next(result, cache, nums, temp, 0, size);
        return result;
    }

private:
    void next(vector<vector<int>>& result, vector<int>& cache, vector<int>& nums, vector<int>& temp, int index, int count) {
        if (index == count) {
            vector<int> v(temp);
            result.push_back(v);
            return;
        }

        int nextIndex = index + 1;
        for (int i = 0; i < count; i++) {
            if (cache[i] == 1) {
                return;
            }

            cache[i] = 1;
            temp.push_back(nums[i]);

            next(result, cache, nums, temp, nextIndex, count);
            cache[i] = 0;
            temp.pop_back();
        }
    }
};