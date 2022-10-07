from django.shortcuts import render
from django.http import HttpResponse,Http404
from django.urls import reverse
from django.shortcuts import redirect
# Create your views here.
def index(request):
    # print(reverse('find')) # 通过路由名称反向生成url请求地址
    # print(reverse('date',args=("2022",'10'))) # 通过路由名称反向生成url请求地址(带参数)
    # return redirect(reverse('date',args=("2022",'10'))) #执行浏览重定向
    return HttpResponse("http")


def find(request,sid=0,name=""):
    return HttpResponse(f"find sid : {sid} name : {name}")

def date(request,year,month):
    # raise Http404("页面不存在")
    return HttpResponse("%s年%s月"%(year,month))
