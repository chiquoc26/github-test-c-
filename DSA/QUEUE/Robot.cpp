#include <bits/stdc++.h>
using namespace std;
int Ax[2] = {1,0};
int Ay[2] = {0,1};
int maxmoney(int n,int m,char matrix[][1005],queue<pair<int,int>> dau,int money[][1005]) {
    int Allmoney = 0;
    while(!dau.empty()) {
        pair<int,int> temp = dau.front();
        dau.pop();
        int i = temp.first;
        int j = temp.second;
        int dem = money[i][j]; 
        for(int t = 0; t < 2; t++) {
            int imoi = i + Ax[t];
            int jmoi = j + Ay[t];
            if(imoi < n && jmoi < m) {
                if(matrix[imoi][jmoi] == '*') {
                    if(dem + 1 > money[imoi][jmoi]) {
                        dau.push({imoi,jmoi});
                        money[imoi][jmoi] = dem + 1;
                        Allmoney = max(dem + 1,Allmoney);
                    }
                    
                } 
                else {
                    if(dem > money[imoi][jmoi] || dem == 0){
                        dau.push({imoi,jmoi});
                        money[imoi][jmoi] = dem;
                    }
                }
            }
        }
    }
    return Allmoney;
}
int money[1005][1005] = {0};
char matrix[1005][1005];
int main() {
    freopen("input.txt", "r",stdin);
    queue<pair<int,int>> dau;
    int n,m; cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cin >> matrix[i][j];
    }
    dau.push({0,0});
    if(matrix[0][0] == '*') money[0][0] = 1;
    cout << maxmoney(n,m,matrix,dau,money);
    return 0;
}
