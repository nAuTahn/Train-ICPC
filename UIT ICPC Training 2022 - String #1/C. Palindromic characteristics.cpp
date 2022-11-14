#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 5007;
const int MOD = 1e9 + 7;
const int P = 256;
string s, t;

ll hash1[10005], hash2[10005];
ll p[10005];
int cnt[MAXN];
int pal[MAXN][MAXN], ans[MAXN];

//    rolling hash

ll getA(int l, int r)
{
    if (l != 0)
        return (((((hash1[r] - (hash1[l - 1] * p[r - l + 1]) % MOD) + MOD)% MOD)) + MOD) % MOD;
    else return hash1[r];
}

ll getB(int l, int r)
{
    if (l != 0)
        return (((((hash2[r] - (hash2[l - 1] * p[r - l + 1]) % MOD) + MOD)% MOD)) + MOD) % MOD;
    else return hash2[r];
}

void SetUp()
{
    p[0] = 1;
    for (int i = 1; i < 10005; ++i)
        p[i] = (p[i - 1] * P) % MOD;

    hash1[0] = s[0];
    for (int i = 1; i < (int)s.size(); ++i)
        hash1[i] = (((hash1[i - 1] * P + s[i]) % MOD) + MOD) % MOD;

    hash2[0] = t[0];
    for (int i = 1; i < (int)t.size(); ++i)
    {
        hash2[i] = (((hash2[i - 1] * P + t[i]) % MOD) + MOD) % MOD;
    }

    for(int i = 0; i < (int)s.size(); ++i)
    {
        pal[i][i] = 1;
        cnt[1]++;
    }
}

void solve()
{
    int sz = (int)s.size();
    for(int i = 1; i < sz; ++i)
    {
        for(int j = 0; j < sz; ++j)
        {
            if (i + j >= sz) break; // out check
            int x = j;
            int y = j + i;
            if (i % 2 == 0)
            {
                if (getA(x, x + i / 2 - 1) == getB(sz - 1 - x - i, sz - 1 - (x + i / 2 + 1)))
                {
                    pal[x][y] = pal[x][x + i / 2 - 1] + 1;
                    cnt[pal[x][x + i / 2 - 1] + 1]++;
                }
            }
            else
            {
                if (getA(x, x + i / 2) == getB(sz - 1 - x - i, sz - 1 - (x + i / 2 + 1)))
                {
                    pal[x][y] = pal[x][x + i / 2] + 1;
                    cnt[pal[x][x + i / 2] + 1]++;
                }
            }
        }
    }

    int j = 0;
    for(int i = sz; i >= 0; --i)
    {
        ans[i] = cnt[i] + j;
        j += cnt[i];
    }

    for(int i = 1; i <= sz; ++i)
        cout << ans[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> s;

//    summm
    for(int i = (int)s.size() - 1; i >= 0; --i)
        t += s[i];

    SetUp();
    solve();

    return 0;
}
