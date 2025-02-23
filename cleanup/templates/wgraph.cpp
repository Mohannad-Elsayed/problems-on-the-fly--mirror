struct edge {
    ll from, to, w;
    edge() : from(0), to(0), w(0) {};
    edge(ll f, ll t, ll wie) : from(f), to(t), w(wie) {};
    edge(ll t) : from(-1), to(t), w(0) {};
    bool operator<(const edge &e1) const {
        return e1.w > w;
    }
    bool operator>(const edge &e1) const {
        return e1.w < w;
    }
    friend ostream& operator<<(ostream &out, const edge &e){
        out << e.from << ' ' << e.to << ' ' << e.w << '\n';
        return out;
    }
    friend istream& operator>>(istream &in, edge &e){
        in >> e.from >> e.to >> e.w;
        return in;
    }
    edge rev(){
        return edge(to, from, w);
    }
};
using wgraph = vector<edge>;