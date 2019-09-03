#!/usr/bin/python

import sys
import subprocess
import os
import os.path

if __name__ == '__main__':
    if len(sys.argv) != 4:
        print ('usage: %s <type/prefix> <number> <filename>' % (sys.argv[0]))
        sys.exit(-1)
    prefix = sys.argv[1]
    number = sys.argv[2]
    filename = sys.argv[3]

    dirname = '%s%s_%s' % (prefix, number, filename)
    os.makedirs(dirname)

    with open(os.path.join(dirname, 'Makefile'), 'w') as fpw:
        with open(os.path.join('base_templates', 'Makefile'), 'r') as fpr:
            for line in fpr:
                line = line.replace('filename', filename)
                fpw.write(line)

    with open(os.path.join(dirname, '%s.cc' % (filename)), 'w') as fpw:
        with open(os.path.join('base_templates', 'test.cc'), 'r') as fpr:
            for line in fpr:
                fpw.write(line)

    print (dirname)
