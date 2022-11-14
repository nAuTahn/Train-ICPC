//    Ahihi To Thich Cau :))
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;

int n, sz;
char s[MAXN];

//    Template
class Suffix_Automaton {
public:
    int clk, last, nodecnt;
    int a[MAXN];
    int c[MAXN];
    int len[MAXN];
    int vis[MAXN];
    int size[MAXN];
    int fail[MAXN];
    int nxt[MAXN][26];

    void Go()
    {
        last = 1;
        nodecnt = 1;
    }

    void Extend(int x) {
        int np = ++nodecnt;
        int p = last;
        size[np] = 1;
        len[last = np] = len[p] + 1;
        while (p && nxt[p][x] == 0) {
            nxt[p][x] = np;
            p = fail[p];
        }

        if (p == 0) fail[np] = 1;
        else {
            int q = nxt[p][x];
            if (len[q] == len[p] + 1) fail[np] = q;
            else {
                int nq = ++nodecnt;
                len[nq] = len[p] + 1;
                fail[nq] = fail[q];
                fail[q] = fail[np] = nq;
                memcpy(nxt[nq], nxt[q], sizeof(nxt[nq]));
                while (nxt[p][x] == q) {
                    nxt[p][x] = nq;
                    p = fail[p];
                }
            }
        }
    }

    void Topo() {
        for (int i = 1; i <= nodecnt; ++i) ++c[len[i]];
        for (int i = 1; i <= nodecnt; ++i) c[i] += c[i - 1];
        for (int i = nodecnt; i >= 1; --i) a[c[len[i]]--] = i;
        for (int i = nodecnt; i >= 1; --i)
            size[fail[a[i]]] += size[a[i]];
    }

    int Count() {
        ++clk;
        int ret = 0;
        for (int i = 1; i <= sz; ++i) s[i + sz] = s[i];
        for (int i = 1, cur = 1, now = 0; i <= (sz << 1); ++i) {
            if (nxt[cur][s[i] - 'a']) {
                cur = nxt[cur][s[i] - 'a'];
                ++now;
            }
            else {
                while (cur && nxt[cur][s[i] - 'a'] == 0) now = len[cur = fail[cur]];
                if (cur == 0) cur = 1;
                else {
                    cur = nxt[cur][s[i] - 'a'];
                    ++now;
                }
            }
            while (cur && len[fail[cur]] >= sz) now = len[cur = fail[cur]];
            if ((now >= sz) && (vis[cur] != clk)) {
                vis[cur] = clk;
                ret += size[cur];
            }
        }
        return ret;
    }
};

Suffix_Automaton SAM;

void setupSAM() {
    SAM.Go();
    for (int i = 1; i <= sz; ++i) SAM.Extend(s[i] - 'a');
    SAM.Topo();
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> (s + 1) >> n;
    sz = strlen(s + 1);

    setupSAM();

    while (n--)
    {
        cin >> (s + 1);
        sz = strlen(s + 1);
        cout << SAM.Count() << "\n";
    }

    return 0;
}
