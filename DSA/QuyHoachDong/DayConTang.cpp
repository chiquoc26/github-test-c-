#include <bits/stdc++.h>
using namespace std;
//l[i] = max(l[i],l[j] + 1)
 
int main(){
    int a[1000],l[1000],n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        l[i] = 1;
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(a[j] < a[i]) l[i] = max(l[j] + 1,l[i]);
        }
    }
    sort(l,l+n);
    cout << l[n - 1];
}