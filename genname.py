#!/usr/bin/python
#-*- coding: UTF-8 -*-

import sys
import os

args = sys.argv
argc = len(args)

directory = ''
extension = ''
filename = ''
file_type = args[argc - 1]

if file_type == 'cpp':
    directory = 'algorithm/'
    extension = '.cpp'
elif file_type == 'db':
    directory = 'database/'
    extension = '.sql'
elif file_type == 'sh':
    directory = 'shell/'
    extension = '.sh'

if directory != '':
    filename = args[1]
    for i in range(2, argc - 1):
        word = args[i]
        if word is str:
            filename += word
        else:
            filename += '{}'.format(word)
    
        if i < argc - 1:
            filename += '_'

    filename += extension
    print(filename)

    filepath = directory + filename
    if not os.path.exists(filepath):
        with open(filepath, 'w') as fd:
            fd.close()
