from re import T
from traceback import print_tb
from django.shortcuts import render
from django.http import HttpResponse
from .models import Users
# Create your views here.
def index(request):
    object = Users()

    # #添加操作
    # object.id = 1
    # object.name = "张三"
    # object.age  = 12
    # object.phone = "123456"
    # object.save()
    # print(object.id)

    # #删除操作
    # model = Users.objects #获取user的model对象
    # user = model.get(id = 1) #获取id值为1的数据信息
    # user.delete()

    # # 修改操作
    # object = Users.objects.get(id=2)
    # print(object.name)
    # object.name = "王五"
    # object.save()

    # # 查询
    # mod = Users.objects #获取Users模型的Model操作对象
    # user_list = mod.all() #获取所有数据

    # user_list = mod.filter(name='王五') #获取name值为小刘的信息
    # user_list = mod.filter(age__gt=11)  #获取所有age大于11的信息
    # user_list = mod.filter(age__gte=11)  #获取所有age大于等于11的信息
    # user_list = mod.filter(age__lte=11)  #获取所有age大于等于11的信息
    # user_list = mod.order_by("age")[:3] #按age升序排序 | 切片
    # s = ""
    # for u in user_list:
    #     # print("id: " + str(u.id) + " name: " + u.name)
    #     s += "<p>" +"id: " + str(u.id) + " name: " + u.name + "</p>"

    
    return HttpResponse("首页 : " + "<br>" + '<a href="/users">用户信息管理系统</a>')


# 浏览用户信息
def showUsers(request):
    # try:
    user_list = Users.objects.all()
    # for u in user_list:
    #     print(u.id)
    context = {"userlist":user_list}
    return render(request,"myapp/user/showUsers.html",context)
    # except:
    #     return HttpResponse("没有找到用户信息")





# 加载添加用户信息表单
def addUsers(request):
    return render(request,"myapp/user/add.html")



# 执行用户信息添加
def insertUsers(request):
    try:
        ob = Users()
        # 从表单中添加用户信息
        ob.name = request.POST['name']
        ob.age = request.POST['age']
        ob.phone = request.POST['phone']
        ob.save()
        context = {'info':'添加成功！'}
    except:
        context = {'info':'添加失败！'}
    return render(request,"myapp/user/info.html",context)


# 执行用户信息删除
def delUsers(request,uid=0):
    try:
        ob = Users.objects.get(id=uid) #获取要删除的数据
        ob.delete()
        context = {"info":"删除成功！"}
    except:
        context = {"info":"删除不成功！"}
    return render(request,"myapp/user/info.html",context)


# 加载用户信息修改表单
def editUsers(request,uid=0):
    # try:
    ob = Users.objects.get(id=uid)
    context = {'user':ob}
    return render(request,"myapp/user/edit.html",context)
    # except:
    #     context = {'info':'没有找到要修改的信息！'}
    #     return render(request,"myapp/user/info.html",context)



# 执行用户信息修改
def updateUsers(request):
    try:
        ob = Users.objects.get(id= request.POST['id'])
        ob.name = request.POST['name']
        ob.age = request.POST['age']
        ob.phone = request.POST['phone']
        #ob.addtime = datetime.now
        ob.save()
        context = {'info':'修改成功！'}
    except:
        context = {'info':'修改失败！'}
    return render(request,"myapp/user/info.html",context)
