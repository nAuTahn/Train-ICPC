//    Ahihi To Thich Cau :))
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, a, b;

int ToThichCau() {
    cin >> n >> a >> b;

//    Thuoc ve 2 nua ==> exist
    if ((a <= n / 2 && b >= n / 2 + 1) || (a == n / 2 + 1 && b == n / 2))
    {
        cout << a << " ";
        for (int i = n; i >= 1; --i)
            if (i != a && i != b)
                cout << i << " ";
        cout << b << "\n";
    }
    else cout << "-1\n";

    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int test; cin >> test;
    while(test--)
        ToThichCau();

    return 0;
}
