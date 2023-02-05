#category information
import time

from django.shortcuts import render
from django.http import HttpResponse, JsonResponse
# Create your views here.
from myadmin.models import Category
from django.core.paginator import Paginator
from datetime import datetime

def index(request,pIndex=1):
    '''浏览信息'''
    smod = Category.objects
    mywhere=[]
    list = smod.filter(status__lt=9)

    # 获取、判断并封装关keyword键搜索
    kw = request.GET.get("keyword",None)
    if kw:
        # 查询店铺名称中只要含有关键字就可以
        list = list.filter(name__contains=kw)
        mywhere.append("keyword="+kw)

    # 获取、判断并封装状态status搜索条件
    status = request.GET.get('status','')
    if status != '':
        list = list.filter(status=status)
        mywhere.append("status="+status)

    #执行分页处理
    pIndex = int(pIndex)
    page = Paginator(list,10) #以10条每页创建分页对象
    maxpages = page.num_pages #最大页数
    #判断页数是否越界
    if pIndex > maxpages:
        pIndex = maxpages
    if pIndex < 1:
        pIndex = 1
    list2 = page.page(pIndex) #当前页数据
    plist = page.page_range   #页码数列表
    '''
    #遍历信息，并获取对应的商铺名称，以shopname名封装
    for vo in list2:
        sob = Category.objects.get(id=vo.id)
        vo.name = sob.name
    '''
    #封装信息加载模板输出
    context = {"categorylist":list2,'plist':plist,'pIndex':pIndex,'maxpages':maxpages,'mywhere':mywhere}
    return render(request,"myadmin/category/index.html",context)

def loadCategory(request,sid):
    clist = Category.objects.filter(status__lt=9,id=sid).values("id","name")
    #返回QuerySet对象，使用list强转成对应的菜品分类列表信息
    return JsonResponse({'data':list(clist)})

def add(request):
    '''add table information '''
    return render(request, 'myadmin/category/add.html')

def insert(request):
    '''insert information'''
    try:
        #实例化model、封装、添加
        ob = Category()
        ob.id = request.POST['id']
        ob.name = request.POST['name']
        ob.save()
        context = {'info':"添加成功!"}
    except Exception as err:
        print(err)
        context = {'info':"添加失败!"}
    return render(request, 'myadmin/../../templates/client/info.html', context)

def edit(request,cid=0):
    ''' delete information '''
    try:
        ob = Category.objects.get(id=cid)
        context = {'category': ob}
        return render(request, 'myadmin/category/edit.html', context)
    except Exception as err:
        print(err)
        context = {'info': "未查询修改信息!"}
        return render(request, 'myadmin/../../templates/client/info.html', context)

def update(request,cid=0):
    '''edit tabel information'''
    try:
        ob = Category.objects.get(id=cid)
        ob.id = request.POST['id']
        ob.name = request.POST['name']
        ob.status = request.POST['status']
        ob.save()
        context = {'info': '修改成功'}
    except Exception as err:
        print(err)
        context = {'info': "修改失败!"}
    return render(request, 'myadmin/../../templates/client/info.html', context)

def delete(request,cid=0):
    '''delete information'''
    try:
        ob = Category.objects.get(id=cid)
        ob.status = 9
        ob.save()
        context = {'info': "删除成功!"}
    except Exception as err:
        print(err)
        context = {'info': "删除失败!"}
    return render(request, 'myadmin/../../templates/client/info.html', context)
