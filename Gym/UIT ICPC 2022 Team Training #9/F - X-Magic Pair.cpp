//    Ahihi To Thich Cau :))
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a, b, x;

int ToThichCau() {
    cin >> a >> b >> x;

    while(a != 0 && b != 0)
    {
        if (a > b) swap(a, b);
        if ((b % a == x % a) && b >= x)
            return cout << "YES\n", 1;
        b %= a;
    }

    return cout << "NO\n", 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int test; cin >> test;
    while(test--)
        ToThichCau();

    return 0;
}
