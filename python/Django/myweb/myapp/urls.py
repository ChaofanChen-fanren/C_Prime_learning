from django.urls import path

from . import views

urlpatterns = [
    path('', views.index, name='index'),
    path('add/', views.add, name='add'),
    path('list/', views.goodslist, name='list'),
    path('pwd/', views.userpwd, name='pwd'),
]
