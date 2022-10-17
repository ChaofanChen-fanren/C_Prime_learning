from django.shortcuts import render
from myadmin.models import News
from django.db.models import Q
from django.core.paginator import Paginator
def index(request,pIndex=1):
    '''浏览信息'''
    umod = News.objects
    list = umod.all()
    keyWord_list=[]


    # 获取、判断并封装关keyword键搜索
    kw = request.GET.get("keyword",None)
    if kw:
        # 查询员工账号或昵称中只要含有关键字的都可以
        list = list.filter(Q(title__contains=kw) | Q(content__contains=kw) | Q(school__contains=kw))
        keyWord_list.append(kw)

    #执行分页处理
    pIndex = int(pIndex)
    page = Paginator(list,10) #以5条每页创建分页对象
    maxpages = page.num_pages #最大页数

    #判断页数是否越界
    if pIndex > maxpages:
        pIndex = maxpages
    if pIndex < 1:
        pIndex = 1
    
    #当前页数据
    list2 = page.page(pIndex) 
    # 将当前数据的新闻文本的字符串截取前30个字符显示
    for l in list2:
        if kw:
            kw_index = l.content.find(kw)
            if kw_index != -1:
                start = max(0,kw_index-15)
                l.content = l.content[start:start+30]
            else:
                l.content = l.content[:30]
        else:
            l.content = l.content[:30]
    
    #页码数列表
    first_page = max(1,pIndex-3);
    plist = range(first_page,first_page + 6) #显示包含此页的页列表
    #封装信息加载模板输出
    context = {"newslist":list2,'plist':plist,'pIndex':pIndex,'kw_list':keyWord_list}
    return render(request,"myadmin/news/index.html",context)

def add(request):
    pass

def insert(request):
    pass

def delete(request,uid):
    pass

def edit(request,uid):
    pass

def update(request,uid):
    pass
