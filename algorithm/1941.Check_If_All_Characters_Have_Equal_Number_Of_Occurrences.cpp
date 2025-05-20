#include "common.h"

USESTD
 
class Solution {
public:
	bool areOccurrencesEqual(string s) {
		int size = s.size();
		if (size == 0) {
			return true;
		}

		int firstCount = 0;
		int counts[26] = { 0 };

		for (int i = 0, size = s.size(); i < size; i++) {
			char ch = s[i];
			counts[ch - 'a']++;
		}
		
		for (int i = 0; i < 26; i++) {
			int count = counts[i];
			if (count == 0) {
				continue;
			} 

			if (firstCount == 0) {
				firstCount = count;
			} else if (count != firstCount) {
				return false;
			}
		}

		return true;
	}
};