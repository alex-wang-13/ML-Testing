#!/usr/bin/sh

FILE=main

set -xe

if [ -z "$1" ] ; then
  clang -Wall -Wextra -o $FILE $FILE.c
else
  rm -f $FILE
  ls
fi
