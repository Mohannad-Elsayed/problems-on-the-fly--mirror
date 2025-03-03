// #define ONLINE_JUDGE
#include "bits/stdc++.h"
using namespace std;
#ifndef ONLINE_JUDGE
    #include "cleanup/debug.h"
#else
    #define print(...)
    #define printarr(...)
#endif
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define kill(x) return void(cout << (x));
#define each(x, v) for (auto &(x) : (v))


vector<int> Arr(256);
string _word;
pair<int, string> slv1() {
    string word ,word1 ,free;
    long long int arr[int('z')+1]={10009};
     long long int mysize=sizeof(arr)/sizeof(arr[122]) ,count=0;
    word = _word;
    for(int i=int('a');i<=int('z');i++)
    {
        arr[i] = Arr[i];
        if(arr[i]==0)
        {
            arr[i]=-1;
        }
    }
    bool test=true;
    char myca;
     long long int s;
     long long int e;
     long long int thestart ,numqu=0 ,tefree=0;
    for(int i=0;i<word.size();i++)
    {
        if(word[i]=='?')
        {
            tefree++;
            free.push_back('a');
        }
        if(word[i]=='?' && test==true)
        {
            if(i==0){
                test=false;
                s=i;
                while(true)
                {
                    s++;
                    numqu++;
                    if(word[s]!='?')
                    {
                        e=s-1;
                        break;
                    }

                }
                int mymn=distance(arr,find(arr,arr+mysize,arr[word[s]]));
                myca=char(mymn);
                word1.push_back(myca);
                if(numqu==1)test=true;
            }else
            {
                test=false;
                s=i;
                thestart=i-1;
                while(true)
                {
                    s++;
                    numqu++;
                    if(word[s]!='?' || s==word.size())
                    {
                        e=s-1;
                        break;
                    }

                }
                if(s==word.size())
                {
                    int mymn=distance(arr,find(arr,arr+mysize,arr[word[thestart]]));
                    myca=char(mymn);
                    word1.push_back(myca);
                    if(numqu==1)test=true;
                }else{
                    int mymn=min(distance(arr,find(arr,arr+mysize,arr[word[s]])),
                                 distance(arr,find(arr,arr+mysize,arr[word[thestart]])));
                    myca=char(mymn);
                    word1.push_back(myca);
                    if(numqu==1)test=true;
                }
            }
        }else if(test==false &&numqu!=1)
        {
            word1.push_back(myca);
            if(i==e)
            {
                test=true;
            }

        }else if(test==true)
        {
            numqu=0;
            word1.push_back(word[i]);
        }

    }
    for(int i=0;i<word1.size();i++)
    {
        if(arr[word1[i]]==-1)arr[word1[i]]=0;
        if(i!=0)
        {
            count+=abs(arr[word1[i-1]]-arr[word1[i]]);
        }

    }
    if(tefree==word.size())
    {
        return make_pair(0, free);
    }else
    {
        return make_pair(count, word1);
    }
    // return 0;
}


pair<int, string> slv(){
    string s; 
    s = _word;
    vector<int> v(256);
    for (int i = 'a'; i<='z'; i++)
        v[i] = Arr[i];
    // print(v);
    int n = s.size();
    for (int i = 0; i < n; i++){
        if (s[i] == '?'){
            char ch1 = (i ? s[i-1] : -1), 
                ch2 = -1, chf;
            int j = i;
            while(j < n && s[j] == '?')
                j++;
            if (j != n)
                ch2 = s[j];
            // print(i, j, ch1, ch2);
            int mn = 1e9;
            for (int c = 'a'; c <= 'z'; c++){
                int curr = 0;
                if (~ch1)
                    curr += abs(v[ch1] - v[c]);
                if (~ch2)
                    curr += abs(v[c] - v[ch2]);
                if (curr < mn){
                    mn = curr;
                    chf = c;
                }
            }
            for (int c = i; c < j; c++)
                s[c] = chf;
        }
    }
    int cost = 0;
    for (int i = 0; i+1 < n; i++)
        cost += abs(v[s[i]] - v[s[i+1]]);
    // print(cost, s);
    return make_pair(cost, s);
}

int main() {
    srand(time(0));
    int n = rand()%50 + 2;
    while(n--)
        _word.push_back(char(rand()%26 + 'a')), _word.back() = (rand()%2 ? '?' : _word.back());
    
    for (int i = 'a'; i<='z'; i++)
        Arr[i] = rand()%10 + 2;
    if (slv() != slv1())
        print(_word, Arr);
    return 0;
}