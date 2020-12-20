// Problem Link :: https://cses.fi/problemset/task/1639/
// dp[i][k] = minimum number of moves to change a[:i] to b[:k].


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
 
    string a,b;
    cin>>a;
    cin>>b;
    int n1=a.length(), n2=b.length();
    vector<vector<int> > dp(n1+1, vector<int> (n2+1, 1e9));
    dp[0][0]=0;
    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            //last char remaining
            if(i==0 && j!=0)dp[i][j]=min(dp[i][j], 1+dp[i][j-1]);
            if(j==0 && i!=0)dp[i][j]=min(dp[i][j], 1+dp[i-1][j]);
 
            if(i!=0 && j!=0){
                if(a[i-1]==b[j-1])dp[i][j]=min(dp[i][j], dp[i-1][j-1]);//Same last char
                else{
                    dp[i][j]=min(dp[i][j], 1+dp[i-1][j-1]);//Replace last char
                    dp[i][j]=min(dp[i][j], 1+dp[i-1][j]);//Add last char
                    dp[i][j]=min(dp[i][j], 1+dp[i][j-1]);//Remove last char
                }
            }
        }
    }
    /*
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            cout<<dp[i][j]<<" ";
        }cout<<endl;
    }
    */
    cout<<dp[n1][n2]<<endl;
    return 0;
}