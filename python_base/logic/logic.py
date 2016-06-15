#!/usr/bin/python
# -*- coding: UTF-8 -*-

a = 10
i =0
#----------------while
while i < a:
	print("loop......")
	i+=1
else: 
    print("exit")

#---------for and if
list = [1, 2, 3, 4, 5 ]

for x in list:
    print(x)
    if x == 3:
        continue
else:
    print("exit")
#------------------------
for x in range(5):
	print(x)
	if x == 3:
		break
else:
    print("exit")
