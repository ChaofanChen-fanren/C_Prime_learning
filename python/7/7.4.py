# lambda匿名函数

def test_func(compute):
    result = compute(1,2)
    print(type(compute))
    return result


print(test_func(lambda x,y:x + y))
