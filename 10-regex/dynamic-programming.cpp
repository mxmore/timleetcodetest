#include <iostream>
#include <vector>
#include <string>
#include <time.h>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size();
        int n = p.size();

        auto matches = [&](int i, int j)
        {
            // Check i
            if (i == 0)
            {
                return false;
            }

            // Check p[j - 1] is a matches sign '.'
            if (p[j - 1] == '.')
            {
                return true;
            }

            return s[i - 1] == p[j - 1];
        };

        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        f[0][0] = true;
        // Hello  H*llo
        for (int i = 0; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                // cout << "p[" << j - 1 << "] is " << p[j - 1] << endl;
                if (p[j - 1] == '*')
                {
                    f[i][j] |= f[i][j - 2];
                    if (matches(i, j - 1))
                    {
                        // cout << "matches" << i << "," << j - 1 << endl;
                        f[i][j] |= f[i - 1][j];
                    }
                }
                else
                {
                    if (matches(i, j))
                    {
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
        }

        return f[m][n];
    }
};

int main()
{
    cout << "Start dynamic programming for regular expression. " << endl;
    Solution *sol = new Solution();

    string str1 = "HhhhhhhhhhhHello";
    string pattern = ".*";

    clock_t start = clock();
    bool res = sol->isMatch(str1, pattern);
    clock_t end = clock();

    double timespan = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Complete test with match result is : " << res << " seconds: " << timespan << endl;

    delete sol;
}