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
    int solveProblem(vector<int> A, int K) {
        int N= A.size();
        int i =0, k =0, j = 0, count = 0;
        for(i = 0; i < N-2; i++) {
            for(j = i+1; j < N-1; j++) {
                for(k=j+1;k<N; k++) {
                    if((((((A[i]%K)*(A[j]%K))%K)*(A[k]%K))%K) == 0) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};

int main() {
        vector<int> A(1500);
            for(int i = 0; i < A.size(); i++) {
                        A[i] = 99999999;
                            }
                int K = 999998;
                    AnArray a;
                        cout<<a.solveProblem(A, K)<<endl;
                            return 0;
}

