"""
文件备份
"""

# 打开文件
fr = open("1.txt","r",encoding="UTF-8")
fw = open("2.txt","w",encoding="UTF-8")

for line in fr:
    line = line.strip() #处理掉首尾的换行
    if line.split(",")[4] == "测试":
        continue
    line = line + '\n'
    fw.write(line)
# 关闭两个文件
fr.close()
fw.close()
