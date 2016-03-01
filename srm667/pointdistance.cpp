#include<iostream>
#include<vector>

using namespace std;

class PointDistance {
public:
    vector <int> findPoint(int x1, int y1, int x2, int y2);
};

vector<int> PointDistance::findPoint(int x1, int y1, int x2, int y2) {
    int a = -100;
    int b = -100;
    bool found = false;
    for(int i = -100; i <= 100; i++) {
        for(int j = -100; j <= 100; j++) {
            int dista = ((x1-i)*(x1-i)) + ((y1-j)*(y1-j));
            int distb = ((x2-i)*(x2-i)) + ((y2-j)*(y2-j));
            if(dista > distb) {
                a = i;
                b = j;
                found = true;
                break;
            }
        }
        if(found)
            break;
    }
    vector<int> v;
    v.push_back(a);
    v.push_back(b);
    return v;
}

int main() {
    PointDistance p;
    vector<int> v = p.findPoint(0, 1, 2, 3);
    cout<<v[0]<<" "<<v[1]<<endl;
    return 0;
}
