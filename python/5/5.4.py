# 函数的嵌套使用

def func_a():
    print("a")

def func_b():
    print("b")
    func_a()

func_b()
