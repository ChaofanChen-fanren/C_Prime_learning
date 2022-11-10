import requests
from lxml import etree
import os
import re
# 导入CSV安装包
import csv
"""
获取网站一页的标题和日期
url: 网址
return: 返回title-[data,url]
"""
def news_page_title(url):
    re = requests.get(url=url)
    re.encoding = "utf-8"
    text = re.text
    tree = etree.HTML(text)
    title = tree.xpath('//*[@id="nav2_7Tabcontent_10"]/tbody/tr') #找到所有的标题路径
    title_date_dict = {}   #标题-日期字典
    for li in title:
        title = ''.join(li.xpath('./td[2]//text()'))
        title_url = 'https://news.hbut.edu.cn/' +''.join(li.xpath('./td[2]//@href'))
        date = ''.join(li.xpath('./td[3]//text()'))
        word = [date,title_url]
        # print(li.xpath('./td[2]//text()'))
        if title == '\xa0':
            continue
        title_date_dict[title] = word
    # title_list.remove('\xa0')
    return title_date_dict

"""
爬取每一页的新闻内容
url: 网址
return: 返回新闻内容
"""
def news_text(url):
    r = requests.get(url=url)
    r.encoding = "utf-8"
    text = r.text
    tree = etree.HTML(text)
    # //*[@id="vsb_content_2"]/div[@class="v_news_content"]
    # //*[@id="vsb_content_6"]/div[@class="v_news_content"]
    # 处理出处
    source = tree.xpath('//*[@class="be12"]//text()') #找到出处
    source = re.sub('\s|\t|\n|\r', '', ''.join(source))
    source = ''.join(re.findall('出处：(.+?)日期',source))  #正则表达式处理出处

    content_list = tree.xpath('//*[@class="v_news_content"]//text()')  # 找到所有的文本的路径
    content = ""
    # for str in content_list:
    #     if '\r\n' not in str:
    #         content = content + str +'\n'
    content = ''.join(content_list)
    # content = re.sub('\s|\t|\n|\r|，|。', '', content) #去掉换行和空格
    content = re.sub('\s|\t|\n|\r', '', content)
    # print(content)
    return [content,source]



def main():
    #创建一个新闻爬取文件 news
    base_path = './news/'
    if not os.path.exists(base_path):
        os.makedirs(base_path)
        print("创建成功")
    # 创建一个文件保存爬取的数据 news.csv
    csv_file = open(base_path + 'news.csv', 'w', encoding ='utf-8', newline ="")
    # 基于文件对象构建 csv写入对象
    csv_writer = csv.writer(csv_file)
    # 构建列表头
    csv_writer.writerow(["新闻标题", "发表日期", "新闻地址","出处","内容"])


    # 获取首页的新闻标题
    url = 'https://news.hbut.edu.cn/hgyw.htm'
    title_date_page_list = news_page_title(url)
    for key in title_date_page_list:
        # print(title_date_page_list)
        new_content = news_text(title_date_page_list[key][1]) # 获取新闻内容
        # print([key,title_date_page_list[key][0],title_date_page_list[key][1],new_content[1],new_content[0]])
        csv_writer.writerow([key,title_date_page_list[key][0],title_date_page_list[key][1],new_content[1],new_content[0]])
        print(key+"已完成")

    print(url+"已完成")



    # 爬取所有的新闻标题和时间
    for index in range(219,225):
        url = 'https://news.hbut.edu.cn/hgyw/' + str(index)+ '.htm'
        title_date_page_list = news_page_title(url)
        for key in title_date_page_list:
            # print(title_date_page_list)
            new_content = news_text(title_date_page_list[key][1])  # 获取新闻内容
            # print([key,title_date_page_list[key][0],title_date_page_list[key][1],new_content[1],new_content[0]])
            csv_writer.writerow([key, title_date_page_list[key][0], title_date_page_list[key][1], new_content[1], new_content[0]])
            print(key + "已完成")
        print(url + "已完成")





    # 将新闻内容写入到txt文件中
    # # 爬取所有的新闻
    # for key in title_date_page_list:
    #     new_title = key.replace(' ','_') #用'_'换掉' '
    #     new_date = title_date_page_list[key][0]
    #     new_url = title_date_page_list[key][1]
    #     new_content = news_text(new_url)
    #     text_path = base_path + '/' + new_title + '.txt'
    #     with open(text_path,'w',encoding='utf-8') as f:
    #         f.write(key + '\n')
    #         f.write(new_date + '\n')
    #         f.write(new_content)




main()

# url = 'https://news.hbut.edu.cn/hgyw.htm'
# title_date_page_list = news_page_title(url)
# print(title_date_page_list)
# news_text('https://news.hbut.edu.cn/info/1002/27551.htm')
# https://news.hbut.edu.cn/info/1002/27740.htm
# https://news.hbut.edu.cn/info/1002/27728.htm
# https://news.hbut.edu.cn/info/1002/27551.htm
