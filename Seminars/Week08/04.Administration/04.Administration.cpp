#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    int N;
    cin >> N;

    vector<int> vec(N);
    unordered_map<int, int> um;
    for (int i = 0; i < N; i++) {
        cin >> vec[i];

        if (!um.count(vec[i])) {
            um[vec[i]] = 1;
        }
        else {
            um[vec[i]]++;
        }
    }

    for (int i = 0; i < N; i++) {
        if (um.count(vec[i]) && um[vec[i]] == 1) {
            cout << vec[i] << " ";
        }
    }
    for (int i = 0; i < N; i++) {
        if (um.count(vec[i]) && um[vec[i]] > 1) {
            cout << vec[i] << " ";
            um.erase(vec[i]);
        }
    }
}
