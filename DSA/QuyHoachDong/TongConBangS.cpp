#include <bits/stdc++.h>
using namespace std;
int dp[1000];
int main(){
    int a[1000],n,s;
    cin >> n >> s;
    for(int i = 1; i <= n; i++) cin >> a[i];
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = s; j >= a[i]; j--){
            if(dp[j - a[i]] == 1){
                dp[j] = 1;
            }
        }
    }       
    cout << dp[s];
    return 0;
    
}