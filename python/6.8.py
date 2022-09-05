# 字典

# 定义字典 不允许重复key  key:value
my_dict = {'A':0,'B':1,'C':2}
my_dict_empty = {}
my_dict_empty = dict()
print(my_dict)


# dict[key] = value
print(my_dict['A'])

# dict嵌套
stu_score_dict = {
    "A":{"math":99,"english":90},
    "B":{"math":98,"english":91},
    "C":{"math":97,"english":92}
}
print(stu_score_dict)

print(stu_score_dict["A"]["math"])

# 新增元素 修改元素
my_dict = {'A':0,'B':1,'C':2}
my_dict["D"] = 3
my_dict["A"] = 2
print(my_dict)

# 删除元素
value = my_dict.pop('A')
print(value)
print(my_dict)

# clear() 清空
my_dict.clear()
print(my_dict)


# 获取全部的key 遍历
my_dict = {'A':0,'B':1,'C':2}
keys = my_dict.keys()
# 遍历
for key in keys:
    print(my_dict[key])

# 直接for循环
for key in my_dict:
    print(my_dict[key])

# len()
print(len(my_dict))
 