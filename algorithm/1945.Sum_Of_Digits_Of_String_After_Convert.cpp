#include "common.h"
#include "node.h"

USESTD

class Solution {
public:
    int getLucky(string s, int k) {
        if (k <= 0) {
            return 0;
        }

        int offset = 0, strLength = 0, sum = 0;
        for (int i = 0, size = s.size(); i < size; i++) {
            int number = s[i] - 'a' + 1;
            strLength += (number < 10 ? 1 : 2);
        }

		string str(strLength, '0');
		for (int i = 0, size = s.size(); i < size; i++) {
			int number = s[i] - 'a' + 1;
			if (number < 10) {
				sum += number;
				str[offset++] = number + '0';
			} else {
				int ten = number / 10;
				int one = number - ten * 10;

				str[offset++] = ten + '0';
				str[offset++] = one + '0';
				sum += (ten + one);
			}
		}

		if (k == 1) {
			return sum;
		}

		for (int i = 1; i < k; i++) {
			int prevSum = sum;
			offset = sum = 0;

			while (prevSum != 0) {
				int mod  = prevSum % 10;
				prevSum /= 10;
				sum += mod;
			}
		}

		return sum;
    }
};

