import webbrowser
import os

x = input()

#######################webbrowser  usage
#google
webbrowser.open_new_tab('https://www.google.com.hk/webhp?sourceid=chrome-instant&rlz=1C1CHWL_zh-CNCN694CN694&ion=1&espv=2&ie=UTF-8#q='+x)
#baidu
webbrowser.open_new_tab('https://www.baidu.com/s?wd='+x+'&ie=UTF-8')
#biying
webbrowser.open_new_tab('http://cn.bing.com/search?q='+x+'&go=%E6%8F%90%E4%BA%A4&qs=n&form=QBLH&pq=sd&sc=8-2&sp=-1&sk=&cvid=F901CD5400C34E7A91640406D339F0F8')
#wiki
webbrowser.open_new_tab('https://zh.wikipedia.org/wiki/'+x)

#######################os  usage
os.system('"D:\software\\360se6\Application\\360se.exe" http:\\www.baidu.com')
