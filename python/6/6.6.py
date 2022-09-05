# 序列


# 切片 序列[起始下标:结束下标:步长]

my_list = [0,1,2,3,4]
print(my_list[1:4]) #默认步长为1
print(my_list[:]) #不写，起始到结尾步长为1

print(my_list[::2])#步长为2
print(my_list[::-1])#反转


print(my_list[3:1:-1])
