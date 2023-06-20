#!/bin/sh
g++ $1.cpp -o $1
./$1 < case.txt