# 写入文件

# w覆盖写
# 打开文件
f = open("test.txt","w",encoding="UTF-8")
# 文件写入
f.write("Hello World\n")
# 文件刷新
f.flush()
f.close()


# a追加写

f = open("test.txt","a",encoding="UTF-8")
f.write("I love python")
f.flush()
f.close()
