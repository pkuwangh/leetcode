#!/usr/bin/python

import sys
import subprocess
import os
import os.path

if __name__ == '__main__':
    if len(sys.argv) != 3:
        print ('usage: %s <number> <filename>' % (sys.argv[0]))
        sys.exit(-1)
    number = sys.argv[1]
    filename = sys.argv[2]

    dirname = 'p%s_%s' % (number, filename)
    os.makedirs(dirname)

    with open(os.path.join(dirname, 'Makefile'), 'w') as fpw:
        with open(os.path.join('templates', 'Makefile'), 'r') as fpr:
            for line in fpr:
                line.replace('filename', filename)
                fpw.write(line)

    with open(os.path.join(dirname, '%s.cc' % (filename)), 'w') as fpw:
        with open(os.path.join('templates', 'test.cc'), 'r') as fpr:
            for line in fpr:
                fpw.write(line)

    print (dirname)
