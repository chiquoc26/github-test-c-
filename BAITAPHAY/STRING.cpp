#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    vector<string> chuoi;
    getline(cin,s);
    for(char &x : s) {
        if( !(isalpha(x)) ) {
            x = ' ';
        }
    }
    stringstream ss(s);
    string word;
    while( ss >> word ) {
        for(int i = 0; i < word.size(); i++) {
            if(i == 0) word[i] = toupper(word[i]);
            else word[i] = tolower(word[i]); 
        }
        chuoi.push_back(word);
    }
    for(int i = 0; i < chuoi.size()  ; i++) {
        if(i == chuoi.size() - 1) {
            cout << chuoi[i];
            return 0;
        }
        cout << chuoi[i] << " ";
    }
    return 0;
}