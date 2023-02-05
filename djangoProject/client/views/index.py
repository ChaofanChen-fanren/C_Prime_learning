import hashlib
import random

from PIL import Image, ImageDraw, ImageFont
from django.shortcuts import render, redirect
from django.http import HttpResponse
from django.urls import reverse

from myadmin.models import User,Business,Category,Product


# Create your views here.

def index(request):
    "客户端首页"

    businessinfo = request.session.get('businessinfo', None)
    if businessinfo is None:
        return redirect(reverse('client_business'))#重定向到店铺选择
    clist=Category.objects.filter(status=1)
    productlist=dict()
    print(businessinfo['id'])
    for vo in clist:
        plist=Product.objects.filter(business_id=businessinfo['id'],category_id=vo.id, status=1)
        productlist[vo.id] = plist
    context = {'categorylist':clist,'productlist':productlist.items(), 'cid':clist[0]}
    return render(request,"client/index.html", context)

def register(request):
    "客户端登录/注册"
    return render(request,"client/register.html")

def doRegister(request):
    "客户端执行登录/注册"
    try:
        #执行验证码校验
        if request.POST["verify_code"] != request.session['verifycode']:
            context = {'info':'验证码错误'}
            return render(request,'client/register.html', context)
        user = User.objects.get(id=request.POST['id'])
        #是否是用户
        if user.status == 1:
            s = request.POST['pwd'] + user.password_salt
            pwd_hash = hashlib.sha256(s.encode("utf-8")).hexdigest()
            if user.password_hash == pwd_hash:
                print("登陆成功")
                request.session['ClientU'] = user.toDict()
                #重定向到后台管理首页
                return redirect(reverse('client_index'))
            else:
                context = {'info': '密码错误'}
        else:
            context = {'info': '无效登陆账户'}
    except Exception as err:
        print(err)
        context = {'info':'登录id不存在'}
    return render(request,'client/register.html', context)


def business(request):
    "店铺页面"
    context = {'businesslist':Business.objects.filter(status=1)}
    return render(request,"client/business.html",context)

def allProduct(request):
    "客户端首页"
    return render(request,"client/allProduct.html")

def selectBusiness(request):
    "选择店铺"
    bid = request.GET['bid']
    ob = Business.objects.get(id=bid)
    request.session['businessinfo'] = ob.toDict()
    return redirect(reverse('client_index'))

def addOrders(request):
    "客户端下单页面"
    return render(request,"client/addOrders.html")

def verify(request):
    #引入随机函数模块

    #定义变量，用于画面的背景色、宽、高
    #bgcolor = (random.randrange(20, 100), random.randrange(
    #    20, 100),100)
    bgcolor = (242,164,247)
    width = 100
    height = 25
    #创建画面对象
    im = Image.new('RGB', (width, height), bgcolor)
    #创建画笔对象
    draw = ImageDraw.Draw(im)
    #调用画笔的point()函数绘制噪点
    for i in range(0, 100):
        xy = (random.randrange(0, width), random.randrange(0, height))
        fill = (random.randrange(0, 255), 255, random.randrange(0, 255))
        draw.point(xy, fill=fill)
    #定义验证码的备选值
    #str1 = 'ABCD123EFGHIJK456LMNOPQRS789TUVWXYZ0'
    str1 = '0123456789'
    #随机选取4个值作为验证码
    rand_str = ''
    for i in range(0, 4):
        rand_str += str1[random.randrange(0, len(str1))]

    font = ImageFont.truetype('static/SmileySans-Oblique.ttf', 21)
    #font = ImageFont.load_default().font
    #构造字体颜色
    fontcolor = (255, random.randrange(0, 255), random.randrange(0, 255))
    #绘制4个字
    draw.text((5, -3), rand_str[0], font=font, fill=fontcolor)
    draw.text((25, -3), rand_str[1], font=font, fill=fontcolor)
    draw.text((50, -3), rand_str[2], font=font, fill=fontcolor)
    draw.text((75, -3), rand_str[3], font=font, fill=fontcolor)
    #释放画笔
    del draw
    #存入session，用于做进一步验证
    request.session['verifycode'] = rand_str
    """
    python2的为
    # 内存文件操作
    import cStringIO
    buf = cStringIO.StringIO()
    """
    # 内存文件操作-->此方法为python3的
    import io
    buf = io.BytesIO()
    #将图片保存在内存中，文件类型为png
    im.save(buf, 'png')
    #将内存中的图片数据返回给客户端，MIME类型为图片png
    return HttpResponse(buf.getvalue(), 'image/png')


def doAddOrders(request):
    return None