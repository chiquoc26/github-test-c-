#include <bits/stdc++.h>
using namespace std;
int sonuoc(int a[],int n) {
    int *left = new int[n];
    int *right =  new int[n];
    left[0] = a[0];
    for(int i = 1; i < n; i++) {
        left[i] = max(left[i - 1],a[i]);
    }
    right[n-1] = a[n - 1];
    for(int i = n - 2; i >= 0; i--) {
        right[i] = max(right[i+1],a[i]);
    }
    int s = 0;
    for(int i = 0; i < n; i++) {
        s += min(left[i],right[i]) - a[i];
    }
    return s;
}
int main() {
    int n,m;
    cin >> n >> m;
    int *a = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << sonuoc(a,m);
    return 0;
}