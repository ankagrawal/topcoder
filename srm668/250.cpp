#include<iostream>
#include<string>
#include<vector>
#include<limits>

using namespace std;

#define REP(k, i) for(int i = 0; i < k; i++)
#define REPI(k, i, j) for(int i = j; i < k; i++)
#define PRL(a) cout<<a<<endl;
#define PR(a) cout<<a<<" ";

class VerySecureEncryption {
    string encrypt(string message, vector <int> key, int K) {
        int track = 0;
        string new_message = message;
        while(track<K) {
            for(int i = 0; i < message.length(); i++) {
                new_message[key[i]] = message[i];
            }
            message = new_message;
            track++;
        }
        return message;
    }
};
int main() {
    return 0;
}
