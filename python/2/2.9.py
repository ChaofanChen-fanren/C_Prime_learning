# 字符串格式化
# 通过占位符

name = "I love"
string = "%s python" % name
print(string)


class_num = 57
avg_salary = 10
string = "hhh class: %s, salary: %s" % (class_num,avg_salary)
print(string)


# %s %d %f
name = "I"
int_num = 111
float_num = 1.22
print("%s : %d : %f" % (name,int_num,float_num))
