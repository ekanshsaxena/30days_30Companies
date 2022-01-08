#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n;
    cin>>n;

    // For holding only unique 10 max elements.
    set<ll> st;

    // For holding 10 max elements no matter whether they are unique or not.
    multiset<ll> mt;

    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        if(st.size()==0){
            st.insert(x);
            mt.insert(x);
        }else{
            if(x>*st.begin()){
                st.insert(x);
            }
            if(x>*mt.begin()){
                mt.insert(x);
            }
            if(st.size()>10){
                st.erase(st.begin());
            }
            if(mt.size()>10){
                mt.erase(mt.begin());
            }
        }
    }

    cout<<"Unique max 10 are: ";
    for(auto x:st){
        cout<<x<<" ";
    }
    cout<<"\n Distinct max 10 are: ";
    for(auto x:mt){
        cout<<x<<" ";
    }
    cout<<endl;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}