import pandas as pd
import pymysql

#定义操作函数
def insert_data():
    liData = []
    num = 0 
    cursor = db.cursor()
    line_data = data_list.iloc[0]
    #读取第每行中每列数据

    # 测试数据
    # value = (str(line_data[0]),str(line_data[1]),str(line_data[2]),str(line_data[3]),str(line_data[4]))
    # liData.append(value)
    # print(liData)
    # sql = "INSERT INTO `news_table`(title,date,urls,school,content)VALUES(%s,%s,%s,%s,%s)"
    # cursor.executemany(sql, liData)  # 执行sql语句
    # 利用shape的第一个元素来获取数据的数量

    for i in range(0,data_list.shape[0]):
        # 获取第每行数据
        line_data = data_list.iloc[i]
         #读取第每行中每列数据
        value = (str(line_data[0]),str(line_data[1]),str(line_data[2]),str(line_data[3]),str(line_data[4]))
        # print(value)
        liData.append(value)
        num +=1
        if num==10000:
            sql = "INSERT INTO `news_table`(title,date,urls,school,content)VALUES(%s,%s,%s,%s,%s)"
            cursor.executemany(sql, liData)  # 执行sql语句
            db.commit()
            num = 0  # 计数归零
            liData.clear()  # 清空list
    # 不足10000的插入
    sql = "INSERT INTO `news_table`(title,date,urls,school,content)VALUES(%s,%s,%s,%s,%s)"
    cursor.executemany(sql, liData)  # 执行sql语句
    db.commit()
    num = 0  # 计数归零
    liData.clear()  # 清空list
    

    cursor.close()
    db.close()


# 读取数据
data_list = pd.read_csv(r'./news.csv')
data_list.head()

#连接数据库
db = pymysql.connect(host="localhost",user="root", passwd="dees",db="news_db",charset='utf8')
# 创建表
# 创建游标
cursor = db.cursor()
sql_create_db = "CREATE DATABASE IF NOT EXISTS news_db"
# 执行创建数据库的sql
cursor.execute(sql_create_db)

# 如果存在此表就删除
sql_create_table = "DROP TABLE IF EXISTS `news_table`;"
cursor.execute(sql_create_table)
# 创建表
sql_create_table = '''CREATE TABLE IF NOT EXISTS `news_table` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `title` VARCHAR(255) NOT NULL,
  `date` DATE,
  `urls` VARCHAR(255) NOT NULL,
  `school` VARCHAR(255),
  `content` TEXT,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
'''
cursor.execute(sql_create_table)
#执行函数 
insert_data()
