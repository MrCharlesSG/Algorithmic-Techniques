from typing import List
from collections import defaultdict
from itertools import combinations

username_data = ["joe", "joe", "joe", "james", "james", "james", "james", "mary", "mary", "mary"]
timestamp_data = [1, 3, 2, 4, 5, 6, 7, 8, 9, 10]
website_data = ["home", "about", "career", "home", "cart", "maps", "home", "home", "about", "career"]

'''
username_data = ["ua", "ua", "ua", "ub", "ub", "ub"]
timestamp_data = [1, 2, 3, 4, 5, 6]
website_data = ["a", "b", "a", "a", "b", "c"]
'''


def mostVisitedPattern(username: List[str], timestamp: List[int], website: List[str]):
    users = defaultdict(list)
    for i, u in enumerate(username):
        users[u].append(website[i])


    max_pattern, max_count = "", 0
    scores = defaultdict(int)
    for user, website_of_user in users.items():
        for pattern in combinations(website_of_user, 3):
            scores[pattern] += 1
            if max_count < scores[pattern] or (max_count == scores[pattern] and pattern < max_pattern):
                max_pattern = pattern
                max_count = scores[pattern]
    return max_pattern, max_count




print(mostVisitedPattern(username_data, timestamp_data, website_data))
