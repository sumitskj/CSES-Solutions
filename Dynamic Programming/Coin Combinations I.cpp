// Problem Link :: https://cses.fi/problemset/task/1635

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
    //vector<ll> dp(m+1,0);
    ll dp[m+1]={0};
    //vector<int> a(n,0);
    int a[n]={0};
    for(int i=0;i<n;i++)cin>>a[i];
 
    dp[0]=1;
    for(int i=1;i<=m;i++){
        for(int j=0;j<n;j++){
            if(i-a[j]>=0){
                dp[i]=(dp[i]+dp[i-a[j]])%mod;
            }
        }
    }
    cout<<dp[m]<<endl;
}