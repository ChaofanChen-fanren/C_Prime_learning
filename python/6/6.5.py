# 字符串相关操作

my_str = "ILOVEPYTHON"
print(my_str[1])
print(my_str[-1])


# 字符串不能修改
# my_str[1] = '1'


# index(元素)
index = my_str.index("LOVE")
print(index)


# str = str.replace(str,str) 字符串的替换
str = my_str.replace("I","YOU")
print(str)

# 字符串的分割
str = "1 2 3 4 5 6"
my_list = str.split(' ')
print(my_list)


# strip() 除去头尾的空格和换行
str = " ffff  "
str = str.strip()
print(str)
# strip(str)
str = "12fff12ff21"
str = str.strip("12") #除去首尾的字符串1和字符串2
print(str)


# count()
str = "  fff "
print(str.count('f'))

# len()
print(len(str))
