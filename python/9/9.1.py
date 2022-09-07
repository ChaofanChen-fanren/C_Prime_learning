"""
捕获异常
"""

#基本捕获语法
try:
    f = open("1.txt","r",encoding="UTF-8")
except:
    print("file not exist")


# 捕获指定异常
try:
    print("hello")
    # print(name)
except NameError as e:
    print("variable don't defined")
    print(e)

# 捕获多个异常
try:
    print(1/0)
    # print(name)
except(NameError,ZeroDivisionError):
    print("NameError or ZeroDivisionError")

# 捕获所有异常
try:
    f = open("1.txt","r",encoding="UTF-8")
except:
    print("file not exist")

try:
    1/0
except Exception as e:  #顶级异常
    print("error")

# 异常else
try:
    f = open("1.txt","r",encoding="UTF-8")
except:
    print("file not exist")
else:
    print("happy not error")

# 异常的finally 无论如何都执行
try:
    f = open("1.txt","r",encoding="UTF-8")
except:
    print("file not exist")
else:
    print("hello")
finally:
    print("finally")
