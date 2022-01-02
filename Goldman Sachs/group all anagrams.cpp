// https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) {
        vector<vector<string>> ans;
        map<vector<int>, int> mp;
        int c = 0;
        for(auto x:arr){
            vector<int> v(26);
            for(auto y:x){
                v[y-'a']++;
            }
            if(mp.find(v)==mp.end()){
                mp[v] = c++;
                ans.push_back({});
            }
            ans[mp[v]].push_back(x);
        }
        return ans;
    }
};