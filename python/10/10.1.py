# json

import json
# 准备列表，列表每一个元素都是字典，将其转换为JSON
data = [{"name":"张三","age":11},{"name":"李四","age":13},{"name":"王五","age":19}]
json_str = json.dumps(data,ensure_ascii=False)

print(type(json_str))
print(json_str)

# 准备字典将其转换为JSON
d = {"name":"张三","age":11}
json_str = json.dumps(d,ensure_ascii=False)
print(type(json_str))
print(json_str)


# 将json转化为列表
s = '[{"name": "张三", "age": 11}, {"name": "李四", "age": 13}, {"name": "王五", "age": 19}]'
l = json.loads(s)
print(type(l))
print(l)

# 将json转化为字典
s = '{"name": "张三", "age": 11}'
dict = json.loads(s)
print(type(dict))
print(dict)
