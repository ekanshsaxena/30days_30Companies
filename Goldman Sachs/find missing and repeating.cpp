// https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1/
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(int *arr, int n) {
        int x = 0;
        for(int i=0;i<n;i++){
            x^=arr[i];
            x^=(i+1);
        }
        x = x & ~(x - 1);
        int x1 = 0,x2=0;
        for(int i=1;i<=n;i++){
            if(arr[i-1] & x){
                x1 ^= arr[i-1];
            }else{
                x2 ^= arr[i-1];
            }
            if(i & x){
                x1 ^= i;
            }else{
                x2 ^= i;
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]==x2){
                swap(x1, x2);
                break;
            }
        }
        return {x1,x2};
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends