#!/usr/bin/env python
# -*- coding: utf-8 -*-
import hashlib
import time
start=time.time()
your_list = "levLEV"
complete_list = []
j=0

for current in xrange(1):
    a = [i for i in your_list]
    for y in xrange(4):
        a = [x+i for i in your_list for x in a]
    complete_list = complete_list+a
while(j<len(complete_list)):
 str="exploit_"+complete_list[j]
 result = hashlib.md5(str.encode()) 
 
 #print(str+":   "+ result.hexdigest())#complete_list[j]
 f = open("output.txt", "a")
 f.write(str+":   "+ result.hexdigest()+"\n")
 f.close()
 if(result.hexdigest()=="0b0d839247b9e564905bb851a4b12b01"): 
   print("OK  " + str)
   break

 j+=1
finish=time.time()

print(finish-start)
# OK  exploit_LeVEl
# 0.0215029716492

