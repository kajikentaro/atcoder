#!/bin/sh
SCRIPT_DIR=$(cd $(dirname $0); pwd)
if [ "$1" = "" ] ; then
	echo "No arguments"
else
	cat $SCRIPT_DIR/ac_template.cpp >> $1
fi