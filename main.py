import random
import os

random.seed()
for i in range(0, 100):
	print(str(random.randint(-50000, 50000)) + " ", end="")