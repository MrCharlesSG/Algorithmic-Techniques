from math import sqrt


class Solution:
    def get_k_closest_point(self, k, points):
        distances = []
        for p in points:
            distances.append([
                sqrt(pow(p[0], 2) + pow(p[1], 2)),
                p[0],
                p[1]
            ])

        distances.sort(key=lambda d: [d[0]])
        return distances[:k]


print(Solution().get_k_closest_point(
    3, [[2, 4], [4, 5], [1, 2], [9, 10], [4, 2]]
))
