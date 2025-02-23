#include "bits/stdc++.h"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
template<typename T> constexpr T inf=0;
template<> constexpr int inf<int> = 0x3f3f3f3f;
template<> constexpr ll inf<ll> = 0x3f3f3f3f3f3f3f3f;
#define each(x, v) for (auto &(x) : (v))
#define ONLINE_JUDGE
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

int maxSubarraySum(vector<long long> &arr) {
    int res = arr[0];
    int maxEnding = arr[0];

    for (int i = 1; i < arr.size(); i++) {
      
        // Find the maximum sum ending at index i by either extending 
        // the maximum sum subarray ending at index i - 1 or by
        // starting a new subarray from index i
        maxEnding = max(maxEnding + arr[i], arr[i]);
      
        // Update res if maximum subarray sum ending at index i > res
        res = max(res, maxEnding);
    }
    return res;
}


int smallestSumSubarr(vector<long long> &arr)
{
    int n = arr.size();
    // to store the minimum value that is ending
    // up to the current index
    int min_ending_here = INT_MAX;
     
    // to store the minimum value encountered so far
    int min_so_far = INT_MAX;
     
    // traverse the array elements
    for (int i=0; i<n; i++)
    {
        // if min_ending_here > 0, then it could not possibly
        // contribute to the minimum sum further
        if (min_ending_here > 0)
            min_ending_here = arr[i];
         
        // else add the value arr[i] to min_ending_here    
        else
            min_ending_here += arr[i];
         
        // update min_so_far
        min_so_far = min(min_so_far, min_ending_here);            
    }
     
    // required smallest sum contiguous subarray value
    return min_so_far;
}



int solve(){
    #define int ll
    int n; cin >> n;
    vector<int> v(n), vr;
    each(i, v)
        cin >> i;
    
    set<int> res;
    vector<int> pfx(n+1), sfx(n+1);
    int diff = -1, diffidx = -1;

    for (int i = 1; i<=n; i++)
        pfx[i] += pfx[i-1] + v[i-1];
    vr = v;
    reverse(all(vr));
    for (int i = 1; i<=n; i++)
        sfx[i] += sfx[i-1] + vr[i-1];
    // print(pfx);
    // print(sfx);

    for (int i = 0; i<n; i++){
        if (v[i] != 1 && v[i] != -1){
            diff = v[i];
            diffidx = i;
            break;
        }
    }
    res.insert(all(pfx));
    res.insert(all(sfx));
    res.insert(all(v));

    if (~diffidx){
        // print(diff, diffidx);
        int sum = 0;
        for (int i = diffidx; i<n; i++){
            sum += v[i];
            res.insert(sum);
            res.insert(sum-diff);
        }
        sum = 0;
        for (int i = diffidx; i > -1; i--){
            sum += v[i];
            res.insert(sum);
            res.insert(sum-diff);
        }
    }

    int longest_alike = 1;
    int mnsum = INT_MAX, mxsum = INT_MIN;
    for (int i = 0; i<n; i++){
        int longest_aliket = 1;
        while(i < n && v[i] == v[i+1])i++, longest_aliket++;
        longest_alike = max(longest_alike, longest_aliket);
    }

    // print(longest_alike);
    int windowsum = 0;
    for (int i = 0; i<longest_alike; i++)
        windowsum += v[i];
    res.insert(windowsum);
    mnsum = min(windowsum, mnsum);
    mxsum = max(windowsum, mxsum);
    for (int i = longest_alike; i<n; i++){
        windowsum -= v[i-longest_alike];
        windowsum += v[i];
        mnsum = min(windowsum, mnsum);
        mxsum = max(windowsum, mxsum);
        res.insert(windowsum);
    }
    
    vector<int> vgay = v;
    if (~diffidx){
        vgay[diffidx] = 0;
    }
    int mxsubarraysum = maxSubarraySum(vgay);
    mnsum = smallestSumSubarr(vgay);
    for (int i = mnsum; i<=mxsubarraysum; i++)
        res.insert(i);
    // print(res.size(), res);
    cout << res.size() << '\n';
    each(x, res)
        cout << x << ' ';

    /*
    set<int> bf;
    for (int i = 0; i<n; i++){
        for (int j = i; j<n; j++){
            int sum = 0;
            for (int k = i; k<=j; k++)
                sum += v[k];
            bf.insert(sum);
        }
    }
    print(bf.size(), bf);
    */
    //________________________
    return 0;
}