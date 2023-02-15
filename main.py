import random

numbers = []
max = 2**31 - 1
min = - max - 1

random.seed()
i = 0

while i < 100:
	n = random.randint(min, max)
	
	if n not in numbers:
		numbers.append(n)
		i += 1

for n in numbers:
	print(str(n), end=' ')