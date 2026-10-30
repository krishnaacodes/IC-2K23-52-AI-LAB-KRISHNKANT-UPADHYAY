
from collections import deque

j1 = int(input("Enter Jug 1 capacity: "))
j2 = int(input("Enter Jug 2 capacity: "))
target = int(input("Enter target capacity: "))

start = (0, 0)

queue = deque([(start, [])])
visited = set()

while queue:

    (a, b), steps = queue.popleft()

    if (a, b) in visited:
        continue

    visited.add((a, b))

    if a == target:
        print("\nSolution Found!")

        for i, step in enumerate(steps):
            print("Step", i + 1, ":", step)

        print("Final State:", (a, b))
        break

    operations = [
        ((j1, b), "Fill Jug 1"),
        ((a, j2), "Fill Jug 2"),
        ((0, b), "Empty Jug 1"),
        ((a, 0), "Empty Jug 2"),

        ((a - min(a, j2-b), b + min(a, j2-b)),
         "Transfer Jug 1 to Jug 2"),

        ((a + min(b, j1-a), b - min(b, j1-a)),
         "Transfer Jug 2 to Jug 1")
    ]

    for state, action in operations:
        if state not in visited:
            queue.append((state, steps + [action]))

else:
    print("No solution possible.")
