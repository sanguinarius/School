#!/bin/bash

groups $MY_USER | sed -e "s/ /,/g"
