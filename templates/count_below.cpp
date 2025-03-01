using ll = long long;
template <typename T>
ll count_below(vector<T>& v, int sz, ll Limit){
    ll total = 0;
    for (int i = 0, j = sz-1; i < j; i++){
        while(j > i && v[i] + v[j] > Limit)
            j--;
        print(i, j, v[i]+v[j], j-i);
        total += max(0, j-i);
    }
    return total;
}