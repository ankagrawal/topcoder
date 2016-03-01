#include<iostream>
#include<string>
#include<vector>
#include<limits>
#include<algorithm>

using namespace std;

#define REP(k, i) for(int i = 0; i < k; i++)
#define REPI(k, i, j) for(int i = j; i < k; i++)
#define PRL(a) cout<<a<<endl;
#define PR(a) cout<<a<<" ";

class IsItASquare {

public:
    string isSquare(vector <int> x, vector <int> y) {
        string SUC = "It's a square";
        string FAIL = "Not a square";

        vector<unsigned long int> dist(6);
        dist[0] = (x[0]-x[1])*(x[0]-x[1]) + (y[0]-y[1])*(y[0]-y[1]);
        dist[1] = (x[0]-x[2])*(x[0]-x[2]) + (y[0]-y[2])*(y[0]-y[2]);
        dist[2] = (x[0]-x[3])*(x[0]-x[3]) + (y[0]-y[3])*(y[0]-y[3]);
        dist[3] = (x[1]-x[2])*(x[1]-x[2]) + (y[1]-y[2])*(y[1]-y[2]);
        dist[4] = (x[1]-x[3])*(x[1]-x[3]) + (y[1]-y[3])*(y[1]-y[3]);
        dist[5] = (x[2]-x[3])*(x[2]-x[3]) + (y[2]-y[3])*(y[2]-y[3]);

        sort(dist.begin(), dist.end());

        if(dist[4] == dist[5]) {
            if((dist[0] == dist[1]) && (dist[2] == dist[3]) && (dist[0] == dist[2])) {
                return SUC;
            }
        }
        return FAIL;
    }
};
int main() {
    return 0;
}
