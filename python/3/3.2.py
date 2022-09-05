# if statment

age = int(input("your age: "))
if age >= 18:
    print(">= 18")
elif age >= 9:
    print("9 <= age < 18")
else:
    print("< 9")
print("----")


# 嵌套判断


age = int(input("your age: "))
if age >= 18:
    if age >= 90:
        print("hhhhh")
    elif age < 90:
        print("yyyyy")
    print(">= 18")
elif age >= 9:
    print("9 <= age < 18")
else:
    print("< 9")
print("----")
