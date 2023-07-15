#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int a=s.length();
    if(s[0]=='/' && s[1]=='/'){
        cout<< "This is comment";
    }
    else if (s[0]=='/' && s[1]=='*' && s[a-2]=='*' && s[a-1]=='/'){
        cout << "This is a comment";
    }
    else {cout << "This is  not a comment";}

}
