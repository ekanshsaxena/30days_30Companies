// https://leetcode.com/problems/subarray-product-less-than-k/
class Solution {
public:
    typedef long long ll;
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        ll ans = 0;
        ll cur = 1;
        ll p = 0;
        for(int i=0;i<nums.size();i++){
            cur*=nums[i];
            while(cur>=k && p<=i){
                cur/=nums[p];
                p++;
            }
            ans+=i-p+1;
        }
        return ans;
    }
};