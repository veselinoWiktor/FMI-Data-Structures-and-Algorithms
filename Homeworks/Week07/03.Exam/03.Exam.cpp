#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to check if all characters in a substring have odd frequencies
bool isValid(const string& S, int start, int end) {
    vector<int> freq(26, 0); // Frequency array for characters
    for (int i = start; i <= end; ++i) {
        freq[S[i] - 'a']++;
    }
    for (int count : freq) {
        if (count % 2 == 0 && count > 0) return false; // Invalid if even and non-zero
    }
    return true;
}

int minPartsDP(const string& S) {
    int n = S.size();
    vector<int> dp(n, INT_MAX); // DP array to store the minimum parts
    dp[0] = 1; // Single character is always valid

    for (int i = 1; i < n; ++i) {
        // Check every possible split
        for (int j = -1; j < i; ++j) {
            if (j == -1 || isValid(S, j + 1, i)) {
                dp[i] = min(dp[i], (j == -1 ? 0 : dp[j]) + 1);
            }
        }
    }
    return dp[n - 1]; // Minimum parts to split the entire string
}

int main() {
    string S;
    cin >> S; // Input the encoded string
    cout << minPartsDP(S) << endl; // Output the minimum number of parts
    return 0;
}