#!/usr/bin/bash
old_dir = pwd;
cd tests;
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 string.tests.c ../mem.c ../string.c -o string.tests.out && ./string.tests.out
