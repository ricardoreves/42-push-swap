#!/usr/bin/env python
# -*- coding: utf-8 -*-

import random
import sys

if (len(sys.argv) != 4):
	print("Usage: python3 setnum.py [min] [max] [size]")
	exit(1)

min = int(sys.argv[1])
max = int(sys.argv[2])
size = int(sys.argv[3])
numbers = random.sample(range(min, max), size)
print("%s" % " ".join([str(num) for num in numbers]))