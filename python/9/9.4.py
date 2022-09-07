# 自定义模块

# # 导入模块和调用功能代码
# from my_module1 import test
# from my_module2 import test # 覆盖上一个

# test(1,1)


# __main__变量

# __all__变量
from my_module1 import *
test_a(1,2)

from my_module1 import test
test(1,2)
