from email.contentmanager import raw_data_manager
import imp
from random import *
from random import *

T = randint(1, 100)
print(T)
for i in range(T):
	n = randint(1, 1000000000)
	m = randint(1, 100000)
	print(n, m, ' ', end = '')
	if i != T - 1:
		print()