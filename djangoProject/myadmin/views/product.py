#product information
import time

from django.shortcuts import render
from django.http import HttpResponse, JsonResponse
# Create your views here.
from myadmin.models import Category,Product,Business
from django.core.paginator import Paginator
import time, os
from datetime import datetime

def index(request,pIndex=1):
    '''浏览信息'''
    smod = Product.objects
    mywhere=[]
    prlist = smod.filter(status__lt=9)

    # 获取、判断并封装关keyword键搜索
    kw = request.GET.get("keyword", None)
    if kw:
        # 查询店铺名称中只要含有关键字就可以
        prlist = prlist.filter(name__contains=kw)
        mywhere.append("keyword="+kw)
    #类别检索
    cid = request.GET.get('category_id',None)
    if cid:
        prlist = prlist.filter(category_id=cid)
        mywhere.append("category_id"+cid)
    # 获取、判断并封装状态status搜索条件
    status = request.GET.get('status','')
    if status != '':
        prlist = prlist.filter(status=status)
        mywhere.append("status="+status)

    #执行分页处理
    pIndex = int(pIndex)
    page = Paginator(prlist,10) #以10条每页创建分页对象
    maxpages = page.num_pages #最大页数
    #判断页数是否越界
    if pIndex > maxpages:
        pIndex = maxpages
    if pIndex < 1:
        pIndex = 1
    list2 = page.page(pIndex) #当前页数据
    plist = page.page_range   #页码数列表

    for vo in list2:
        sob = Business.objects.get(id=vo.business_id)
        vo.business_name = sob.name
        cob = Category.objects.get(id=vo.category_id)
        vo.category_name = cob.name
    #封装信息加载模板输出
    context = {"productlist":list2,'plist':plist,'pIndex':pIndex,'maxpages':maxpages,'mywhere':mywhere}
    return render(request,"myadmin/product/index.html",context)

def loadCategory(request,sid):
    clist = Category.objects.filter(status__lt=9,id=sid).values("id","name")
    #返回QuerySet对象，使用list强转成对应的菜品分类列表信息
    return JsonResponse({'data':list(clist)})

def add(request):
    '''add table information '''
    blist = Business.objects.values('id','name')
    clist = Category.objects.values('id','name')
    context = {'businesslist':blist, 'categorylist':clist}
    return render(request, 'myadmin/product/add.html', context)

def insert(request):
    '''insert information'''
    try:
        # 店铺封面图片的上传处理
        myfile = request.FILES.get("cover_pic", None)
        if not myfile:
            return HttpResponse("没有封面上传文件信息")
        cover_pic = myfile.name
        destination = open("./static/uploads/product/" + cover_pic, "wb+")
        for chunk in myfile.chunks():  # 分块写入文件
            destination.write(chunk)
        destination.close()


        #实例化model、封装、添加
        ob = Product()
        ob.name = request.POST['name']
        ob.category_id = request.POST['category_id']
        ob.business_id = request.POST['business_id']
        ob.price = request.POST['price']
        ob.cover_pic = cover_pic
        ob.save()
        context = {'info':"添加成功!"}
    except Exception as err:
        print(err)
        context = {'info':"添加失败!"}
    return render(request, 'myadmin/../../templates/client/info.html', context)

def edit(request,pid=0):
    ''' delete information '''
    try:
        ob = Product.objects.get(id=pid)
        blist = Business.objects.values('id', 'name')
        clist = Category.objects.values('id', 'name')
        context = {'product': ob,'businesslist':blist, 'categorylist':clist}
        return render(request, 'myadmin/product/edit.html', context)
    except Exception as err:
        print(err)
        context = {'info': "未查询修改信息!"}
        return render(request, 'myadmin/../../templates/client/info.html', context)

def update(request,pid):
    '''执行编辑信息'''
    try:
        #获取原图片名
        oldpicname = request.POST['oldpicname']
        #判断是否有文件上传
        myfile = request.FILES.get("cover_pic",None)
        if not myfile:
            cover_pic = oldpicname
        else:
          #图片的上传处理
          cover_pic = myfile.name
          destination = open("./static/uploads/product/"+cover_pic,"wb+")
          for chunk in myfile.chunks():      # 分块写入文件
              destination.write(chunk)
          destination.close()

        ob = Product.objects.get(id=pid)
        ob.business_id = request.POST['business_id']
        ob.category_id = request.POST['category_id']
        ob.name = request.POST['name']
        ob.price = request.POST['price']
        ob.cover_pic = cover_pic
        ob.status = request.POST['status']
        ob.update_at = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        ob.save()
        context={"info":"修改成功！"}
        # 判断删除老图片
        if myfile:
            os.remove("./static/uploads/product/"+oldpicname)
    except Exception as err:
        print(err)
        context={"info":"修改失败"}
        #判断删除刚刚上传的图片
        if myfile:
            os.remove("./static/uploads/product/"+cover_pic)

    return render(request, "myadmin/../../templates/client/info.html", context)

def delete(request,pid=0):
    '''delete information'''
    try:
        ob = Product.objects.get(id=pid)
        ob.status = 9
        ob.save()
        context = {'info': "删除成功!"}
    except Exception as err:
        print(err)
        context = {'info': "删除失败!"}
    return render(request, 'myadmin/../../templates/client/info.html', context)
