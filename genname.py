#!/usr/bin/python
#-*- coding: UTF-8 -*-

import os
import sys

args = sys.argv
argc = len(args)

if argc < 4:
    sys.exit()

number      = args[1]
question    = args[2]
file_type   = args[3]
directory   = None 

if file_type == "cpp":
    directory = 'algorithm/'
elif file_type == 'sql':
    directory = 'sql/'
elif file_type == 'sh':
    directory = 'shell/'
else:
    sys.exit()
    
words = []
lastIndex = -1
str_len = len(question)

for i in range(0, str_len + 1):
    if i == str_len:
        substr = question[lastIndex + 1:i]
        words.append(substr.capitalize())
        break
        
    ch = question[i]
    if ch == '-':
        substr = question[lastIndex + 1:i]
        words.append(substr.capitalize())
        lastIndex = i
    
filename = '{}.{}.{}'.format(number, '_'.join(words), file_type)
filepath = directory + filename

if not os.path.exists(filepath):
    with open(filepath, 'w') as fd:
        fd.close()