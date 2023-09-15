class Solution:
    def countTime(self, time: str) -> int:
        hour, minute = 1, 1

        if time[0] == '?' and time[1] == '?':
            hour = 24
        elif time[0] == '?':
            if int(time[1]) <= 3:
                hour = 3
            else:
                hour = 2
        elif time[1] == '?':
            if int(time[0]) <= 1:
                hour = 10
            else:
                hour = 4

        if time[3] == '?':
            minute *= 6
        if time[4] == '?':
            minute *= 10
        return hour + minute
