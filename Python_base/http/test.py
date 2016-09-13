import urllib.request
import re

def  delete_double_quotation_marks(data):
	size = len(data)
	result =data[1:size-1]
	return result

src = open("./src.txt",'wb+')
tar = open("./tar.txt",'w')

fp = urllib.request.urlopen("http://nba.hupu.com/")
f = fp.read()
src.write(f)

html_str = re.findall(r'"http\S*"',str(f))

for i in html_str:
	tar.write(i)
	tar.write("\n")

x = delete_double_quotation_marks(html_str[1])

src.close()
tar.close()