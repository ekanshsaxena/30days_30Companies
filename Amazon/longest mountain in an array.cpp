// https://leetcode.com/problems/longest-mountain-in-array/
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int flag = 0;
        int x=0;
        int ans = 0;
        for(int i=1;i<arr.size();i++){
            if(flag==0){
                if(arr[i]>arr[i-1]){
                    flag = 1;
                }else{
                    x = i;
                }
            }else if(flag == 1){
                if(arr[i]>arr[i-1]){
                    flag = 1;
                }else if(arr[i] == arr[i-1]){
                    x = i;
                    flag = 0;
                }else{
                    flag = 2;
                }
            }else{
                if(arr[i]<arr[i-1]){
                    flag = 2;
                    ans = max(ans, i-x+1);
                }else if(arr[i]>arr[i-1]){
                    x = i-1;
                    flag = 1;
                }else{
                    x = i;
                    flag = 0;
                }
            }
            if(flag==2){
                ans = max(ans, i-x+1);
            }
        }
        
        return ans;
    }
};