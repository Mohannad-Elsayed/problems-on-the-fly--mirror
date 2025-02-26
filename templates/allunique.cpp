template <typename T>
void mq(T &t){
    sort(t.begin(), t.end());
    t.resize(unique(t.begin(), t.end()) - t.begin());
}
