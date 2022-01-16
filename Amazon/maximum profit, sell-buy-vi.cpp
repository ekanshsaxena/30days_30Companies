// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
class Solution {
public:
    typedef long long ll;
    ll dp[2][101][1001];
    ll fun(ll i,ll k,bool flag,ll kk, vector<int> &p){
        if(i==p.size() || k == kk){
            return LLONG_MIN/2;
        }
        if(dp[flag][k][i]!=-1) return dp[flag][k][i];
        ll ans = fun(i+1,k, flag,kk,p);
        if(flag){
            ans = max(ans, fun(i+1,k+1,!flag,kk,p) + p[i]);
        }else{
            ans = max(ans, fun(i+1, k, !flag, kk,p) - p[i]);
        }
        return dp[flag][k][i] = ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return fun(0, 0, false, k, prices);
    }
};