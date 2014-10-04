#!/bin/bash

awk -F: '{total += $3}END{ print total}' passwd
