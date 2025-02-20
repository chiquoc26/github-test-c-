#include <bits/stdc++.h>
using namespace std;
int N,X[1000];
int used[1000] = {0};

void inkq(){
    for(int i = 1; i <= N; i++) {
        cout << X[i];
    }
    cout << endl;
}

void Try(int i){
    // Duyet cac kha nang ma X[i] co the nhan duoc
    for(int j = 1; j <= N; j++){
        //Xet lieu co the gan X[i] = j hay khong?
        if(used[j] == 0){
            X[i] = j;
            used[j] = 1; // Danh Dau
            if(i == N){
                inkq();
            } else {
                Try(i + 1);
            }
            //backtrack
            used[j] = 0;
        }
    }
}


int main() {
    cin >> N;
    Try(1);
    return 0;
}