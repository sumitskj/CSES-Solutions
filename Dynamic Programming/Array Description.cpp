// Problem Link :: https://cses.fi/problemset/task/1746/
//  dp[i][v] = number of ways to fill the array up to index i, if x[i] = v.
#include<bits/stdc++.h>
#define ll int
using namespace std;
 
void fast(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
 
int main(){
    ll mod= 1e9+7;
 
    fast();
 
    int n,m;
    cin>>n>>m;
 
    vector<int> a(n,0);
    for(int i=0;i<n;i++)cin>>a[i];

    vector<vector<int> > dp(n, vector<int> (m+2,0));
 
    if(a[0]==0)
    for(int i=1;i<=m;i++)dp[0][i]=1;
    else dp[0][a[0]]=1;
 
    for(int i=1;i<n;i++){
        if(a[i]==0){
            for(int j=1;j<=m;j++){
                for(int k : {j-1,j,j+1}){
                    dp[i][j]=(dp[i][j]%mod+dp[i-1][k]%mod)%mod;
                }
            }
        }else{
            int v=a[i];
            for(int x : {v-1,v,v+1}){
                dp[i][v]=(dp[i][v]%mod+dp[i-1][x]%mod)%mod;
            }
        }
    }
    int ans=0;
    for(int i=0;i<=m;i++){
        ans=(ans%mod+dp[n-1][i]%mod)%mod;
    }
    cout<<(ans%mod+mod)%mod<<endl;
}