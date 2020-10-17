#!/bin/bash
set -e
set -o pipefail
openocd -f stm32l4-nucleo.cfg -c 'program test.elf reset exit'
