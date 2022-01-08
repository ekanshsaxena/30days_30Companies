// https://practice.geeksforgeeks.org/problems/number-following-a-pattern3126/1
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string ans = "";
    bool check(int i, int mask, string &cur, string &s){
        if(i==s.length()){
            ans = cur;
            return true;
        }
        if(i==-1){
            for(int j=1;j<=9;j++){
                cur.push_back(j+'0');
                if(check(i+1, mask|(1<<j), cur, s)) return true;
                cur.pop_back();
            }
        }
        else{
            for(int j=1;j<=9;j++){
                if(mask & (1<<j) || (s[i]=='I' && j<(cur.back()-'0')) || (s[i]=='D' && j>(cur.back()-'0')) ) continue;
                cur.push_back(j+'0');
                if(check(i+1,mask|(1<<j), cur, s)) return true;
                cur.pop_back();
            }
        }
        return false;
    }
    string printMinNumberForPattern(string &s){
        ans = "";string cur = "";
        check(-1, 0, cur, s);
        return ans;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends