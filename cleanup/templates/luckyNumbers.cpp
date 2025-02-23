// pre(limit), use luckyset or luckyVector (one based)
namespace luckyNumbers {
    set<ll> luckyset;
    vector<ll> luckyvector(1, -1);
    ll limit;
    void recurse(ll x){
        luckyset.insert(x);
        if (x < limit)
            recurse(x*10+4),
            recurse(x*10+7);
    }
    void pre(ll _limit){
        limit = _limit;
        recurse(0);
        luckyset.erase(0);
        for (auto lucky : luckyset)
            luckyvector.push_back(lucky);
    }
}