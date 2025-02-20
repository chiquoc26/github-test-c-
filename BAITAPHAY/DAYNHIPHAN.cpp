#include <bits/stdc++.h>
using namespace std;
int main() {
    string a[50][50];
    string xau; cin >> xau;
    int n =  xau.size();
    for(int i = 0; i < n; i++) {
        a[0][i] = xau[i];
    }
    for(int i = 1; i < n; i++) {
        string number; cin >> number;
        for(int j = 0; j < n; j++) {
            a[i][j] = number[j];
        }
    }
    string nhiphan = "1";
    for(int i = 0; i < n - 1; i++) {
        nhiphan += "1";
    }
   for(int i = 0; i < n; i++) {
        string so = a[i][0];
        for(int j = 1; j < n; j++) {
            so += a[i][j];
        }
        if(stoi(so) <= stoi(nhiphan)) nhiphan = so;
    }
    for(int j = 0; j < n; j++) {
        string so = a[0][j]; 
        for(int i = 1; i < n; i++) {
            so += a[i][j];
        }
        if(stoi(so) <= stoi(nhiphan)) nhiphan = so;
    }
    string cheo1 = a[0][0],cheo2 = a[0][n-1];
    for(int i = 1; i < n; i++) {
        cheo1 += a[i][i];
        cheo2 += a[i][n - 1 - i];
    }
    if(stoi(cheo1) <= stoi(nhiphan) ) nhiphan = cheo1;
    if(stoi(cheo2) <= stoi(nhiphan) ) nhiphan = cheo2;
    cout << nhiphan;

    return 0;
}