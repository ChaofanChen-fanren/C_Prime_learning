# 演示python的包

# 自定义包
# 文件夹里面要有__init__.py


# 导入自定义的包的模块

# import my_package.my_module1
# import my_package.my_module2

# my_package.my_module1.info_print1()
# my_package.my_module2.info_print2()

from my_package import my_module1
from my_package import my_module2

from my_package.my_module1 import info_print1
from my_package.my_module2 import info_print2


# import * 
# __all__ 在包里面的__init__.py里面写

