from django.db import models

# Create your models here.
class News(models.Model):
    #id = models.AutoField(primary_key=True) #主键可省略不写
    title = models.CharField(max_length=255)  # 新闻标题
    date  = models.DateField(auto_now_add=True) # 新闻发表日期
    urls = models.CharField(max_length=255) # 新闻链接地址
    school = models.CharField(max_length=255) #新闻发布机构
    content = models.TextField() #新闻的文本内容
    
    def toDict(self):
        return {'id':self.id,'title':self.title,'date':self.date.strftime('%Y-%m-%d'),'urls':self.urls,'school':self.school,'content':self.content}
    
    class Meta:
        db_table = 'news_table'
