template<typename T>
vector<int> range(T a){
    vector<int> ret(a);
    iota(all(ret), 0);
    return ret;
}
template<typename T1, typename T2>
vector<int> range(T1 a, T2 b){
    vector<int> ret(b-a);
    iota(all(ret), a);
    return ret;
}