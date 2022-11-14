#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;

string Remove(string s, char c)
{
    string ans;
    for(int i = 0; i < (int)s.size(); ++i)
        if(s[i] != c)
            ans.pb(s[i]);

    return ans;
}

void solve()
{
    string s; cin >> s;
        string p;
        vector<int> nxt(26, 0);
        for(int i = (int)s.size() - 1; i >= 0; --i)
        {

            if((int)p.size() == 0) p.pb(s[i]);
            else {
                if(nxt[s[i] - 'a'] == 0)
                {
                    p.pb(s[i]);
                }
            }
            nxt[s[i] - 'a']++;
        }

        string pos = "";
        int i = 0, j = 0;
        bool ok = false;

        while(j < (int)p.size())
        {
            if(nxt[p[j] - 'a'] % ((int)p.size() - j) != 0)
            {
                ok = true;
                break;
            }
            i += (nxt[p[j] - 'a']) / ((int)p.size() - j);
            j++;
        }
        if(ok)
        {
            cout << -1 << endl;
            return;
        }

        pos = s.substr(0, i);
        reverse(p.begin() , p.end());
        j = 0;

        string tmp = pos;
        string t = pos;
        while(j < (int)p.size())
        {
            pos = Remove(pos, p[j]);
            t += pos;
            j++;
        }

        if((int)pos.size() == 0 && t == s)
            cout << tmp << " " << p << endl;
        else
            cout << -1 << endl;
}

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}
