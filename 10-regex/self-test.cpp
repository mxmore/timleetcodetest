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
        int n = p.size(); // p[n - 1] is the last character of p

        if (m < n)
        {
            return false;
        }

        auto matches = [&](int i, int j)
        {
            if (i == 0)
            {
                return false;
            }

            if (p[j - 1] == '.')
            {
                return true;
            }

            return s[i - 1] == p[j - 1];
        };

        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        f[0][0] = true;

        for (int i = 0; i < m; i++)
        {

            // 从 j = 1 开始，因为 f[0][0] = true;
            for (int j = 1; j < n; j++)
            {

                cout << "f[" << i << "][" << j << "] =" << f[i][j] << endl;

                if (p[j - 1] == '*')
                {
                    f[i][j] |= f[i][j - 1];
                    if (matches(i, j))
                    {
                        f[i][j] |= f[i - 1][j];
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    cout << "Start dynamic programming for regular expression. " << endl;
    Solution *sol = new Solution();

    string str1 = "Hello";
    string parten = "H*o";

    clock_t start = clock();
    bool res = sol->isMatch(str1, parten);
    clock_t end = clock();

    double timespan = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Complete test with match result is : " << res << " seconds: " << timespan << endl;

    delete sol;
}