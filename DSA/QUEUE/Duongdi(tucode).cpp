#include <bits/stdc++.h>
using namespace std;
int Ax[4] = {-1,0,0,1};
int Ay[4] = {0,-1,1,0};

int streetlong(char matrix[][1000],int n,int m,set<pair<int,int>> search,queue<pair<pair<int,int>,int>> box) {
    while(!box.empty()) {
        int ai = box.front().first.first;
        int aj = box.front().first.second;
        int dem = box.front().second;
        box.pop();
        for(int i = 0; i < 4; i++) {
            int inew = ai + Ax[i];
            int jnew = aj + Ay[i];
            if(inew < n && inew >= 0 && jnew < m && jnew >= 0) {
                if(matrix[inew][jnew] == '.' && search.count({inew,jnew}) == 0) {
                    search.insert({inew,jnew});
                    box.push({{inew,jnew},dem + 1});
                } else if (matrix[inew][jnew] == 'B') return dem + 1;
            }
        }
    }
    return -2;
}
char matrix[1000][1000];
int main() {
    queue<pair<pair<int,int>,int>> box;
    set<pair<int,int>> search;
    int n,m; cin >> n >> m;
    int ai,aj,bi,bj;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
            if(matrix[i][j] == 'A') {
                box.push({{i,j},0});
            }
        }
    }
    if(streetlong(matrix,n,m,search,box) == -2) cout << -1;
    else cout << streetlong(matrix,n,m,search,box);
}