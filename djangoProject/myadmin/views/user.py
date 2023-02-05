#user information

from django.shortcuts import render
from django.http import HttpResponse, JsonResponse
# Create your views here.
from myadmin.models import User
from django.core.paginator import Paginator
from django.db.models import Q
from datetime import datetime
import hashlib
import random


def index(request,pIndex=1):
    '''view information'''
    udemo = User.objects
    '''不表现删除数据'''
    ulist = udemo.filter(status__lt=9)

    mywhere = []

    '''获取并判断搜索条件'''
    kw = request.GET.get('keyword', None)
    if kw:
        ulist = ulist.filter(Q(username__contains=kw) | Q(id__contains=kw)) #模糊查询
        mywhere.append('keyword='+kw)

    '''状态判断'''
    status = request.GET.get('status','')
    if status != '':
        ulist = ulist.filter(status=status)
        mywhere.append('status='+status)


    #执行分页处理
    pIndex = int(pIndex)
    page = Paginator(ulist, 5) # 5条数据为一页分页
    maxpages = page.num_pages # 获取最大页数
    if pIndex > maxpages:
        pIndex = maxpages
    if pIndex <= 1:
        pIndex = 1

    list2 = page.page(pIndex)
    plist = page.page_range
    context = { "userlist":list2, 'plist':plist, 'pIndex':pIndex, 'maxpages':maxpages,'mywhere':mywhere}
    return render(request,"myadmin/user/index.html",context)

def add(request):
    '''add table information '''
    return render(request, 'myadmin/user/add.html')

def insert(request):
    '''insert information'''
    try:
        ob = User()
        ob.id = request.POST['id']
        ob.username = request.POST['username']
        ob.nickname = request.POST['nickname']

        #密码加盐、hash处理
        n = random.randint(100000, 999999)
        s = request.POST['password'] + str(n)
        ob.password_hash = hashlib.sha256(s.encode("utf-8")).hexdigest()
        ob.password_salt = n
        ob.status = 1
        ob.create_at = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        ob.update_at = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        ob.save()
        context = {'info':"添加成功!"}
    except Exception as err:
        print(err)
        context = {'info':"添加失败!"}
    return render(request, 'myadmin/../../templates/client/info.html', context)

def edit(request,uid):
    ''' delete information '''
    try:
        ob = User.objects.get(id=uid)
        context = {'user': ob}
        return render(request, 'myadmin/user/edit.html', context)
    except Exception as err:
        print(err)
        context = {'info': "未查询修改信息!"}
        return render(request, 'myadmin/../../templates/client/info.html', context)

def update(request,uid):
    '''edit tabel information'''
    try:
        ob = User.objects.get(id=uid)
        ob.username = request.POST['username']
        ob.nickname = request.POST['nickname']
        ob.status = request.POST['status']
        ob.update_at = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        ob.save()
        context = {'info': '修改成功'}
    except Exception as err:
        print(err)
        context = {'info': "修改失败!"}
    return render(request, 'myadmin/../../templates/client/info.html', context)

def delete(request,uid=0):
    '''delete information'''
    try:
        ob = User.objects.get(id=uid)
        ob.status = 9
        ob.update_at = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        ob.save()
        context = {'info': "删除成功!"}
    except Exception as err:
        print(err)
        context = {'info': "删除失败!"}
    return render(request, 'myadmin/../../templates/client/info.html', context)
