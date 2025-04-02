from typing import List


def solve_two_sum(nums_list: List[int], target: int):
    num_target = {}
    for i, num in enumerate(nums_list):
        actual_target = target - num
        print(actual_target, " ", num_target)
        if actual_target in num_target:
            return [num_target[actual_target], i]
        num_target[num] = i
    return None


nums = [2, 7, 11, 15]
target_aux = 9
print(solve_two_sum(nums, target_aux))
