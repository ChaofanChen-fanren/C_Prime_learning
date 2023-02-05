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
from client.views import index, user, cart

urlpatterns = [
    path('', index.index, name='client_index'), #客户端首页
    path('register', index.register, name='client_register'), #客户端登录
    path('doRegister', index.doRegister, name='client_doRegister'), #客户端首页
    path('business', index.business, name='client_business'), #客户端店铺选择页
    path('business/select', index.selectBusiness, name='client_selectBusiness'), #客户端执行店铺选择
    path('orders/add', index.addOrders, name='client_addOrders'), #客户端首页
    path('verify',index.verify, name='client_verify'),

    path('user', user.index, name='client_user_index'),  # 客户中心首页
    path('user/orders', user.orders, name='client_user_orders'),  # 加载客户订单页
    path('user/detail', user.detail, name='client_user_details'),  # 加载订单详情页
    path('user/logout', user.logout, name='client_user_logout'),  # 执行退出

    # 心愿单信息管理路由配置
    path('cart/add', cart.add, name="client_cart_add"),
    path('cart/del', cart.delete, name="client_cart_del"),
    path('cart/clear', cart.clear, name="client_cart_clear"),
    path('cart/change', cart.change, name="client_cart_change"),

    # 订单处理
    path('orders/add', index.addOrders, name="client_addorders"),  # 加载移动端订单页
    path('orders/doadd', index.doAddOrders, name="client_doaddorders"),  # 执行移动端下单操作
]
