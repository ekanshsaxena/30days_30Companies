// https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        vector<int> v(k);
        for(auto x:nums){
            v[x%k]++;
        }
        for(int i=0;i<k/2+1;i++){
            if(i==0 || (k%2==0 && k-i==k/2)){
                if(v[i]&1) return false;
            }else{
                if(v[i]!=v[k-i]) return false;
            }
        }
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends