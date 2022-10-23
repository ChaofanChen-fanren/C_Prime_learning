from calendar import month
from django.shortcuts import render
from django.http import HttpResponse
from myadmin.models import News
from django.core.paginator import Paginator
import re
# Create your views here.
def index(request):
    umod = News.objects
    New_lists = umod.all()
    # 统计每个部门发表文章数
    school_dict = {}
    for new in New_lists:
        if new.school == '学校办公室（党办、校办）':
            school_list = ['党办','校办']
        else:
            school_list = re.split('，|、',new.school)
        for s in school_list:
            if s not in school_dict:
                school_dict[s] = 0
            school_dict[s] = school_dict[s] + 1
    school = sorted(school_dict.items(), key = lambda kv:(kv[1], kv[0]),reverse=True)[0:6]
    # 取出前 5个元素
    school = [{"value":v[1],"name":v[0]} for v in school]
    # print(school)

    #展示词云
    import os
    if not os.path.exists('./static/web/photo/new_wordcloud.jpg'):
        showWorldCould()
    

    # 展示词频
    import json
    tf = open("./static/web/photo/myDictionary.json", "r")
    word_list = json.load(tf)[0:7]
    tf.close()
    word_dict = {"word_name":[v['name'] for v in word_list],"word_value":[v['value'] for v in word_list]}
    # print(word_dict)
    

    month_value = show_Month_value()

    # 展示最近前几篇新闻
    page = Paginator(New_lists,7) #以10条每页创建分页对象
    news_page_1 = page.page(1) #只需要第一页

    for new in news_page_1:
        new.title = new.title[0:20]

    context = {"school":school,"newslist":news_page_1,"word_count":word_dict,'month_value':month_value}
    # context = {"data":{"data":[5, 20, 36, 10, 10, 20],"name":['校庆办', '党委组织部', '党委宣传部', '计算机学院', '社会资源处', '经管学院']}}
    # wordCloud()
    return render(request,'web/index.html',context)


def showWorldCould():
    #导入词云库
    from wordcloud import WordCloud
    #导入图像处理库
    import PIL.Image as image
    #导入数据处理库
    import numpy as np
    #导入结巴分词库
    import jieba

    umod = News.objects
    New_lists = umod.all()
    text = ""
    for new in New_lists:
        text += new.content
    # print(text)

    # 统计词频
    words = jieba.lcut(text)
    counts = {}
    word_list = []
    for word in words:
        if len(word) == 1:
            continue
        else:
            counts[word] =counts.get(word,0) + 1
            word_list.append(word)
    items = list(counts.items())
    items.sort(key=lambda x: x[1], reverse=True)
    wordclout_dict = [{"name": k[0], "value": k[1]} for k in items]
    
    #将词频统计存入txt文件
    import json
    tf = open("./static/web/photo/myDictionary.json", "w")
    json.dump(wordclout_dict,tf)
    tf.close()

    #生成词云图
    # word_list = jieba.cut(text,cut_all= True)
    result = " ".join(word_list)
    # print(word_list)
    # import os
    # print(os.listdir("./static/web/photo/"))
    mask = np.array(image.open("./static/web/photo/WCbg.jpg"))
    wordcloud = WordCloud(
        # 遮罩层,除白色背景外,其余图层全部绘制（之前设置的宽高无效）
        mask=mask,
        #默认黑色背景,更改为白色
        background_color='#FFFFFF',
        # 若想生成中文字体,需添加中文字体路径
        font_path="./static/web/photo/阿里巴巴普惠体 B.ttf"
    ).generate(result)
    wordcloud.to_file("./static/web/photo/new_wordcloud.jpg")

    return wordclout_dict


def show_Month_value():
    import pandas as pd
    df = pd.read_csv('./static/web/photo/news.csv')
    # 将日期转化为pandas的 datetime
    df.set_index(pd.to_datetime(df['发表日期']),inplace=True)
    # 统计日期发表篇数
    # print(df)
    # 得到所有月份
    month = [str(v) + '月' for v in list(df.groupby(df.index.month)['新闻标题'].count().index)]
    # 得到所有月份对应的发表篇数
    value = list(df.groupby(df.index.month)['新闻标题'].count())

    return {'month':month,'value':value}
