#business information
import time

from django.shortcuts import render
from django.http import HttpResponse
# Create your views here.
from myadmin.models import User
from django.core.paginator import Paginator
from datetime import datetime
from myadmin.models import Business

def index(request,pIndex=1):
    '''view information'''
    bdemo = Business.objects
    '''不表现删除数据'''
    blist = bdemo.filter(status__lt=9)

    mywhere = []

    '''获取并判断搜索条件'''
    kw = request.GET.get('keyword', None)
    if kw:
        blist = blist.filter(name__contains=kw)
        mywhere.append('keyword='+kw)

    '''状态判断'''
    status = request.GET.get('status','')
    if status != '':
        blist = blist.filter(status=status)
        mywhere.append('status='+status)

    #执行分页处理
    pIndex = int(pIndex)
    page = Paginator(blist, 5) # 5条数据为一页分页
    maxpages = page.num_pages # 获取最大页数
    if pIndex > maxpages:
        pIndex = maxpages
    if pIndex <= 1:
        pIndex = 1

    list2 = page.page(pIndex)
    plist = page.page_range
    context = { "businesslist":list2, 'plist':plist, 'pIndex':pIndex, 'maxpages':maxpages,'mywhere':mywhere}
    return render(request,"myadmin/business/index.html",context)

def add(request):
    '''add table information '''
    return render(request, 'myadmin/business/add.html')

def insert(request):
    '''insert information'''
    try:
        # 店铺封面图片的上传处理
        myfile = request.FILES.get("cover_pic", None)
        if not myfile:
            return HttpResponse("没有封面上传文件信息")
        cover_pic = str(time.time()) + "." + myfile.name.split('.').pop()
        destination = open("./static/uploads/business/" + cover_pic, "wb+")
        for chunk in myfile.chunks():  # 分块写入文件
            destination.write(chunk)
        destination.close()

        # 店铺logo图片的上传处理
        myfile = request.FILES.get("banner_pic", None)
        if not myfile:
            return HttpResponse("没有logo上传文件信息")
        banner_pic = str(time.time()) + "." + myfile.name.split('.').pop()
        destination = open("./static/uploads/business/" + banner_pic, "wb+")
        for chunk in myfile.chunks():  # 分块写入文件
            destination.write(chunk)
        destination.close()

        #实例化model、封装、添加
        ob = Business()
        ob.id = request.POST['id']
        ob.name = request.POST['name']
        ob.address = request.POST['address']
        ob.wechat = request.POST['wechat']
        ob.cover_pic = cover_pic
        ob.banner_pic = banner_pic
        ob.status = 1
        ob.create_at = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        ob.update_at = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        ob.save()
        context = {'info':"添加成功!"}
    except Exception as err:
        print(err)
        context = {'info':"添加失败!"}
    return render(request, 'myadmin/../../templates/client/info.html', context)

def edit(request,bid=0):
    ''' delete information '''
    try:
        ob = Business.objects.get(id=bid)
        context = {'business': ob}
        return render(request, 'myadmin/business/edit.html', context)
    except Exception as err:
        print(err)
        context = {'info': "未查询修改信息!"}
        return render(request, 'myadmin/../../templates/client/info.html', context)

def update(request,bid=0):
    '''edit tabel information'''
    try:
        ob = Business.objects.get(id=bid)
        ob.id = request.POST['id']
        ob.name = request.POST['name']
        ob.address = request.POST['address']
        ob.wechat = request.POST['wechat']
        ob.update_at = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        ob.save()
        context = {'info': '修改成功'}
    except Exception as err:
        print(err)
        context = {'info': "修改失败!"}
    return render(request, 'myadmin/../../templates/client/info.html', context)

def delete(request,bid=0):
    '''delete information'''
    try:
        ob = Business.objects.get(id=bid)
        ob.status = 9
        ob.update_at = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        ob.save()
        context = {'info': "删除成功!"}
    except Exception as err:
        print(err)
        context = {'info': "删除失败!"}
    return render(request, 'myadmin/../../templates/client/info.html', context)
