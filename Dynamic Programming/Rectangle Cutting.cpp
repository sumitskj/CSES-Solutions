// Problem Link: https://cses.fi/problemset/task/1744
// dp[w][h] = minimum number of cuts needed to cut a w x h piece into squares.

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
    vector<vector<int> > dp(n+1, vector<int> (m+1,1e9));
    dp[0][0]=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0)dp[i][j]=0;
            else{
                if(i==j)dp[i][j]=0;
                else{
                    for(int k=1;k<=i;k++){
                        dp[i][j]=min(dp[i][j], 1+dp[i-k][j]+ dp[k][j]);
                    }
                    for(int k=1;k<=j;k++){
                        dp[i][j]=min(dp[i][j], 1+dp[i][j-k]+ dp[i][k]);
                    }
                }
            }
        }
    }
 
/*
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j]<<" ";
        }cout<<endl;
    }
*/
    cout<<dp[n][m]<<endl;
    //return 0;
}