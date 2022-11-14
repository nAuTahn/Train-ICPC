#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int P = 169;
const ll MOD = 10000000000000000LL;
string s, binary;
map<ll, bool> mlb;
ll base[2005];
ll k, cnt;
ll H;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> s >> binary >> k;

    ll sz = (ll)s.size();
    base[0] = 1; // setup hashing
    for (int i = 1; i <= sz; ++i)
        base[i] = (base[i - 1] * P) % MOD;
    for (int i = 0; i < sz; ++i)
    {
        H = cnt = 0;
        for (int j = i; j < sz; ++j)
        {
            if (binary[s[j] - 'a'] == '0')
                ++cnt;
            if (cnt > k)
                break;
            H = (H + (ll)(s[j] - 'a' + 1) * base[j - i]) % MOD;
            mlb[H] = true;
        }
    }

    cout << (ll)mlb.size();

    return 0;
}
