# 遍历list

my_list = [1,2,3]

def while_func(my_list):
    index = 0
    while index < len(my_list):
        print(my_list[index])
        index += 1

def for_func(my_list):
    for element in my_list:
        print(element)

while_func(my_list)
for_func(my_list)
