from django.urls import path,re_path
from . import views
urlpatterns = [
    path('',views.index,name="index"),
    path('getcookie',views.getcookie,name="getcookie"),
    path('find/',views.find,name="find"),
    path('find/<int:sid>',views.find,name="find1"),
    path('find/<int:sid>/<str:name>',views.find,name="find2"),
    #正则匹配
    re_path(r'^date/(?P<year>[0-9]{4})/(?P<month>[0-9]{2})/$',views.date,name="date"),
    path('verifycode/', views.verifycode,name='verifycode'),
]
