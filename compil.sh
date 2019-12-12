#!/bin/sh
((./bin/lcc < $1.c) > $1.ll) 2> $1.txt
