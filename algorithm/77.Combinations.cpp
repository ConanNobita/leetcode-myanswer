#include "common.h"
#include "node.h"

USESTD

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
		if (n == 0 || k == 0) {
			return result;
		}

        vector<int> temp;
        vector<int> cache(n + 1, 0);
		backtract(result, temp, cache, 0, k, n);
        return result;
    }

private:
    void backtract(vector<vector<int>>& result, vector<int>& temp, vector<int>& cache, int count, int k, int n) {
        if (count == k) {
            result.push_back(vector<int>(temp));
            return;
        }

        
        for (int i = 1; i <= n; i++) {
            if ((temp.size() == 0 || i >= temp[count - 1]) && cache[i] == 0) {
                cache[i] = 1;
                
                temp.push_back(i);
                backtract(result, temp, cache, count + 1, k, n);
                temp.pop_back();
                cache[i] = 0;
            }
        }
    }
};
