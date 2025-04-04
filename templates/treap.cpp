#include <bits/stdtr1c++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

/// Maximum value of treap * ADD must fit in long long
class TREAP{ /// hash = 96814
    private:
        int len;
        const int ADD = 1000010;
        const int MAXVAL = 1000000010;
        tr1::unordered_map <long long, int> mp; /// Change to int if only int in treap
        tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> T;
        void init(){
            len = 0;
            T.clear(), mp.clear();
        }

    public:
        treap(){
            init();
        }

        template <typename U>
        treap(U v){
            init();
            for (auto x : v)
                insert(x);
        }

        inline void clear(){
            len = 0;
            T.clear(), mp.clear();
        }

        inline void insert(long long x){
            len++, x += MAXVAL;
            int c = mp[x]++;
            T.insert((x * ADD) + c);
        }

        // erase only one occurrence of x
        inline void erase(long long x){
            x += MAXVAL;
            int c = mp[x];
            if (c){
                c--, mp[x]--, len--;
                T.erase((x * ADD) + c);
            }
        }

        /// 0-based index, returns the K'th element in the treap, -1 if none exists
        inline long long kth(int k){
            k++;
            if (k < 1 || k > len) return -1;
            auto it = T.find_by_order(--k);
            return ((*it) / ADD) - MAXVAL;
        }

        /// Count of value < x in treap
        inline int count(long long x){
            x += MAXVAL;
            int c = mp[--x];
            return (T.order_of_key((x * ADD) + c));
        }

        /// Number of elements in treap
        inline int size(){
            return len;
        }
};