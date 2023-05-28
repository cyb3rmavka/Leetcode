/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
	    const int N = prices.size();
	    int *lMaxYield = new int[n]();
      int *rMaxYield = new int[n]();
	    int minCost = prices[0];
	    
      for (int i = 1; i < n; i++) {
		    minCost = min(minCost, prices[i]);
		    lMaxYield[i] = max(lMaxYield[i - 1], prices[i] - minCost);
	    }
	    int maxCost = prices[n - 1];
	    for (int i = n - 2; i >= 0 ; i--) {
		    maxCost = std::max(maxCost, prices[i]);
		    rMaxYield[i] = std::max(rMaxYield[i + 1], maxCost - prices[i]);
	    }
	    int yield = 0;
	    for (int i = 0; i < n; i++) {
		    yield = std::max(yield, rMaxYield[i] + lMaxYield[i]);
	    }
	    delete []lMaxYield;
	    delete []rMaxYield;
	    return yield;
  }
};
