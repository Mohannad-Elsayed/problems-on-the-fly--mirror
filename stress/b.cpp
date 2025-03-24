#include<iostream>
#include<algorithm>
using namespace std;

int makearray(int arr[] , int n){
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr , arr + n);
    int unique_end = unique(arr, arr + n) - arr;
    return unique_end;
}

int count_unique(int a[] , int n , int b[] , int m){
    int counter = 0;
    for(int i=0;i<n;i++){
        if(!binary_search(b , b + m , a[i])){
            counter++;
        }
    }
    return counter;
}

int solve(){
    int n , m;
    cin >> n >> m;
    int a[n] , b[m];
    int unique_a_size = makearray(a, n);
    int unique_b_size = makearray(b, m);
    int prob_a = count_unique(a, unique_a_size, b, unique_b_size);
    int prob_b = count_unique(b, unique_b_size, a, unique_a_size);
    cout << min(prob_a , prob_b) << '\n';
    return 0;
}
int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}
