class Solution {
public:
    int maxProfit_any(vector<int>& prices){
        int n = prices.size();
        int dp_i_0 = 0, dp_i_1 = INT_MIN;
        for(int i = 0; i < n; i++){
            int temp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, temp - prices[i]);
        }
        return dp_i_0;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(k > n/2){
            return maxProfit_any(prices);
        }

        int dp[n][k + 1][2];

        for(int i = 0; i < n; ++i){
            dp[i][0][0] = 0;
            for(int j = k; j >= 1; --j){
                if(i - 1 == -1){
                    dp[i][j][0] = 0;
                    dp[i][j][1] = -prices[i];
                    continue;
                }
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        }

        return dp[n - 1][k][0];
    }
};