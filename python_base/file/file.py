#!/usr/bin/python
# -*- coding: UTF-8 -*-

'''
multiline comment
'''

f = open("p.txt","r+")
print(f.tell())
#position of file
f.seek(2,0)
print(f.tell())
