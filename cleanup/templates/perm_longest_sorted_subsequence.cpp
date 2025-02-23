template<typename T>
int perm_longest_sorted_subsequence(vector<T> &v){
    int f = 2, cnt = 1;
    auto it = find(v.begin(), v.end(), 1);
    for (it++; it != v.end(); it++){
        if (*it == f){
            cnt++;
            f++;
        }
    }
    return cnt;
}