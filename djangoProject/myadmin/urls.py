"""djangoProject URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/4.1/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path, include
from myadmin.views import index, category, product
from myadmin.views import user
from myadmin.views import business
urlpatterns = [
    path('', index.index, name='myadmin_index'), #后台首页

    #后台管理员登录、退出路由
    path('login',index.login,name='myadmin_login'),
    path('dologin',index.dologin,name='myadmin_dologin'),
    path('logout',index.logout,name='myadmin_logout'),
    path('verify',index.verify,name='myadmin_verify'),
    #员工信息管理路由
    path('user/<int:pIndex>', user.index, name='myadmin_user_index'),#浏览
    path('user/add', user.add, name='myadmin_user_add'),#添加表单
    path('user/insert', user.insert, name='myadmin_user_insert'),#执行添加
    path('user/del/<uid>', user.delete, name='myadmin_user_delete'),#执行删除
    path('user/edit/<uid>', user.edit, name='myadmin_user_edit'),#加载编辑表单
    path('user/update/<uid>', user.update, name='myadmin_user_update'),#执行编辑

    #商户信息管理路由
    path('business/<int:pIndex>', business.index, name="myadmin_business_index"),
    path('business/add', business.add, name="myadmin_business_add"),
    path('business/insert', business.insert, name="myadmin_business_insert"),
    path('business/del/<int:bid>', business.delete, name="myadmin_business_delete"),
    path('business/edit/<int:bid>', business.edit, name="myadmin_business_edit"),
    path('business/update/<int:bid>', business.update, name="myadmin_business_update"),

    #分类信息管理
    path('category/<int:pIndex>', category.index, name="myadmin_category_index"),
    path('category/load/<int:sid>', category.loadCategory, name="myadmin_category_load"),
    path('category/add', category.add, name="myadmin_category_add"),
    path('category/insert', category.insert, name="myadmin_category_insert"),
    path('category/del/<int:cid>', category.delete, name="myadmin_category_del"),
    path('category/edit/<int:cid>', category.edit, name="myadmin_category_edit"),
    path('category/update/<int:cid>', category.update, name="myadmin_category_update"),

    #商品分类
    path('product/<int:pIndex>', product.index, name="myadmin_product_index"),
    path('product/add', product.add, name="myadmin_product_add"),
    path('product/insert', product.insert, name="myadmin_product_insert"),
    path('product/del/<int:pid>', product.delete, name="myadmin_product_del"),
    path('product/edit/<int:pid>', product.edit, name="myadmin_product_edit"),
    path('product/update/<int:pid>', product.update, name="myadmin_product_update"),
]
