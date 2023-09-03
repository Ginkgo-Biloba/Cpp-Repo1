import ctypes
import math
import os
import random
import sys
import time
from datetime import datetime, date, timedelta
from os import path

import numpy as np
import matplotlib
from matplotlib import pyplot as plt
from PIL import Image
import av

from typing import List
import collections
import itertools


class Solution:

	def minAreaFreeRect(self, points: List[List[int]]) -> float:
		points.sort()
		cpx = [complex(*z) for z in points]
		seen = collections.defaultdict(list)
		ans = float("inf")
		for (P, Q) in itertools.combinations(cpx, 2):
			seen[(Q - P)].append((Q + P) / 2)
		for A, cand in seen.items():
			for (P, Q) in itertools.combinations(cand, 2):
				if A.real * (P - Q).real == -A.imag * (P - Q).imag:
					ans = min(ans, abs(A) * abs(P - Q))
		if ans == float("inf"):
			ans = 0
		return ans


a = [[1, 2], [2, 1], [1, 0], [0, 1]]
b = [[0, 1], [2, 1], [1, 1], [1, 0], [2, 0]]
c = [[0, 3], [1, 2], [3, 1], [1, 3], [2, 1]]
d = [[3, 1], [1, 1], [0, 1], [2, 1], [3, 3], [3, 2], [0, 2], [2, 3]]
s = Solution()
print(s.minAreaFreeRect(a))
print(s.minAreaFreeRect(b))
print(s.minAreaFreeRect(c))
print(s.minAreaFreeRect(d))

