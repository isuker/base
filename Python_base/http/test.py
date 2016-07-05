import urllib.request
import re

fp = urllib.request.urlopen("http://nba.hupu.com/")
f = fp.read()
src = open("./src.txt",'wb')
tar = open("./tar.txt",'wb')

reg_str = '^http.*html$'
html_str = re.match(reg_str,str(f))

tar.write(html_str)
src.write(f)
src.close()
