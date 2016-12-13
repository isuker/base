#!/usr/bin/python
# -*- coding: UTF-8 -*-

list = []
target_str = ""
temp=0

f = open("p.txt","r+",encoding='utf-8')
str = f.read()
break_point_number = int(input("输入断点数量:"))
print("-----------------------")

for i in range(break_point_number):
    point = int(input())
    list.append(str[temp:point])
    print(list[i])
    target_str = target_str+ list[i] + "\n"
    temp=point
list.append(str[temp:])
target_str+=list[break_point_number]

print(target_str)

ft = open("ii.tit","w",encoding='utf-8')
ft.write(target_str)