#!/usr/bin/env python3
# simple python script to compile the *.c files both on linux and windows
import argparse
import os
from os import system as sys

parser = argparse.ArgumentParser(description='')
parser.add_argument('-w', '--windows', '--win', dest='windows', action='store_true', help='Toggle windows compilation')
parser.add_argument('-a', '--autorun', dest='autorun', action='store_true', help='Toggle auto running after compilation false')
args = parser.parse_args()

if args.windows == True:
    if not os.path.exists("build/"):
        os.makedirs("build/")
    sys("gcc *.c -o build/corescript")
    if args.autorun == True:
        sys("cd build/ && .\\corescript.exe")
else:
    if not os.path.exists("build/"):
        os.makedirs("build/")
    sys("gcc *.c -o build/corescript")
    if args.autorun == True:
        sys("cd build/ ; ./corescript")