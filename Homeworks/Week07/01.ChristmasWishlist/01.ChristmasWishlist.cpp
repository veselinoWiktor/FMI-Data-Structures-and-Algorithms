#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_MINS = 10080;
const int MOD = 1000000007;
vector<int> wishlist(MAX_MINS + 1, 0);

void populateWhishlist(int* friends, int size) {
    if (size > 0) {
        populateWhishlist(friends, size - 1);
    }
    else if (size == 0) {
        wishlist[0] = 1;
        return;
    }
    int curr = 0;
    int N = wishlist.size();
    int currTime = friends[size - 1];
    for (int i = MAX_MINS; i >= currTime; i--) {
        wishlist[i] = (wishlist[i] + wishlist[i - currTime]) % MOD;
    }
}

int main() {
    int n;
    cin >> n;

    int* times = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> times[i];
    }

    populateWhishlist(times, n);

    int result = 0;
    for (int i = 0; i <= MAX_MINS; i++) {
        result = (result + wishlist[i]) % MOD;
    }
    cout << result << endl;
    return 0;
}