# 动态柱状图绘制

# 打开文件
from pyecharts.charts import Bar,Timeline
from pyecharts.options import *
from pyecharts.globals import ThemeType


f = open("动态柱状图数据/1960-2019全球GDP数据.csv","r",encoding="GB2312")
lines=f.readlines() #读取全部的行
f.close
lines.pop(0)  #删除第一行

data_dict = {}
for line in lines:
    year = int(line.split(",")[0])
    country = line.split(",")[1]
    gdp = float(line.split(",")[2])
    try:
        data_dict[year].append((country,gdp))
    except KeyError:
        data_dict[year] = []
        data_dict[year].append((country,gdp))

sorted_year_list = sorted(data_dict.keys()) #排序年份
timeline = Timeline({"theme":ThemeType.LIGHT})  #创建时间线，并设置主题

for year in sorted_year_list:
    data_dict[year].sort(key=lambda element:element[1],reverse=True)
    year_data = data_dict[year][0:8]
    countrys = []
    gdps = []
    for country_gdp in year_data:
        countrys.append(country_gdp[0])
        gdps.append(int(country_gdp[1]/100000000))
    bar = Bar()
    countrys.reverse()
    gdps.reverse()

    #设置标题
    bar.set_global_opts(title_opts=TitleOpts(title=f"{year}年全球前8GDP国家"))
    bar.add_xaxis(countrys)
    bar.add_yaxis("GDP(亿)",gdps,label_opts=LabelOpts(position="right")) #y轴数据 标签向右
    bar.reversal_axis() #x.y轴翻转
    timeline.add(bar,str(year))  #时间线添加一个点，和对应bar柱状图

#设置自动播放
timeline.add_schema(
    play_interval=500,
    is_timeline_show=True,
    is_auto_play=True,
    is_loop_play=False
)
timeline.render("全球GDP.html")
