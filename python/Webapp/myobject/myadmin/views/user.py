from django.shortcuts import render
from django.http import HttpResponse
from django.http import JsonResponse
from django.db.models import Q
from django.core.paginator import Paginator
from datetime import datetime
import random

from myadmin.models import User

def index(request,pIndex=1):
    umod = User.objects
    # status >= 9
    ulist = umod.filter(status__lt=9)
    kw_list=[]

    # status != 9
    # ulist = umod.exclude(status=9)



    # 获取并判断搜索条件
    kw = request.GET.get("keyword",None)
    if kw:
        ulist = ulist.filter(Q(username__contains=kw) | Q(nickname__contains=kw))
        kw_list.append('keyword='+kw)

    # 获取、判断并封装状态status搜索条件
    status = request.GET.get('status','')
    if status != '':
        list = list.filter(status=status)
        kw_list.append("status="+status)


    # 执行分页处理
    pIndex = int(pIndex)
    page = Paginator(ulist,5) #以每页5条数据分页
    maxpages = page.num_pages # 获取最大页数
    # 判断当前页是否越界
    if pIndex > maxpages:
        pIndex = maxpages
    if pIndex < 1:
        pIndex = 1
    
    list2 = page.page(pIndex)  # 获取当前页数据
    plist = page.page_range    # 获取页码列表信息
    context = {"userlist":list2,'plist':plist,'pIndex':pIndex,'maxpages':maxpages,'kw_list':kw_list}

    return render(request,"myadmin/user/index.html",context)

def add(request):
    pass

def insert(request):
   pass

def delete(request):
    pass

def edit(request,uid):
   pass

def update(request):
    pass
