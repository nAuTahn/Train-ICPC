#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
const int MAXN = 100;
int n, k[MAXN];
string s, m[MAXN];
int sztrie = 0, nxt[MAXN][26], cur[MAXN], link[MAXN];
vector<int> cnt[MAXN];
vector<vector<int>> pos(MAXN);

void buildTrie(string a, int i)
{
    int r = 0;
    for (auto &c : a)
    {
        int ch = c - 'a';
        if (!nxt[r][ch])
            nxt[r][ch] = ++sztrie;
        r = nxt[r][ch];
    }
    cnt[r].pb(i);
}

//void sort_pos(vector <int> a) {
//    sort(a.begin(), a.end(), [&](int i, int j) {return a[i] + i > a[j] + j;});
//}

void compute()
{
    queue<int> q;
    q.push(0);

    while (!q.empty())
    {
        int u = q.front(); q.pop();
        for (int ch = 0; ch < 26; ++ch)
        {
            int v = nxt[u][ch];
            int lv = nxt[link[u]][ch];
            if (v == 0)
                nxt[u][ch] = lv;
            else
            {
                if (lv == v) link[v] = 0;
                else
                {
                    link[v] = lv;
                    if (!cnt[lv].empty())
                        cur[v] = lv;
                    else
                        cur[v] = cur[lv];
                }
                q.push(v);
            }
        }
    }
}

void solve()
{
    int root = 0;
    for (int i = 0; i < (int)s.size(); ++i)
    {
        root = nxt[root][s[i] - 'a'];
        int u = root;
        while (u)
        {
            for (auto it : cnt[u])
                pos[it].pb(i);
            u = cur[u];
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        int ans = 1e9 + 7;
        if ((int)pos[i].size() < k[i])
            ans = -1;
        else
        {
            for (int j = k[i] - 1; j < (int)pos[i].size(); ++j)
            {
                int r = pos[i][j];
                int l = pos[i][j - k[i] + 1] - (int)m[i].size() + 1;
//                cout << r << " " << l;
                ans = min(ans, r - l + 1);
//                cout << ans;
            }
        }

        cout << ans << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> k[i] >> m[i];
        buildTrie(m[i], i);
    }

    compute();

    solve();
    return 0;
}
