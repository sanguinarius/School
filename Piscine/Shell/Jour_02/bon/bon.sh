#!/bin/bash

awk -F: '{if ($0 ~ /\ bon:/) print $0}' passwd | wc -l | sed 's/ //g'
