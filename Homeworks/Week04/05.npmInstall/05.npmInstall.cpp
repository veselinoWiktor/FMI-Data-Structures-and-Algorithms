#include <iostream>
#include <unordered_map>
#include <list>

void processPackages(int T, int N) {
    std::unordered_map<int, std::list<int>::iterator> cache;
    std::list<int> lruList;

    for (int i = 0; i < T; ++i) {
        int package;
        std::cin >> package;

        if (cache.find(package) != cache.end()) {
            lruList.erase(cache[package]);
            lruList.push_front(package);
            cache[package] = lruList.begin();
            std::cout << "true\n";
        }
        else {
            if (lruList.size() == N) {
                int oldPackage = lruList.back();
                lruList.pop_back();
                cache.erase(oldPackage);
            }
            lruList.push_front(package);
            cache[package] = lruList.begin();
            std::cout << "false\n";
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T, N;
    std::cin >> T >> N;
    processPackages(T, N);
    return 0;
}