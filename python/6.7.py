# 集合

# 定义集合
my_set = {1,2,3,3,3}
my_set_empty = set()
print(my_set)
print(my_set_empty)

# 不支持下标访问

# 添加元素 add(元素)
my_set.add(1)
my_set.add(4)
print(my_set)

# remove(元素)
my_set.remove(4)
print(my_set)

# pop() 随机取出一个
print(my_set.pop())
print(my_set)


# 取两个集合的差集 difference(set)
set1 = {1,2,3}
set2 = {1,5,6}
set3 = set1.difference(set2)
print(set1)
print(set2)
print(set3)

set1.difference_update(set2)
print(set1)
print(set2)
print(set3)


# union(set)
set1 = {1,2,3}
set2 = {1,5,6}
set3 = set1.union(set2)
print(set1)
print(set2)
print(set3)

#len
set1 = {1,2,3,2,3,4}
print(len(set1))


# 遍历集合
for element in set1:
    print(element)
    
