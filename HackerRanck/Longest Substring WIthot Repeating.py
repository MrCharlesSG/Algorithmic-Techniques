def solve(s: str):
    last_index, counter, max_counter = 0, 1, 1
    in_series = {s[0]: last_index}

    for i in range(1, len(s) - 1):
        if s[i] not in in_series or in_series[s[i]] < last_index:
            counter += 1
            in_series[s[i]] = i
        else:
            if counter > max_counter:
                max_counter = counter
                counter = i - in_series[s[i]]

            last_index = in_series[s[i]] + 1
            in_series[s[i]] = i

    if counter > max_counter:
        max_counter = counter
    return max_counter


s1 = "abcabcbb"
s2 = "abcabcadbb"
s3 = "abcabcadbbabcde"
print(solve(s1))
print(solve(s2))
print(solve(s3))
