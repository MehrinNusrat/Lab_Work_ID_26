#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int simulate(const vector<int>& p, int x) {
    int l = 0;
    int r = p.size();
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if(p[m] <= x)
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    return l;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> p(n);
        for(int i = 0; i < n; ++i)
        {
            cin >> p[i];
        }

        int originalTarget = simulate(p, x);
        if(p[originalTarget] == x)
        {
            cout << "0\n";
            continue;
        }

        vector<tuple<int, int, int, int>> twoSwap; // (a,b,c,d)
        vector<pair<int, int>> oneSwap;

        for(int a = 0; a < n; ++a)
        {
            for(int b = a + 1; b < n; ++b)
            {
                swap(p[a], p[b]);
                for(int c = 0; c < n; ++c)
                {
                    for(int d = c + 1; d < n; ++d)
                    {
                        if(c == a && d == b)
                        {
                            continue;
                        }
                        swap(p[c], p[d]);
                        int l = simulate(p, x);
                        if(p[l] == x)
                        {
                            twoSwap.emplace_back(a + 1, b + 1, c + 1, d + 1);
                        }
                        swap(p[c], p[d]);
                    }
                }
                swap(p[a], p[b]);
            }
        }

        if(!twoSwap.empty())
        {
            sort(twoSwap.begin(), twoSwap.end());
            cout << "2\n";
            auto [a, b, c, d] = twoSwap[0];
            cout << a << " " << b << "\n" << c << " " << d << "\n";
            continue;
        }

        for(int a = 0; a < n; ++a)
        {
            for(int b = a + 1; b < n; ++b)
            {
                swap(p[a], p[b]);
                int l = simulate(p, x);
                if(p[l] == x)
                {
                    oneSwap.emplace_back(a + 1, b + 1);
                }
                swap(p[a], p[b]);
            }
        }

        if(!oneSwap.empty())
        {
            sort(oneSwap.begin(), oneSwap.end());
            cout << "1\n" << oneSwap[0].first << " " << oneSwap[0].second << "\n";
            continue;
        }

        cout << "-1\n";
    }
    return 0;
}
