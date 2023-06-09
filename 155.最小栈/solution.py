class MinStack:

    def __init__(self):
        self.valStack = []
        self.minStack = [1e32]

    def push(self, val: int) -> None:
        self.valStack.append(val)
        self.minStack.append(min(val, self.minStack[-1]))

    def pop(self) -> None:
        self.valStack.pop()
        self.minStack.pop()

    def top(self) -> int:
        return self.valStack[-1]

    def getMin(self) -> int:
        return self.minStack[-1]