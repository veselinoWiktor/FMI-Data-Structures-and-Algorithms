#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    unordered_map<string, int> um;

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string currRow;
        int currNum = 0;
        for (int j = 0; j < M; j++) {
            cin >> currNum;
            currRow.push_back('0' + currNum);
        }

        if (!um.count(currRow)) {
            um[currRow] = 1;
        }
        else {
            um[currRow]++;
        }
    }

    int count = 0;
    for (auto x : um) {
        if (x.second == 1) {
            count++;
        }
    }

    cout << count;
}       