"""
元组
"""

#定义元组
t1 = (1,"Hello",True)
t2 = ()
t3 = tuple()
print(type(t2))


# 定义单个元组加个逗号 ， 否则不是元组
t3 = ("hello")
print(type(t3))
t4 = ("hello",)
print(type(t4))


#元组的嵌套
t5 = ((1,2,3),(3,4,5))
print(type(t5))

#索引
print(t5[-1][-1])



# index(元素) 
print(t1.index(1))
# count(元素)
print(t1.count(1))
# len(元组)
print(len(t1))


# 元组中的list可以修改内容 可以添加
t2 = (1,[1,2,3])
t2[1][0] = 4
t2[1].append(2)
print(t2)
