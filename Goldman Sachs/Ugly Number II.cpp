// https://leetcode.com/problems/ugly-number-ii/submissions/
class Solution {
public:
    int nthUglyNumber(int n) {
        
        vector<int> dp(n);
        
        dp[0] = 1;
        
        int count = 1;
        
        int idx_2 = 0;
        int idx_3 = 0;
        int idx_5 = 0;
        
        while(count < n)
        {
            int next_2 = 2 * dp[idx_2];
            
            int next_3 = 3 * dp[idx_3];
            
            int next_5 = 5 * dp[idx_5];
            
            int next = min({next_2, next_3, next_5});
        
            dp[count] = next;
            
            count++;
            
            if(next == next_2)
                idx_2++;
            
            if(next == next_3)
                idx_3++;
            
            if(next == next_5)
                idx_5++;
            
        }
        
        return dp[n-1];
    }
};