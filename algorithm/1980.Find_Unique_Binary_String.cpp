#include "common.h"
#include "node.h"

USESTD

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
		int size = nums.size();
		if (size == 0) {
            return "";
		}
        
		set<int> numberSet;
		int maxValue = (1 << size) - 1;

		for (int i = 0; i < nums.size(); ++i) {
            int decimal = 0;
            string& number = nums[i];

			for (int j = 0; j < number.size(); ++j) {
                decimal = (decimal << 1) + number[j] - '0';
			}

			if (numberSet.find(decimal) == numberSet.end()) {
				numberSet.insert(decimal);
			}
		}

        for (int i = 0; i <= maxValue; i++) {
			if (numberSet.find(i) == numberSet.end()) {
				int end = size - 1;
				string result(size, '0');

				for (int j = 0; j < size; j++) {
					result[end - j] = ((i & 1) == 1) ? '1' : '0';
					i >>= 1;
				}

				return result;
			}
        }

		return "";
    }
};
                                 