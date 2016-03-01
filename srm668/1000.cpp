#include<iostream>
#include<string>
#include<vector>
#include<limits>

using namespace std;

#define REP(k, i) for(int i = 0; i < k; i++)
#define REPI(k, i, j) for(int i = j; i < k; i++)
#define PRL(a) cout<<a<<endl;
#define PR(a) cout<<a<<" ";

class AnArray {
public:
    int solveProblem(vector <int> A, int K) {
        int cnt = 0;
        for(int i = 0; i < A.size(); i++) {
            for(int j = i+1; j<A.size(); j++) {
                for(int k = j+1; k<A.size(); k++) {
                    int a = A[i]%K;
                    int b = A[j]%K;
                    int c = (a*b)%K;
                    int d = A[k]%K;
                    int e = (c*d)%K;
                    if(e%K == 0) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};

int main() {
    vector<int> A(2000);
    for(int i = 0; i < A.size(); i++) {
        A[i] = 99999999;
    }
    int K = 999998;
    AnArray a;
    cout<<a.solveProblem(A, K)<<endl;
    return 0;
}
