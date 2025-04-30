#include "common.h"
#include "node.h"

USESTD

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int size = candidates.size();
        vector<vector<int>> result;

        if (size == 0) {
            return result;
        }

        vector<int> temp;
        vector<int> used(size, 0);
        vector<int> newCandidates(candidates);

        sort(newCandidates.begin(), newCandidates.end());
        backtract(result, newCandidates, temp, used, 0, target, 0);
        return result;
    }

private:
    void backtract(vector<vector<int>>& result, vector<int>& candidates, vector<int>& temp, vector<int>& used, int sum, int target, int index) {
        if (sum > target) {
            return;
        }

        if (sum == target) {
            result.push_back(vector<int>(temp));
            return;
        }

        for (int i = index, size = candidates.size(); i < size; i++) {
            int number = candidates[i];
			if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == 0) {
				continue;
			}

            int newSum = sum + number;
            used[i] = 1;
            temp.push_back(candidates[i]);

            backtract(result, candidates, temp, used, newSum, target, i + 1);
            temp.pop_back();
            used[i] = 0;
        }
    }
};