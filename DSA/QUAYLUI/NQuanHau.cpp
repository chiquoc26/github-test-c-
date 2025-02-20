#include <bits/stdc++.h>
using namespace std;
// Khi hau nam (i,j) no se quan ly hang i,cot j,duong cheo xuoi : i - j + n,duong cheo nguoc : i + j - 1
int N,d1[1000] = {1},d2[1000] = {1},cot[1000] = {1},X[1000];


void inkq(){
    for(int i = 1; i <= N; i++){
        cout << "Con hau o hang thu " << i << " va cot " << X[i] << endl;
    }
    cout << endl;
}

void Try(int i){
    for(int j = 1; j <= N; j++){
        if(cot[j] == 1 && d1[i - j + N] == 1 && d2[i + j - 1] == 1){
            X[i] = j;
            cot[j] = 0;
            d1 [i - j + N] = 0;
            d2[i + j - 1] = 0;
            if(i == N) inkq();
            else Try(i + 1);
            //backtrack
            cot[j] = 1;
            d1 [i - j + N] = 1;
            d2[i + j - 1] = 1; 
        }
        
    }
}

int main(){
    for(int i = 0; i < 1000; i++) {
        cot[i] = d1[i] = d2[i] = 1;
    }
    cin >> N;
    Try(1);
    return  0;
}