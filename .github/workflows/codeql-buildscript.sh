#!/usr/bin/env bash

# https://github.com/achimdoebler/UGUI/issues/23
sed -i 's/#include "system.h"/#include <stdint.h>/' ugui.h
gcc -c ugui.c
