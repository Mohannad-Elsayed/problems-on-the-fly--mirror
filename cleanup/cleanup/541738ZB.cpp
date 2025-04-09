#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> a, b;

// Global variables to store the best (maximum) profit and corresponding sale configuration.
long long bestProfit = -1;
vector<int> bestSolution;
vector<int> currentSolution;

// Backtracking function that considers two choices for each problem:
// 1. Sell safely (price = a[i]), no negative reputation added.
// 2. Sell aggressively (price = b[i]), which adds one negative reputation (only allowed if we haven't reached k yet).
void backtrack(int index, int negativeCount, long long currentProfit) {
    if (index == n) {
        // Reached a valid configuration if negative reputation is within allowed limit.
        if (negativeCount <= k && currentProfit > bestProfit) {
            bestProfit = currentProfit;
            bestSolution = currentSolution;
        }
        return;
    }
    
    // Option 1: Safe sale (price = a[index])
    currentSolution[index] = a[index];
    backtrack(index + 1, negativeCount, currentProfit + a[index]);
    
    // Option 2: Aggressive sale (price = b[index]) if allowed
    if (negativeCount < k) {
        currentSolution[index] = b[index];
        backtrack(index + 1, negativeCount + 1, currentProfit + b[index]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        a.resize(n);
        b.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        
        bestProfit = -1;
        bestSolution.assign(n, 0);
        currentSolution.assign(n, 0);
        
        backtrack(0, 0, 0);
        
        // Print the sale configuration for the current test case.
        // Each index i gets either a[i] (safe sale) or b[i] (aggressive sale)
        for (int i = 0; i < n; i++) {
            cout << bestSolution[i] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
