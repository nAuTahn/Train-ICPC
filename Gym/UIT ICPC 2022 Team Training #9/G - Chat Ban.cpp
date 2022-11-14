//    Ahihi To Thich Cau :))
#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

typedef pair <int, int> pii;
typedef long long ll;
#define pb push_back
const ll INF = 10000000000LL;

const int MAXN = 2e5 + 3;
ll k, x;

bool ok(ll p)
{
    ll s = 0;
    if (p > k)
        s += (k + 1) * k / 2 + (3 * k - p - 1) * (p - k) / 2;
    else s += (p + 1) * p / 2;

    return x > s;
}

void ToThichCau()
{
    cin >> k >> x;
    ll l = -1, r = 2 * k - 1, ans = 0;

    while(r >= l)
    {
        ll mid = (l + r) / 2;
        if (ok(mid - 1))
        {
            l = mid + 1;
            ans = mid;
        }
        else r = mid - 1;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int test; cin >> test;
    while(test--)
        ToThichCau();
    return 0;
}
