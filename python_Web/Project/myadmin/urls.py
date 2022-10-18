from django.urls import path
from .views import index,news

urlpatterns = [
    path('', index.index,name = "myadmin_index"),
    
     #新闻爬取后台管理
    path('news/<int:pIndex>', news.index, name="myadmin_news_index"),#浏览信息
    path('news/add', news.add, name="myadmin_news_add"),             #加载添加表单
    path('news/insert', news.insert, name="myadmin_news_insert"),     #执行信息添加
    path('news/del/<int:uid>', news.delete, name="myadmin_news_del"), #删除信息
]
