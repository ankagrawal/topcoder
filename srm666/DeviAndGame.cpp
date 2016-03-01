#include<iostream>
#include<vector>
#include<map>

using namespace std;

class DevuAndGame {
    map<int, int> pos_vis_map;
public:
    string canWin(vector<int> nect_level);
    bool tryWin(vector<int> nect_level, int pos);
};

string DevuAndGame::canWin(vector<int> next_level) {
    if(tryWin(next_level, 0)) {
        return "Win";
    } else {
        return "Lose";
    }
}

bool DevuAndGame::tryWin(vector<int> next_level, int pos) {
    if(next_level[pos] == -1) {
        return true;
    }
    else if(pos_vis_map.find(next_level[pos]) != pos_vis_map.end()) {
        return false;
    }
    pos_vis_map[pos] = next_level[pos];
    return tryWin(next_level, next_level[pos]);
}

int main() {
    vector<int> nl;
    nl.push_back(1);
    //nl.push_back(0);
    nl.push_back(-1);
    DevuAndGame d;
    cout<<d.canWin(nl)<<endl;
}
