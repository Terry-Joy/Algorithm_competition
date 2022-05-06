import os

for i in range(21, 31):
	os.system(f"python3 gen.py > {i}.in")
	os.system(f"./std < {i}.in > {i}.out")