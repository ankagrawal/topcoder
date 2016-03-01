#include<iostream>
#include<string>
#include<vector>
#include<limits>

using namespace std;

#define REP(k) for(int i =0; i < k; i++)
#define PRL(a) cout<<a<<endl;
#define PR(a) cout<<a<<endl;

class OrderOfOperationsDiv2 {
    int score;
public:
    int minTime(vector<string> s) {
        int strln = s[0].length();
        int vlen   = s.size();
        vector<int> inp(vlen, 0);
        int target = 0;
        for(int i = 0; i < s.size(); i++) {
            for(int j = strln-1; j >= 0; j--) {
                inp[i] |= (s[i][j]=='1')?(1<<(strln-1-j)):0;
            }
            target = target|inp[i];
        }
        int start = 0;
        score = numeric_limits<int>::max();
        getMinTimeOpt(inp, start, target, 0, 0);
        return score;
    }

    void getMinTime(vector<int> inp, int start, int target, int sc) {
        if(start == target) {
            if(sc < score) {
                score = sc;
            }
            return;
        }
        for(int i = 0; i < inp.size(); i++) {
            if((start|inp[i]) == start)
                continue;
            int c = get_bit_diffs(start, inp[i]);
            getMinTime(inp, start|inp[i], target, sc + (c*c));
        }
    }

    void getMinTimeOpt(vector<int> inp, int start, int target, int sc, int stind) {
        if(start == target) {
            if(sc < score) {
                score = sc;
            }
            return;
        }
        for(int i = stind; i < inp.size(); i++) {
            if((start|inp[i]) == start)
                continue;
            int c = get_bit_diffs(start, inp[i]);
            swap(inp[stind], inp[i]);
            getMinTimeOpt(inp, start|inp[stind], target, sc + (c*c), stind+1);
            swap(inp[stind], inp[i]);
        }
    }

    int get_bit_diffs(int i, int j) {
        int k = 1;
        int cnt = 0;
        int diff = 0;
        while( k <= ((i<j)?j:i)) {
            k = 1<<cnt;
            cnt++;
            if( ((i&k) == 0) && ((j&k) != 0) )
                diff++;
        }
        return diff;
    }
};

int main() {
    string a[] = {"00001001001000000", "00000000000000000", "01001001000000100", "01000000010000000", "00000010011000000", "00100000000000100", "00100000000000000", "01000011000000000", "10000000000000000", "00000101000000000", "00100000000010000", "00010010000000010", "00000000000000000", "00100000000000000", "00000010000000010", "00000000000100000", "10000000000010000", "00010000000000001", "00100000000100000", "00001000000000000"};
    vector<string> v (a, a+ (sizeof(a)/sizeof(a[0])));
    OrderOfOperationsDiv2 o;
    cout<<o.minTime(v)<<endl;
}
