from collections import deque

queue = deque(["hi1", "hi2", "hi3"])
print(queue)

queue.append("hi4")
print(queue)

print(queue.popleft())
print(queue)
