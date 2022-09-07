# 异常的传递

# 定义一个出现异常的方法
def func1():
    print("func1 start")
    1/0
    print("func1 end")

# 定义一个无异常的方法，调用上面的方法

def func2():
    print("func2 start")
    func1()
    print("func2 end")
    
# 定义一个方法 调用上面的方法
def main():
    try:
        func2()
    except Exception as e:
        print(e)


main()
