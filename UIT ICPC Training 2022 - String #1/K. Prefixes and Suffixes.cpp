#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 5007;
const int MOD = 1e9 + 7;

string s;

vector <int> Zfunction(string S) {
    int L = 0, R = 0;
    int n = S.size();
    vector <int> Z(n);
    Z[0] = 0;
    for (int i = 1; i < n; i++)
       if (i > R)
       {
          L = R = i;
          while (R < n && S[R] == S[R - L]) R++;
          Z[i] = R - L; R--;
       }
       else
       {
          int k = i - L;
          if (Z[k] < R - i + 1) Z[i] = Z[k];
          else
          {
              L = i;
              while (R < n && S[R] == S[R - L]) R++;
              Z[i] = R - L; R--;
          }
       }
    return Z;
}

void solve()
{
    int sz = s.size();
    vector<int> hz = Zfunction(s);
    hz[0] = sz;
    vector<int> tmp = hz;
    sort(tmp.begin(), tmp.end());

    vector<pii> ans;
    for (int i = 0; i < sz; ++i)
    {
       if(hz[i] == sz - i)
       {
           int idx = upper_bound(tmp.begin(), tmp.end(), sz) - lower_bound(tmp.begin(), tmp.end(), hz[i]);
           ans.pb({hz[i], idx});
       }
    }

    sort(ans.begin(), ans.end());

    cout << (int)ans.size() << endl;
    for (auto t : ans)
        cout << t.F << ' ' << t.S << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> s;

    solve();

    return 0;
}
