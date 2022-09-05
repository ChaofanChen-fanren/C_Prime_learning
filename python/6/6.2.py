# list相关操作

my_list = [1,2,3,4,5]

# 查询 index()
print(my_list.index(1))
# print(my_list.index(6))
my_list[0] = 6
print(my_list[0])


#insert(下标，元素)
my_list.insert(1,2)
print(my_list)

# append(元素) 追加单个元素
my_list.append(7)
print(my_list)

# extend(容器) 一批元素
my_list.extend([1,2,3])
print(my_list)


# 删除
# del list[下标]
del my_list[2]
print(my_list)

# pop(下标)
element = my_list.pop(1)
print(element,my_list)

# remove(元素)
my_list.remove(2)
print(my_list)


# clear() 清空列表
my_list.clear()
print(my_list)


# count(元素)
print(my_list.count(1))


# len(列表)
length = len(my_list)
print(length)
