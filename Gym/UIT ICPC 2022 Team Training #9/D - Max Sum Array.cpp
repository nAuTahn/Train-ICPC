//    Ahihi To Thich Cau
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

const ll MAXN = 1e6 + 7;

ll f[MAXN], cnt[MAXN];
ll c[MAXN];

void ToThichCau() {
    f[0] = 1; f[1] = 1;
    for (int i = 2; i <= 500007; ++i)
    {
        f[i] = f[i - 1] * i;
        f[i] %= MOD;
    }

    ll m; cin >> m;
    ll s = 0;
    for (int i = 1; i <= m; ++i)
    {
        cin >> c[i];
        cnt[c[i]]++;
        s += c[i] % MOD;
    }

    s %= MOD;
    ll k = 0, l = 1;

    for (int i = MAXN; i >= 2; --i)
    {
        if (cnt[i] == 0)
            continue;
        k += ((((i - 1) * cnt[i]) % MOD) * (((s - cnt[i]) + MOD) % MOD)) % MOD;
        k %= MOD;
        l *= (((f[cnt[i]] * f[cnt[i]]) % MOD)) % MOD;
        l %= MOD;
        s -= 2 * cnt[i];
        cnt[i - 2] += cnt[i];
        s = (s + MOD) % MOD;
    }
    cout << k << " " << (l * f[cnt[1]]) % MOD << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int test = 1; //cin >> test;
    while(test--) {
        ToThichCau();
    }

    return 0;
}
