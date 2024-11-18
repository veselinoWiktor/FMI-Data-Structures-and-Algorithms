#include <iostream>
#include <vector>
using namespace std;

const int N = 1000001;

vector<int> tree[N];
int timeIn[N], timeOut[N];
int ttime = 0;

void dfs(int v) {

    timeIn[v] = ttime++;

    for (auto x : tree[v]) dfs(x);

    timeOut[v] = ttime++;

}

int main()
{
    int n;
    cin >> n;
    int a, b;
    while (--n) {
        cin >> a >> b;
        tree[a].push_back(b);
    }

    dfs(0);

    cin >> n;
    vector<string>ans;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        if (timeIn[a] < timeIn[b] && timeOut[a] > timeOut[b]) ans.push_back("YES\n");
        else ans.push_back("NO\n");
    }

    for (int i = 0; i < n; i++) cout << ans[i];

    return 0;
}