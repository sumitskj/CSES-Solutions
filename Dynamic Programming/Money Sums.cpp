// Problem Link : : https://cses.fi/problemset/task/1745/

// dp[i][x] = true if it is possible to make x using the first i coins, false otherwise.

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

    int n;
    cin>>n;

    vector<int> a(n,0);
    int sum=0;
    for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
    }

    vector<vector<int> > dp(n, vector<int> (sum+1,0));
    set<int> ans;
    sort(a.begin(), a.end());
    dp[0][a[0]]=1;
    ans.insert(a[0]);

    for(int i=1;i<n;i++){
        for(int j=1;j<=sum;j++){
            if(j-a[i]==0){
                dp[i][j]=1;
                ans.insert(j);
            }
            else if(j-a[i]>0){
                if(dp[i-1][j-a[i]]==1){
                    dp[i][j]=1;
                    ans.insert(j);
                }
            }
            if(dp[i][j]==0){
                dp[i][j]=dp[i-1][j];
            }
        }
    }

/*
    for(int i=0;i<n;i++){
        for(int j=0;j<=sum;j++){
            cout<<dp[i][j]<<" ";
        }cout<<endl;
    }
*/
    cout<<ans.size()<<endl;
    for(auto it=ans.begin(); it!=ans.end();++it)cout<<*it<<" ";cout<<endl;
    return 0;
}
