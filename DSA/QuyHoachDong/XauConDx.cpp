#include <bits/stdc++.h>
using namespace std;

bool f[1000][1000];

int main(){
    string s; cin >> s;
    int n = s.size();
    s = "x" + s;
    //f[i][j] = f[i+1][j+1] && (s[i] == s[j])
    memset(f, true, sizeof(f));
    for(int i = 1; i <= n; i++) f[i][i] == true; //Xau con co do dai la mot
    //xet tat ca cac xau con co do dai tu 2 den n
    int ans = 1;
    for(int len = 2; len <= n; len++){
        for(int i = 1; i <= n - len + 1; i++){
            int j = i + len - 1;
            if(len == 2 && s[i] == s[j]) f[i][j] = true;
            else f[i][j] = f[i + 1][j - 1] && (s[i] == s[j]);
            if(f[i][j]) ans = max(ans,len);
        }
    }

    cout << ans;
    return 0;
}