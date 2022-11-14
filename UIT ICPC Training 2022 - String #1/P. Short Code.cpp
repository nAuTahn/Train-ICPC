//    Ahihi To Thich Cau :))
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;
int n;
string s;
int nxt[MAXN][26];
int sztrie = 0;
int cnt[MAXN];
multiset <int> mui[MAXN];

void insert(string a) {
    int p = 0;
    for (auto c : a) {
        int ch = c - 'a';
        if (!nxt[p][ch])
            nxt[p][ch] = ++sztrie;
        p = nxt[p][ch];
    }
    cnt[p]++;
}

void merg(int a, int b) {
    for (auto t : mui[b])
        mui[a].insert(t);
}

void DFS(int vert, int h) {
    for (int i = 0; i < 26; ++i) {
        if (nxt[vert][i]) {
            DFS(nxt[vert][i], h + 1);
            merg(vert, nxt[vert][i]);
        }
    }

    if (vert) {
        if (cnt[vert]) mui[vert].insert(h);
        else if (!mui[vert].empty()) {
//            multiset <int> ::iterator x;
//            x = --mui[v].end();
            mui[vert].erase(--mui[vert].end());
            mui[vert].insert(h);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> s; insert(s);
    }

    DFS(0, 0);

    int ans = 0;
    for (auto &t : mui[0])
        ans += t;

    cout << ans;
    return 0;
}
