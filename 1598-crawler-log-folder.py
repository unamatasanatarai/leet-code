class Solution:
    def minOperations(self, logs: List[str]) -> int:
        cnt = 0
        for f in logs:
            if f == "../":
                cnt = max(0, cnt - 1)
            elif f == "./":
                pass
            else:
                cnt += 1
        return cnt
