# -*- coding: utf-8 -*-
"""Untitled9.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/14HZO0MTiUNhOJfuyCFujtkVwKJTzUVoa
"""
#The values are distinct thats why the following code works otherwise using linear search is highly inefficient(10**5 x 10**5 loops)
size = int(input())
values = [0]*100001     # list of index-----list[n] stores index of number n------ note n<=100000------ list[0]-list[100000](100001 elements)
index =1
for item in input().split():
  values[int(item)]=index     #storing index of every searchable item in a seprate list which can be directly accesed without need of comparisons.
  index+=1

num = int(input())

count1 = 0
count2 = 0
queries = [int(items) for items in input().split()]
for val in queries:
  count1+=values[val]
  count2+=size-values[val]+1     #directly using the list---the elements are distinct.
print(count1,count2)

