# 模块的导入


# time 的 sleep

# import 模块
import time
print("hello")
time.sleep(5)
print("hello")


# from 函数 import 模块

from time import sleep
print("hello")
sleep(5)
print("hello")


# from 函数 import *
from time import *
print("hello")
sleep(5)
print("hello")


#模块别名
import time as t
print("hello")
t.sleep(5)
print("hello")
