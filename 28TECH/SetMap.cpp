#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    cin.ignore();
    set<string> se;
    int dem = 0;
    while(t--) {
        string s;
        getline(cin,s);
       
        if(se.count(s) == 0) {
            se.insert(s);
            cout << s << endl;
        } else {
            dem++;
            cout << s << dem << endl;
        }
        
    
    }
    
    return 0;
}