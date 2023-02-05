from django.db import models
from datetime import datetime
# Create your models here.

class User(models.Model):
    id = models.CharField(max_length=50, primary_key=True)
    username = models.CharField(max_length=100)
    nickname = models.CharField(max_length=100)
    password_hash = models.CharField(max_length=100)
    password_salt = models.CharField(max_length=50)
    status = models.IntegerField(default=1)
    create_at = models.DateTimeField(default=datetime.now)
    update_at = models.DateTimeField(default=datetime.now)

    def toDict(self):
        return {'id':self.id,
                'username':self.username,
                'nickname':self.nickname,
                'password_hash':self.password_hash,
                'password_salt':self.password_salt,
                'status':self.status,
                'create_at':self.create_at.strftime('%Y-%m-%d %H:%M:%S'),
                'update_at':self.update_at.strftime('%Y-%m-%d %H:%M:%S')
                }
    class Meta:
        db_table = 'user'



#商户信息模型
class Business(models.Model):
    name = models.CharField(max_length=255)        #商户名称
    cover_pic = models.CharField(max_length=255)#封面图片
    banner_pic = models.CharField(max_length=255)#图标Logo
    address = models.CharField(max_length=255)    #商户地址
    wechat = models.CharField(max_length=255)    #联系微信
    status = models.IntegerField(default=1)        #状态:1正常/2暂停/9删除
    create_at = models.DateTimeField(default=datetime.now)    #创建时间
    update_at = models.DateTimeField(default=datetime.now)    #修改时间

    def toDict(self):
        return {'id':self.id,
                'name':self.name,
                'cover_pic':self.cover_pic,
                'banner_pic':self.banner_pic,
                'address':self.address,
                'wechat':self.wechat,
                'status':self.status,
                'create_at':self.create_at.strftime('%Y-%m-%d %H:%M:%S'),
                'update_at':self.update_at.strftime('%Y-%m-%d %H:%M:%S')
                }

    class Meta:
        db_table = "business"  # 更改表名

class Category(models.Model):
    id = models.IntegerField(primary_key=True)
    name = models.CharField(max_length=50)
    status = models.IntegerField(default=1)
    class Meta:
        db_table = "category"

class Product(models.Model):

    business_id = models.IntegerField()        #店铺id
    category_id = models.IntegerField()    #菜品分类id
    cover_pic = models.CharField(max_length=50)    #菜品图片
    name = models.CharField(max_length=50)#商品名称
    price = models.FloatField()    #商品单价
    status = models.IntegerField(default=1)        #状态:1正常/2停售/9删除
    create_at = models.DateTimeField(default=datetime.now)    #创建时间
    update_at = models.DateTimeField(default=datetime.now)    #修改时间

    def toDict(self):
        return {'id':self.id,
                'shop_id':self.business_id,
                'category_id':self.category_id,
                'cover_pic':self.cover_pic,
                'name':self.name,
                'price':self.price,
                'status':self.status,
                'create_at':self.create_at.strftime('%Y-%m-%d %H:%M:%S'),
                'update_at':self.update_at.strftime('%Y-%m-%d %H:%M:%S')
                }

    class Meta:
        db_table = "product"  # 更改表名