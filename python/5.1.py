# 函数

str1 = "11223"
str2 = "python"
str3 = "ccf"


# 使用函数
def my_len(data):
    count = 0
    for i in data:
        count += 1
    print(f"string of {data} length : {count}")

my_len(str1)
my_len(str2)
my_len(str3)

