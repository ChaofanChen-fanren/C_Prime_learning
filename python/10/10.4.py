# 折线图的可视化

import json
from pyecharts.charts import Line
from pyecharts.options import *
# 处理数据
us_file = open("折线图数据/美国.txt","r",encoding="UTF-8")
us_data = us_file.read()
us_data = us_data.replace("jsonp_1629344292311_69436(","")
us_data = us_data[:-2]
us_dict = json.loads(us_data)
# print(us_dict)

in_file = open("折线图数据/印度.txt","r",encoding="UTF-8")
in_data = in_file.read()
in_data = in_data.replace("jsonp_1629350745930_63180(","")
in_data = in_data[:-2]
in_dict = json.loads(in_data)
# print(in_dict)


jp_file = open("折线图数据/日本.txt","r",encoding="UTF-8")
jp_data = jp_file.read()
jp_data = jp_data.replace("jsonp_1629350871167_29498(","")
jp_data = jp_data[:-2]
jp_dict = json.loads(jp_data)
# print(jp_dict)


# 获取trend key
us_trend_data = us_dict['data'][0]['trend']
in_trend_data = in_dict['data'][0]['trend']
jp_trend_data = jp_dict['data'][0]['trend']


# 获取日期 用于x轴 取2020年
us_x_data = us_trend_data['updateDate'][:314]
in_x_data = in_trend_data['updateDate'][:314]
jp_x_data = jp_trend_data['updateDate'][:314]

# y轴确诊数据
us_y_data = us_trend_data['list'][0]['data'][:314]
in_y_data = in_trend_data['list'][0]['data'][:314]
jp_y_data = jp_trend_data['list'][0]['data'][:314]


# 生成图表
line = Line()

# 添加x轴数据
line.add_xaxis(us_x_data)

# 添加y轴数据 
line.add_yaxis("美国确诊人数",us_y_data,label_opts=LabelOpts(is_show=False))
line.add_yaxis("日本确诊人数",jp_y_data,label_opts=LabelOpts(is_show=False))
line.add_yaxis("印度确诊人数",in_y_data,label_opts=LabelOpts(is_show=False))

# 设置全局选项
line.set_global_opts(
    #标题设置
    title_opts=TitleOpts(title="2020年美日印三国确诊人数对比折线图",pos_left="center",pos_bottom="1%"),
    xaxis_opts=AxisOpts(name="时间"),
    yaxis_opts=AxisOpts(name="累计确诊人数"),
    legend_opts=LegendOpts(pos_left='70%')
)


# 调用render方法，生成图表
line.render("折线图.html")

#关闭文件对象
us_file.close()
in_file.close()
jp_file.close()
