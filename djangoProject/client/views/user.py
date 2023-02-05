import time
from django.shortcuts import render
from django.http import HttpResponse
# Create your views here.
from django.core.paginator import Paginator
from datetime import datetime
from myadmin.models import Business

def index(request):
    return render(request,'client/user.html')

def orders(request):
    "个人订单浏览"
    return render(request,'client/user_orders.html')

def detail(request):
    "个人中心详情"
    return render(request,'client/user_detail.html')

def logout(request):
    return render(request,'client/register.html')