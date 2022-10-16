from django.shortcuts import render
from django.http import HttpResponse

# Create your views here.
def index(request):
    context = {"data":{"data":[5, 20, 36, 10, 10, 20],"name":['校庆办', '党委组织部', '党委宣传部', '计算机学院', '社会资源处', '经管学院']}}
    return render(request,'web/index.html',context)
