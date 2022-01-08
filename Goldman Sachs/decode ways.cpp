// https://leetcode.com/problems/decode-ways/
class Solution {
public:
    int dp[101][2];
    int fun(int i,bool flag,string &s){
        if(!flag && s[i]=='0'){
            return 0;
        }else if(i==s.length()-1){
            return 1;
        }
        if(dp[i][flag]!=-1) return dp[i][flag];
        int ans = fun(i+1,false,s);
        if(!flag && (s[i]=='1' || (s[i]=='2' && s[i+1]<='6'))){
            ans += fun(i+1,true,s);
        }
        return dp[i][flag] = ans;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return fun(0,false,s);    
    }
};