#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    string s; cin >> s;
    int max = 0;
    for(int i = 1; i < s.size() - 2; i++) {
        int l = i - 1;
        int r = i + 1;
        int dem = 1;
        while( l >= 0 && r <= s.size() - 1) {
            if(s[l] == s[r]) {
                dem += 2;
                l--;
                r++;
            }
            else break;
        }
        if(dem > max) max = dem;
    } 
    for(int i = 1; i < n - 2; i++) {
        int dem1 = 0;
        int l = i;
        int r = i + 1;
        bool chan = true;  
        while(chan && l >= 0 && r <= s.size() - 1) {
            if(s[l] == s[r]) {
                 dem1 += 2;
                 l--;
                 r++;
            }
            else chan = false;
        }
        if(dem1 > max) max = dem1;
    }
    cout << max;
    return 0;
}
//IKACOBEGIGEBOCAHTM