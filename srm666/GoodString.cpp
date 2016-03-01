#include<string>
#include<vector>
#include<map>
#include<iostream>

using namespace std;

class GoodString {
public:
    string isGood(string);
};

string GoodString::isGood(string s) {
    if(s.length()%2 == 1) {
        return "Bad";
    }
    if(s.length() == 0) {
        return "Good";
    }
    if(s == "ab") {
        return "Good";
    }
    for(int i = 1; i < s.length(); i++) {
        string newstr = "";
        if(s[i] == 'b' && s[i-1] == 'a') {
            newstr += s.substr(0, i-1);
            if(i!=s.length()-1) {
                    newstr = newstr + s.substr(i+1, s.length());
                    return isGood(newstr);
            }
        }
    }
    return "Bad";
}

int main() {
    GoodString g;
    string s = "aaaaaaaabbbaaabaaabbabababababaabbbbaabbabbbbbbabb";
    cout<<g.isGood(s)<<endl;
    return 0;
}
