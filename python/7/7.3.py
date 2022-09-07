# 函数做为传递参数

def test_func(compute):
    result = compute(1,2)
    print(type(compute))
    return result

def compute(x,y):
    return x + y

 
print(test_func(compute))
