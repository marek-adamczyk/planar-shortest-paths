#!/bin/bash

if [ $# -ne 3 ];
then
  echo "maja byc trzy argumenty"
  exit 1;
fi

numfile="tsts/num"
num=`cat $numfile`
num=$((num+1))
file="tsts/ex$num.in"
echo $1 $2 > $file
echo $3 >> $file
echo $1 $2 $3 | ./createtst >> $file
if [ $? -ne 0 ];
then
  rm $file
  exit 1;
fi;

echo $num > $numfile
