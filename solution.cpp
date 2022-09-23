#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define spc ' '
#define all(x) x.begin(), x.end()
#define allR(x) x.rbegin(), x.rend()
#define vi(x) vector<x>
#define pii(x, y) pair<x, y>
#define F first
#define S second
#define ll long long
#define pb(x) push_back(x)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, m, cnt = 0;

    while (true)
    {
        cin >> n >> m;
        if (n == 0 || m == 0)
            break;

        char field[n][m], answer[n][m], x = '0';
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> field[i][j];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (field[i][j] != '*')
                {
                    if (i - 1 >= 0)
                    {
                        if (j - 1 >= 0 && field[i - 1][j - 1] == '*')
                            x++;
                        if (field[i - 1][j] == '*')
                            x++;
                        if (j + 1 < m && field[i - 1][j + 1] == '*')
                            x++;
                    }
                    if (j - 1 >= 0 && field[i][j - 1] == '*')
                        x++;
                    if (j + 1 < m && field[i][j + 1] == '*')
                        x++;
                    if (i + 1 < n)
                    {
                        if (j - 1 >= 0 && field[i + 1][j - 1] == '*')
                            x++;
                        if (field[i + 1][j] == '*')
                            x++;
                        if (j + 1 < m && field[i + 1][j + 1] == '*')
                            x++;
                    }
                    answer[i][j] = x;
                    x = '0';
                }
                else
                    answer[i][j] = '*';
            }
        }

        cnt++;
        cout << "\nField #" << cnt << ":\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << answer[i][j];
            cout << endl;
        }
    }
}