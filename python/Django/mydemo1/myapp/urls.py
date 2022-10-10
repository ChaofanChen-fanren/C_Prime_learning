from django.urls import path,include
from . import views


urlpatterns = [
    path('',views.index,name="index"),
    # 配置users信息操作路由
    path('users',views.showUsers,name="showUsers"),
    path('users/add',views.addUsers,name="addUsers"),
    path('users/insert',views.insertUsers,name="insertUsers"),
    path('users/delete/<int:uid>',views.delUsers,name="delUsers"),
    path('users/edit/<int:uid>',views.editUsers,name="editUsers"),
    path('users/update',views.updateUsers,name="updateUsers"),
]
