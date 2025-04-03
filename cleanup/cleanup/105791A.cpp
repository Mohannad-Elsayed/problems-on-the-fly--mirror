// #define ONLINE_JUDGE
#include "bits/stdc++.h"
using namespace std;
#ifndef ONLINE_JUDGE
    #include "cleanup/debug.h"
#else
    #define print(...) 69
    #define printarr(...) 69
#endif
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define kill(x) return void(cout << (x));
#define each(x, v) for (auto &x : (v))
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void getv(T& v) {each(i, v)cin>>i;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<> uid(1, 1ll<<31);
void solve();

typedef struct Node
{
	struct Node* links[26];
	bool flag = false;
	int cp = 0, cd = 0;

	bool containsKey(char ch){
        return links[ch-'a'] != NULL;
	}
	void put(char ch, Node* node){
        links[ch-'a'] = node;
	}
    Node *get(char ch){
        return links[ch-'a'];
    }
    void increasePrefix(){
        cp++;
    }
    void increaseEndWith(){
        cd++;
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }

}Node;

class Trie{
private:
    Node* root; //diclare a pointer Node datatype
public:
    // initialize root with c++ new operator
    // to allocating dynamic memory
	Trie(){
		root = new Node();
		// Node temp; root = &temp; is it possible?
	}
    void insert(string word){
        Node* head = root;
        for(int i=0; i<word.size(); i++){
             if(!head->containsKey(word[i])){
                head->put(word[i], new Node());
             }
             head = head->get(word[i]);
             head->increasePrefix();
        }
        head->increaseEndWith();
    }

    /** Returns if there is any word in the trie that end with given word  **/
    bool search(string word){
        Node* head = root;
        for(int i=0; i<word.size(); i++){
            if(!head->containsKey(word[i])){
                return false;
            }
            head = head->get(word[i]);
        }
        return head->isEnd();
    }
    /** Returns if there is any word in the trie that starts with the given prefix  **/
    bool startsWith(string prefix){
        Node* head = root;
        for(int i=0; i<prefix.size(); i++){
            if(!head->containsKey(prefix[i])){
                return false;
            }
            head = head->get(prefix[i]);
        }
        return true;
    }
    /** Returns the number of word whose equal to given word  **/
    int countWordsEqualTo(string word){
        Node* head = root;
        for(int i=0; i<word.size(); i++){
            if(!head->containsKey(word[i])){
                return 0;
            }
            head = head->get(word[i]);
        }
        return head->cd;
    }
    /** Returns the number of word for given prefix **/
    int countWordsStartingWith(string prefix){
        Node* head = root;
        int ans = 0;
        for(int i=0; i<prefix.size(); i++){
            if(!head->containsKey(prefix[i])){
                return 0;
            }
            head = head->get(prefix[i]);
        }
        return head->cp;
    }
};


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
        if(tt) cout << '\n';
    }return 0;
}

void solve() {
    int n, m; cin >> n >> m;
    Trie t;
    while(n--) {
        string s; cin >> s;
        t.insert(s);
    }
    while(m--) {
        string s; cin >> s;
        print(s);
        cout << t.countWordsStartingWith(s) << '\n';
    }
}