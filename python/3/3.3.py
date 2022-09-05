import random

num = 5

guess_num = int(input("输入你要猜测的数字："))

if guess_num == num:
    print("第一次就猜中了")
else:
    if guess_num > num:
        print("greater")
    else:
        print("lower")

    guess_num = int(input("再次输入你猜的数字："))

    if guess_num == num:
        print("第二次猜中")
    else:
        if guess_num > num:
            print("greater")
        else:
            print("lower")
        guess_num = int(input("再次输入你猜的数字："))

        if guess_num == num:
            print("第三次猜中")
        else:
            if guess_num > num:
                print("greater")
            else:
                print("lower")
            
