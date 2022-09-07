# open(name,mode,...,encoding)

f = open("test.txt","r",encoding="UTF-8")
print(type(f))

# read(number) read()
# print(f"read 10: {f.read(10)}")
# print(f"read all: {f.read()}")


# readlines() 
# print(f.readlines())

# readline()
# print(f.readline())


# for 循环读文件行
for line in f:
    print(line)

# time.sleep()
# 文件关闭
f.close()

# with open()
with open("test.txt","r",encoding="UTF-8") as f:
    for line in f:
        print(line)
