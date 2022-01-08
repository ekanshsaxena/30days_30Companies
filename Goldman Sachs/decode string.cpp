// https://practice.geeksforgeeks.org/problems/decode-the-string2444/1

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        stack<string> st;
        vector<int> v;
        int i=0;
        while(i<s.length()){
            int j = i;
            if(isdigit(s[i])){
                string h = "";
                while(isdigit(s[j])){
                    h.push_back(s[j]);
                    j++;
                }
                v.push_back(stoi(h));
            }else if(s[i]=='['){
                string h = "";h.push_back(s[i]);
                st.push(h);
                j++;
            }else if(s[i]==']'){
                string h = "";
                while(!st.empty() && st.top()!="["){
                    h=st.top()+h;
                    st.pop();
                }
                string m = h;
                for(int k=0;k<v.back()-1;k++){
                    h.append(m);
                }
                st.pop();
                st.push(h);
                v.pop_back();
                j++;
            }else{
                string h = "";
                while(!isdigit(s[j]) && s[j]!='[' && s[j]!=']'){
                    h.push_back(s[j]);
                    j++;
                }
                st.push(h);
            }
            i=j;
        }
        string h = "";
        while(!st.empty() && st.top()!="["){
            h=st.top()+h;
            st.pop();
        }
        return h;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends