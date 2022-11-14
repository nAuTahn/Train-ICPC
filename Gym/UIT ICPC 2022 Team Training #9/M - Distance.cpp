//    Ahihi To Thich Cau :))
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll x, y;

int ToThichCau() {
    cin >> x >> y;

    if ((x + y) & 1)
        return cout << "-1 -1\n", 1;

    if (x > y)
        cout << (x - y) / 2 << " " << y << "\n";
    else cout << x << " " << (y - x) / 2 << "\n";

    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int test; cin >> test;
    while(test--) ToThichCau();

    return 0;
}
