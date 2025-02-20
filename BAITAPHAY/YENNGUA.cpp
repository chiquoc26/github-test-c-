#include <bits/stdc++.h>
using namespace std;
bool yenngua(int n,int m,int a[][101],int i,int j) {
    vector<int> cot;
    vector<int> hang;
    for(int x = 1; x <= m; x++) {
        hang.push_back(a[i][x]);
    }
    for(int x = 1; x <= n; x++) {
        cot.push_back(a[x][j]);
    }
    sort(cot.begin(),cot.end());
    sort(hang.begin(),hang.end());
    if(a[i][j] == cot[0] && a[i][j] == hang[m - 1]) return true;
    else return false;

    
}
int main() {
    multimap<int, int> cq;
    int n,m; cin >>  n >> m;
    int a[101][101];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) { 
            cin >> a[i][j];
        }
    }
    int dem = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(yenngua(n,m,a,i,j)) {
                dem++;
                cq.insert({i,j});
            }
        }
    }
    cout << dem << endl;
    for(auto x : cq) {
        cout << x.first << " " << x.second << endl;
    }
    return 0;
    
}