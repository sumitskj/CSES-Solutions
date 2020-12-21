// Problem Link :: https://cses.fi/problemset/task/1634

#include<bits/stdc++.h>
#define ll int
using namespace std;
 
 
int main(){
    ll mod= 1e9+7;
 
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n,m;
    cin>>n>>m;
 
    vector<ll> dp(m+1,mod);
    vector<int> a(n,0);
 
    for(int i=0;i<n;i++)cin>>a[i];
 
    dp[0]=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<n;j++){
            if(i-a[j]>=0){
                dp[i]=min(dp[i], 1+dp[i-a[j]]);
            }
        }
    }
    if(dp[m]==mod)cout<<"-1"<<endl;
    else
    cout<<dp[m]<<endl;
}