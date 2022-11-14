#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back

const int MAXN = 4e5 + 7;
const int MOD = 1e9 + 7;

int n, que;
string t[MAXN];
vector <int> ask[MAXN];

struct Aho_Corasick{
    struct Node{
        int child[26];
        int link[26], par, cha;
        int nextString = -1, id = -1;
    } t[MAXN];

    int sz = -1;

    void setup(int u)
    {
        memset(t[u].child, -1, sizeof(t[u].child));
        memset(t[u].link, -1, sizeof(t[u].link));
    }

    void init() {setup(++sz);}

    void add(string s, int id)
    {
        int cur = 0;
        for (int i = 0; i < (int)s.size(); ++i)
        {
            if (t[cur].child[s[i] - 'a'] == -1)
            {
                setup(++sz);
                t[sz].par = cur;
                t[sz].cha = s[i] - 'a';
                t[cur].child[s[i] - 'a'] = sz;
            }
            cur = t[cur].child[s[i] - 'a'];
        }
        t[cur].id = id;
    }

    int getLink(int u, int j)
    {
        if (t[u].link[j] != -1)
            return t[u].link[j];
        int par = t[u].par, cha = t[u].cha;
        int tmp = getLink(par, cha);
        if (t[tmp].child[j] != -1)
            t[u].link[j] = t[tmp].child[j];
        else
            t[u].link[j] = getLink(tmp, j);
        return t[u].link[j];
    }

    int getNextString(int u)
    {
        if (t[u].nextString != -1)
            return t[u].nextString;
        int par = t[u].par, cha = t[u].cha;
        int tmp = t[par].link[cha];
        if (t[tmp].id != -1)
            t[u].nextString = tmp;
        else t[u].nextString = getNextString(tmp);
//        cout << "next String of " << u << " is " << t[u].nextString << "\n";
        return t[u].nextString;
    }

    void links()
    {
        for (int i = 0; i < 26; ++i)
            t[0].link[i] = 0;
        for (int i = 1; i <= sz; ++i)
            for (int j = 0; j < 26; ++j)
                getLink(i, j);
        t[0].nextString = MOD;
        for (int i = 1; i <= sz; ++i)
            getNextString(i);
    }

    int go(int u, int j)
    {
        if (t[u].child[j] != -1)
            return t[u].child[j];
        return t[u].link[j];
    }
} Aho;

vector <int> child[MAXN][26];
map<string, int> msi;
int cnt[MAXN];
int ans[MAXN], tmpFirst[MAXN], q[MAXN];

void dfs(int u, int pos)
{
    int tmp = pos;
    while(tmp != MOD)
    {
        cnt[Aho.t[tmp].id]++;
        tmp = Aho.t[tmp].nextString;
    }

    for (int i = 0; i < 26; ++i)
        for (auto v : child[u][i])
            dfs(v, Aho.go(pos, i));

    for (auto t : ask[u])
        ans[t] = cnt[tmpFirst[t]];
    tmp = pos;
    while(tmp != MOD)
    {
        --cnt[Aho.t[tmp].id];
        tmp = Aho.t[tmp].nextString;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int type, ind;
        char c;
        cin >> type;
        if (type == 1) {
            cin >> c;
            child[0][c - 'a'].pb(i);
        }
        else {
            cin >> ind >> c;
            child[ind][c - 'a'].pb(i);
        }
    }

    cin >> que;

    for (int i = 0; i < que; ++i) cin >> q[i] >> t[i];
    for (int i = 0; i < que; ++i)
        if (msi.count(t[i]) == 0)
        msi[t[i]] = i;

    for (int i = 0; i < que; ++i)
        tmpFirst[i] = msi[t[i]];

    for (int i = 0; i < que; ++i) ask[q[i]].pb(i);

    Aho.init();

    for (int i = 0; i < que; ++i)
    if (tmpFirst[i] == i)
        Aho.add(t[i], i);
    Aho.links();

    dfs(0, 0);

    for (int i = 0; i < que; ++i) cout << ans[i] << "\n";

    return 0;
}
