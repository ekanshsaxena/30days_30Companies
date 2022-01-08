// https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    typedef long long ll;
    int minSubArrayLen(int t, vector<int>& nums) {
        ll ans = LLONG_MAX;
        ll i=0,j=0;
        ll sum = 0;
        while(i<nums.size()){
            sum+=nums[i];
            while(j<=i && sum>=(ll)t){
                ans = min(ans, i-j+1);
                sum-=nums[j];
                j++;
            }
            i++;
        }
        return ans==LLONG_MAX?0:ans;
    }
};