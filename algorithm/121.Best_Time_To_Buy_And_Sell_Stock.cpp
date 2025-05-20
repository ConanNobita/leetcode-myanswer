#include "common.h"

USESTD 

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int maxProfit = 0, minPrice = INT_MAX;
		for (int i = 0, size = prices.size(); i < size; i++) {
			int price = prices[i];
			if (price < minPrice) {
				minPrice = price;
			} else if (price - minPrice > maxProfit) {
				maxProfit = price - minPrice;
			}
		}

		return maxProfit;
	}
};