import urllib.request
import re

src = open("./src.txt",'wb+')
tar = open("./tar.txt",'w')

fp = urllib.request.urlopen("http://nba.hupu.com/")
f = fp.read()
src.write(f)

html_str = re.search(r'http.*?html',str(f))

##print(type(html_str.group()))
print(type(f))

src.close()
tar.close()