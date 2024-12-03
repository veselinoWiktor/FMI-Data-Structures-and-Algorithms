#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    int slaps = 0;

    int N = 0;
    cin >> N;
    vector<int> ivanchoCards(N);
    for (int i = 0; i < N; i++) {
        cin >> ivanchoCards[i];
    }

    unordered_map<int, int> um;
    int sticker = 0;
    for (int i = 0; i < N; i++) {
        if (!um.count(ivanchoCards[i])) {
            um[ivanchoCards[i]] = 1;
        }
        else {
            um[ivanchoCards[i]]++;
        }

        cin >> sticker;

        if (!um.count(sticker)) {
            slaps++;
        }
        else {
            um[sticker]--;
            if (um[sticker] == 0)
            {
                um.erase(sticker);
            }
        }
    }

    cout << slaps;
}