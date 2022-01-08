// https://www.geeksforgeeks.org/distributing-m-items-circle-size-n-starting-k-th-position/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m,k;
        cin>>n>>m>>k;
        cout<<((m-1)%n + k - 1)%n + 1<<endl;
    }
    return 0;
}