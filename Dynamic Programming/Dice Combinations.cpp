// Problem Link :: https://cses.fi/problemset/task/1633

#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
int main() {
    ll mod=1e9+7;
    ll n;
    cin>>n;
    vector<ll> a(n+1,0);
    a[0]=1;
    for(int i=1;i<=n;i++){
        ll ans=0;
        for(int j=1;j<=6;j++){
            ll v=i-j;
            if(v>=0)ans=(ans+a[v])%mod;
            else break;
        }
        a[i]=ans%mod;
    }
    cout<<a[n]<<endl;
}