#include <bits/stdc++.h>
using namespace std;
int partition(int a[],int l,int r) {
    int i = l - 1; 
    for(int j = l; j < r; j++) {
        if(a[j] <= a[r]) {
            i++;
            swap(a[i],a[j]);
        }
    }
    i++;
    swap(a[i],a[r]);
    return i;
}
void quicksort(int a[],int l,int r) {
    if(l >= r) return;
    int i = partition(a,l,r);
    quicksort(a,l,i - 1);
    quicksort(a,i+1,r);
}

int main() {
    int a[1000];
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    quicksort(a,0,n - 1);
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}
