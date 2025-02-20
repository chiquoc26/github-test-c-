#include <bits/stdc++.h>
using namespace std;
void merge(int a[],int l,int r,int m) {
    vector<int> x(a + l, a + m + 1);
    vector<int> y(a + m + 1, a + r + 1);
    int i = 0; //chi so x
    int j = 0; //chi so y
    while(i < x.size() && j < y.size()) {
        if(x[i] < y[j]) {
            a[l] = x[i];
            l++; i++;
        } else {
            a[l] = y[j];
            l++; j++;
        }
    }
    while(i < x.size()) {
        a[l] = x[i];
        l++; i++;
    }
    while(j < y.size()) {
        a[l] = y[j];
        l++; j++;
    }
}

void sapxeptron(int a[],int l,int r) {  // tách đến khi còn 1 số và trôn vào với nhau
    if(l >= r) return;
    int m = (r+l)/2;
    sapxeptron(a,l,m);
    sapxeptron(a,m+1,r);
    merge(a,l,r,m);
}

int main() {
    int a[1000];
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sapxeptron(a,0,n - 1);
    for(int x = 0; x < n; x++) cout << a[x] << " ";
    return 0;
}