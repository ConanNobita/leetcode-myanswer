#include "common.h"
#include "node.h"

USESTD

class Solution {
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            int size = candidates.size();
            vector<vector<int>> result;
    
            if (size == 0) {
                return result;
            }
    
            vector<int> temp;
            vector<int> cache(size, 0);
    
            backtract(result, candidates, cache, temp, 0, target, 0);
            return result;
        }
    
    private:
        void backtract(vector<vector<int>>& result, vector<int>& candidates, vector<int>& cache, vector<int>& temp, int sum, int target, int index) {
            if (sum > target) {
                return;
            }
    
            if (sum == target) {
                result.push_back(vector<int>(temp));
                return;
            }
    
            for (int i = index, size = candidates.size(); i < size; i++) {
                if (cache[i] == 1) {
                    return;
                }
    
                int number = candidates[i];
                int newSum = sum + number;
    
                temp.push_back(candidates[i]);
                backtract(result, candidates, cache, temp, newSum, target, i);
                temp.pop_back();
            }
        }
    };