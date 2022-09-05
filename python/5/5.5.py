# 局部变量 和 全局变量

# # 访问全局变量
# num = 200

# def test_1():
#     print(num)

# def test_2():
#     print(num)

# test_1()
# test_2()
# print(num)

# num = 200

# def test_1():
#     print(num)

# def test_2():
#     num = 500  #局部变量
#     print(num)

# test_1()
# test_2()
# print(num)

# global 关键字,在函数内声明变量为全局变量

num = 200

def test_1():
    print(num)

def test_2():
    global num #使用全局变量
    num = 500  #全局变量
    print(num)

test_1()
test_2()
print(num)
