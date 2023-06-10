class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        m = len(temperatures)
        st = []
        ans = [0] * m
        for i in range(m):
            while len(st) != 0 and temperatures[i] > temperatures[st[-1]]:
                ans[st[-1]] = i - st[-1]
                st.pop()
            st.append(i)
        return ans
