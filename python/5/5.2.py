# 传入参数

from unittest import registerResult, result


def add(x,y):
    reslut = x + y
    print(f"{x} + {y} reslut : {reslut}")
add(5,6)


# 返回值
def add(a,b):
    result = a + b
    return result

r = add(5,6)
print(r)


# 返回值为None -> false
def check_age(age):
    if age > 18:
        return "Success"
    else:
        return None

age = 16
result = check_age(age)
if  not result:
    print(f"age {age} <= 18")
