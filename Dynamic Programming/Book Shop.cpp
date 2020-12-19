// Problem Link : https://cses.fi/problemset/task/1158

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
    vector<int>a(n,0),b(n,0);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];



    vector<vector<int> > dp(n, vector<int>(m+1,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<=m;j++){
            if(i==0){
                if(j-a[i]>=0){
                    dp[i][j]=b[i];
                }
            }
            else{
                if(j-a[i]>=0){
                    dp[i][j]=max(dp[i-1][j], b[i]+dp[i-1][j-a[i]]);
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
    }
    /*
    for(auto c:dp){
        for(auto i=c.begin();i!=c.end();i++)cout<<*i<<" ";cout<<endl;
    }
    */
    cout<<dp[n-1][m]<<endl;
}
