#ifdef NACHIA
#define _GLIBCXX_DEBUG
#else
#define NDEBUG
#endif
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using i64 = long long;
using u64 = unsigned long long;
#define rep(i,n) for(i64 i=0; i<i64(n); i++)
const i64 INF = 1001001001001001001;
template<typename A> void chmin(A& l, const A& r){ if(r < l) l = r; }
template<typename A> void chmax(A& l, const A& r){ if(l < r) l = r; }
using namespace std;

void testcase(){
    i64 N, K; cin >> N >> K;
    vector<i64> A(N); rep(i,N) cin >> A[i];
    if(K >= 2){
        sort(A.begin(), A.end());
        i64 ans = 0;
        rep(i,K+1){ ans += A.back(); A.pop_back(); }
        cout << ans << "\n";
    } else {
        i64 ans = 0;
        rep(i,N-1) chmax(ans, A[i] + A[N-1]);
        rep(i,N-1) chmax(ans, A[1+i] + A[0]);
        cout << ans << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    i64 T; cin >> T; rep(t,T)
    testcase();
    return 0;
}
