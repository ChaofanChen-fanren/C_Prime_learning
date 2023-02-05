from django.shortcuts import render
from django.http import HttpResponse
from django.http import JsonResponse

from myadmin.models import Product

# 心愿单信息管理
def add(request):
    '''添加心愿单'''
    cartlist = request.session.get("cartlist",{})
    pid = request.GET.get("pid",None)
    if pid is not None:
        product = Product.objects.get(id=pid).toDict()
        product['num'] = 1

        #判断心愿单中是否已存在要购买的商品
        if pid in cartlist:
            cartlist[pid]['num'] += product['num'] #累加购买量
        else:
            cartlist[pid] = product
        #将心愿单中的商品信息放回到session中
        request.session['cartlist'] = cartlist
    #响应json格式的心愿单信息
    return JsonResponse({'cartlist':cartlist})

def delete(request,pid):
    '''删除心愿单中的商品'''
    cartlist = request.session['cartlist']
    del cartlist[pid]
    request.session['cartlist'] = cartlist
    #响应json格式的心愿单信息
    return JsonResponse({'cartlist':cartlist})

def clear(request):
    '''清空心愿单'''
    request.session['cartlist'] = {}
    #响应json格式的心愿单信息
    return JsonResponse({'cartlist':{}})

def change(request):
    '''心愿单信息修改'''
    cartlist = request.session['cartlist']
    businessid = request.GET.get("pid",0)
    num = int(request.GET.get('num',1))
    if num < 1:
        num = 1
    cartlist[businessid]['num'] = num
    request.session['cartlist'] = cartlist
    #响应json格式的心愿单信息
    return JsonResponse({'cartlist':cartlist})