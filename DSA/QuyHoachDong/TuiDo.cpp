#include <bits/stdc++.h>
using namespace std;
int w[1000],v[1000];
int dp[1000][1000];
int main(){
    int n,s; cin >> n >> s;
    for(int i = 1; i <= n; i++){
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++) cin >> v[i];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= s; j++){
            dp[i][j] = dp[i - 1][j];
            if(j >= w[i]){
                dp[i][j] = max(dp[i][j],dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }
    cout << "Lay duoc nhieu nhat la: " << dp[n][s];
    return 0;
}


