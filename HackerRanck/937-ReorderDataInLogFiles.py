from typing import List

logs = ["dig1 8 1 5 1", "let1 art can", "dig2 3 6", "let2 own kit dig", "let3 art zero"]
dig_id = "dig"


class Solution:

    def get_log_id(self, log: str):
        return log.split(" ", 1)[0]

    def get_log_content(self, log: str):
        return log.split(" ", 1)[1]

    def is_digit_log(self, log: str):
        return self.get_log_id(log)[:3] == dig_id

    def get_reordered_logs(self, logs: List[str]):
        letter_logs, digit_logs = [], []
        for log in logs:
            if self.is_digit_log(log):
                digit_logs.append(log)
            else:
                letter_logs.append(log)

        letter_logs.sort(
            key=lambda letter_log: (
                self.get_log_content(letter_log),
                self.get_log_id(letter_log)
            ))

        return letter_logs + digit_logs


print(Solution().get_reordered_logs(logs))
