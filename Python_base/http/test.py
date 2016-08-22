import urllib.request
import re

src = open("./src.txt",'wb+')
tar = open("./tar.txt",'w')

fp = urllib.request.urlopen("http://nba.hupu.com/")
f = fp.read()
src.write(f)

html_str = re.findall(r'^',str(f))

print(html_str[1])

src.close()
tar.close()