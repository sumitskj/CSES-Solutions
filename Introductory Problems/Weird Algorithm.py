# Problem Link :: https://cses.fi/problemset/task/1068

import sys,os
import math
from fractions import Fraction 
from collections import defaultdict
from random import randint
from itertools import combinations, permutations
 
# sys.stderr=open('err.txt','w')
# sys.stdout=open('output.txt','w')
# sys.stdin=open('input.txt','r')
 
def linput():
    return list(minput())
 
def minput():
    return map(int, sys.stdin.readline().strip().split())
 
###############################################################
 
n=int(input())
print(n, end=' ')
while n!=1:
	if n&1:
		n*=3
		n+=1
	else:
		n//=2
	print(n, end=' ')