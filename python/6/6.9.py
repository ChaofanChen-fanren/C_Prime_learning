my_list = [1,2,3,4,5]
my_tuple = (1,2,3,4,5)
my_str = "abcdefg"
my_set = {1,2,3,4}
my_dict = {"key1":1,"key2":2,"key3":3,"key4":4,"key5":5}

# len()
print(len(my_list))
print(len(my_tuple))
print(len(my_str))
print(len(my_set))
print(len(my_dict))

# max()
print(max(my_list))
print(max(my_tuple))
print(max(my_str))
print(max(my_set))
print(max(my_dict))

# min()
print(min(my_list))
print(min(my_tuple))
print(min(my_str))
print(min(my_set))
print(min(my_dict))


# 容器转为list
print("-- list() --")
print(list(my_list))
print(list(my_tuple))
print(list(my_str))
print(list(my_set))
print(list(my_dict))

# 容器转为tuple
print("-- tuple() --")
print(tuple(my_list))
print(tuple(my_tuple))
print(tuple(my_str))
print(tuple(my_set))
print(tuple(my_dict))

# 容器转为str
print("-- str() --")
print(str(my_list))
print(str(my_tuple))
print(str(my_str))
print(str(my_set))
print(str(my_dict))

# 容器转集合
print("-- set() --")
print(set(my_list))
print(set(my_tuple))
print(set(my_str))
print(set(my_set))
print(set(my_dict))


# 容器排序 
print("-- sorted() --") #正向排序
print(sorted(my_list))
print(sorted(my_tuple))
print(sorted(my_str))
print(sorted(my_set))
print(sorted(my_dict))

print("-- sorted() --") #正向排序
print(sorted(my_list,reverse=True))
print(sorted(my_tuple,reverse=True))
print(sorted(my_str,reverse=True))
print(sorted(my_set,reverse=True))
print(sorted(my_dict,reverse=True))
