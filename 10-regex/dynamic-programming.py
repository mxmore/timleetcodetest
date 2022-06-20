class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m, n = len(s), len(p)

        def matches(i: int, j: int) -> bool:
            if j == n:
                # if p is empty, s must be empty
                return i == m
            if j+1 < n and p[j+1] == '*':
                # if p is not empty and next char is '*', match 0 or more times of the previous char in s and p respectively and then match the rest of p and s respectively and then match the rest of s and p respectively
                return matches(i, j+2) or (i < m and (s[i] == p[j] or p[j] == '.') and matches(i+1, j))
            else:
                return i < m and (s[i] == p[j] or p[j] == '.') and matches(i+1, j+1)
        for i in range(m):
            if matches(i, 0):
                return True
            else:
                return False

        return matches(0, 0)


if __name__ == '__main__':
    s = Solution()
    print(s.isMatch("aaAA", "a*"))
