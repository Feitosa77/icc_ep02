#!/bin/bash

make

echo "performance" > /sys/devices/system/cpu/cpufreq/policy3/scaling_governo

likwid-perfctr -C 3 -g FLOPS_DP -m ./perfEG < dat/sistemas.dat | less

echo "powersave" > /sys/devices/system/cpu/cpufreq/policy3/scaling_governor
