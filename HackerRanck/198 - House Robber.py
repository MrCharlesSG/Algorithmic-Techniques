


def longestPalindrome(s: str) -> str:
    def is_palindromic(l: int, r: int, s: str):
        nonlocal max_l, max_r
        while 0 <= l and r < len(s) and s[l] == s[r]:
            if r - l > max_r - max_l:
                max_r = r
                max_l = l
            l -= 1
            r += 1

    max_l, max_r = 0, 0
    for i in range(len(s)):
        is_palindromic(i, i, s)
        is_palindromic(i, i + 1, s)

    return s[max_l : max_r + 1]


s = "babadaadsab"

print(longestPalindrome(s))