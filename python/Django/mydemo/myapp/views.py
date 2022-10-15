from urllib import response
from django.shortcuts import render
from django.http import HttpResponse,Http404,HttpResponseNotFound
from django.urls import reverse
from django.shortcuts import redirect
import datetime
# Create your views here.
def index(request):
    # print(reverse('find')) # 通过路由名称反向生成url请求地址
    # print(reverse('date',args=("2022",'10'))) # 通过路由名称反向生成url请求地址(带参数)
    # return redirect(reverse('date',args=("2022",'10'))) #执行浏览重定向

    response = HttpResponse('cookie的设置' + """<img id='verifycode' src="/verifycode" alt="CheckCode"/>""")
    response.set_cookie('num','0')
    return response
    
    now = datetime.datetime.now()
    html = "<html><body>It is now %s.</body></html>" % now
    return HttpResponse(html)
    # return HttpResponse('<script>alert("添加成功");location.href = "/date/2022/10"; </script>')
    # raise Http404("Poll does not exist")
    # return HttpResponse(status=403)
    # return HttpResponseNotFound('<h1>Page not found</h1>')
    # context = {'info':'数据添加成功','u':'/userindex'}
    # return render(request,'info.html',context)

def getcookie(request):
    # a = request.COOKIES.get('a',None)
    # if a:
    #     return HttpResponse("Http的获取:" + a)
    # else:
    #     return HttpResponse("cookie不存在")
    m = request.COOKIES.get('num',None)
    if m:
        m = int(m) + 1
    else:
        m = 1
    response = HttpResponse("cookie counter:"+ str(m))
    response.set_cookie('num',m)
    return response

def find(request,sid=0,name=""):
    return HttpResponse(f"find sid : {sid} name : {name}")

def date(request,year,month):
    # raise Http404("页面不存在")
    return HttpResponse("%s年%s月"%(year,month))


def verifycode(request):
    #引入绘图模块
    from PIL import Image, ImageDraw, ImageFont
    #引入随机函数模块
    import random
    #定义变量，用于画面的背景色、宽、高
    bgcolor = (random.randrange(20, 100), random.randrange(20, 100), 255)
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
    str1 = 'ABCD123EFGHIJK456LMNOPQRS789TUVWXYZ0'
    #随机选取4个值作为验证码
    rand_str = ''
    for i in range(0, 4):
        rand_str += str1[random.randrange(0, len(str1))]
    #构造字体对象
    font = ImageFont.truetype('static/msyh.ttf', 23)
    #font = ImageFont.load_default().font
    #构造字体颜色
    fontcolor = (255, random.randrange(0, 255), random.randrange(0, 255))
    #绘制4个字
    draw.text((5, 2), rand_str[0], font=font, fill=fontcolor)
    draw.text((25, 2), rand_str[1], font=font, fill=fontcolor)
    draw.text((50, 2), rand_str[2], font=font, fill=fontcolor)
    draw.text((75, 2), rand_str[3], font=font, fill=fontcolor)
    #释放画笔
    del draw
    #存入session，用于做进一步验证
    request.session['verifycode'] = rand_str
    # 内存文件操作-->此方法为python3的
    import io
    buf = io.BytesIO()
    #将图片保存在内存中，文件类型为png
    im.save(buf, 'png')
    #将内存中的图片数据返回给客户端，MIME类型为图片png
    return HttpResponse(buf.getvalue(), 'image/png')
