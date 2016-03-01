#include<iostream>
#include<string>
#include<vector>
#include<limits>
#include<unordered_map>

using namespace std;

#define REP(k, i) for(int i = 0; i < k; i++)
#define REPI(k, i, j) for(int i = j; i < k; i++)
#define PRL(a) cout<<a<<endl;
#define PR(a) cout<<a<<" ";

class RelationClassifier {
public:
    string isBijection(vector <int> domain, vector <int> range) {
        unordered_map<int, int> us;
        int sz = domain.size();
        REP(sz, i) {
            if(us.find(domain[i]) == us.end()) {
                us[domain[i]] = range[i];
            } else if (us[domain[i]] != range[i]) {
                return "Not";
            }
            if(us.find(range[i]) == us.end()) {
                us[range[i]] = domain[i];
            } else if (us[range[i]] != domain[i]) {
                return "Not";
            }
        }
        return "Bijection";
    }
};

int main() {
    return 0;
}
