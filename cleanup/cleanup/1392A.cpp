#include "bits/stdc++.h"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
template<typename T> constexpr T inf=0;
template<> constexpr int inf<int> = 0x3f3f3f3f;
template<> constexpr ll inf<ll> = 0x3f3f3f3f3f3f3f3f;
#define each(x, v) for (auto &(x) : (v))
#ifndef ONLINE_JUDGE
    #include "cleanup/debug.h"
#else
    #define print(...)
    #pragma GCC optimize("O3,unroll-loops,Ofast")
    // #pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
#endif

int pre();int solve();
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    cin >> tt;
    pre(); 
    while(tt--){
        solve();
        if(tt) cout << '\n';
    }return 0;
}
int pre(){
    
    //________________________
    return 0;
}

int minSizeAfterOperations(const std::vector<int>& numbers) {
    // إذا كانت المصفوفة فارغة أو تحتوي على عنصر واحد فقط
    if (numbers.empty() || numbers.size() == 1) {
        return numbers.size();
    }

    // نحسب عدد الكتل المتجاورة المختلفة
    int distinctBlocks = 1; // أول كتلة
    for (size_t i = 1; i < numbers.size(); ++i) {
        if (numbers[i] != numbers[i - 1]) {
            ++distinctBlocks; // عدد الكتل يزيد إذا اختلفت القيم
        }
    }

    int result = -1;

    if (distinctBlocks == 1) {
        result = numbers.size();
    }
    else {
        result = 1;
    }

    return result;
}




int solve(){
    int n; cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    cout << minSizeAfterOperations(v);
    //________________________
    return 0;
}