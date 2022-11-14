//    Ahihi To Thich Cau :))
#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

typedef pair <int, int> pii;
#define pb push_back

const int MAXN = 2e5 + 3;
int n;
int m[MAXN], k[MAXN];
pii a[MAXN];
double ans = 0;
vector <int> c;

void ToThichCau() {
    cin >> n;

    for (int i = 1; i <= n; ++i) cin >> m[i] >> k[i];
    for (int i = 1; i <= 20; ++i)
    {
        for (int j = 1; j < MAXN; ++j)
            a[j].F = 0, a[j].S = j;

        for (int j = 1; j <= MAXN; ++j)
            if (k[j] >= i)
                a[m[j]].F += i;
            else a[m[j]].F += k[j];

        sort(a + 1, a + MAXN, [&](pii x, pii y) {return x.F > y.F;});

        int s = 0;
        for (int j = 1; j <= i; ++j) s += a[j].F;

        if (s > ans * i)
        {
            ans = 1.0 * s / i;
            c.clear();
            for (int j = 1; j <= i; ++j)
                c.pb(a[j].S);
        }
    }

    cout << (int)c.size() << "\n";
    for (auto t : c) cout << t << " ";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    ToThichCau();

    return 0;
}
