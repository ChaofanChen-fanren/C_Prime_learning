__all__ = ['test_a'] #对import *有用


def test(a,b):
    print(a+b)

def test_a(a,b):
    print(a-b)


if __name__ == '__main__': # 测试
    test(1,2)
