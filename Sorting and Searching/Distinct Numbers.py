# Problem Link :: https://cses.fi/problemset/task/1621

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
 
# def dfs(a,vis,v):
# 	vis[v]=True
# 	for i in a[v]:
# 		if vis[i]:
# 			return False
# 		c=dfs(a,vis,i)
# 		if c==False:
# 			return False
# 	return True
 
 
n=int(input())
a=linput()
s=set(a)
print(len(s))