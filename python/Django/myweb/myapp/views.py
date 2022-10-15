from traceback import print_tb
from django.shortcuts import render
from django.http import HttpResponse
from myapp.models import Stu
# Create your views here.

logo='welcome to itcast'
def index(request):
    return render(request, 'myapp/index.html', {'logo': logo})

def add(request):
    lists = Stu.objects.all()
    for stu in lists:
        print(stu)
    
    print(Stu.objects.get(id=6))
    return HttpResponse("ADD.....")

def goodslist(request):
    return render(request, 'myapp/goodslist.html', {'logo': logo})

def userpwd(request):
    return render(request, 'myapp/userpwd.html', {'logo': logo})
