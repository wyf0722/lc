from functools import cache
import logging

def exist(x):
    return x is not 1

print(exist(1))
print(exist(None))