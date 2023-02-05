from django.shortcuts import redirect
from django.urls import reverse
import re

class ShopMiddleware:
    def __init__(self, get_response):
        self.get_response = get_response

    def __call__(self, request):
        path = request.path
        print('url:', path)
        #定义后台开放url列表
        urllist = ['/myadmin/login'
            ,'/myadmin/logout'
            ,'/myadmin/dologin'
            ,'/myadmin/verify']
        #判断管理后台是否登录
        #判断当前顶球url地址是否是以/myadmin，and不在urllist中
        if re.match(r'^/myadmin',path) and (path not in urllist):
            #判断是否登录(key名为AdminU是否在session中)
            if 'AdminU' not in request.session:
                #从定向到login
                return redirect(reverse('myadmin_login'))

        urllist = ['/client/register'
            , '/client/logout'
            , '/client/doRegister'
            , '/client/verify']
        # 判断管理后台是否登录
        # 判断当前顶球url地址是否是以/client，and不在urllist中
        if re.match(r'^/client', path) and (path not in urllist):
            # 判断是否登录(key名为AdminU是否在session中)
            if 'ClientU' not in request.session:
                # 从定向到login
                return redirect(reverse('client_register'))

        response = self.get_response(request)

        return response