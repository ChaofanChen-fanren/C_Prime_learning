# 传入参数

from ast import arg


def user_info(name,age,gender='男'):
    print(f"name:{name},age:{age},gender:{gender}")

# 位置参数
user_info("A",20,'男')

# 关键字参数
user_info(name='A',age=10,gender='男')
user_info(age=10,name='A',gender='男')
user_info('A',age=10,gender='男')


# 缺省参数
user_info("A",20)
user_info(age=10,name='A')


# 不定长参数 位置不定长 *号
def user_info(*args):
    print(args)
    print(type(args))
user_info(1,2,3,'ffff')

# 不定长参数 关键字不定长 **号

def user_info(**kwargs):
    print(kwargs)
    print(type(kwargs))
user_info(name='nnn',age=20)
