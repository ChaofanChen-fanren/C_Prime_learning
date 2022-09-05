# 格式化表达式

print("1*1 result: %d" % (1*1))
print(f"1*2 result: {1 * 2}")
print("1*1 result: %s" % type("string"))
# print(f"type {type("string")}")


name = "python"
stock_price = 19.99
stock_code = "003032"
stock_price_daily_growth_factor = 1.2
growth_days = 7

print(f"公司: {name},股票代码：{stock_code},当前股价：{stock_price}")
print("每日增长系数：%d,经过%d,股价达到：%.2f" % 
(stock_price_daily_growth_factor,growth_days,stock_price*
(stock_price_daily_growth_factor**growth_days)))
