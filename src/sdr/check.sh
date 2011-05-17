#!/bin/bash

beg=0
end=`cat tsts/num`
if [ "$1" != "" ];
then
  beg=$1
  end=$1
fi;

for i in `seq $beg $end`; do
  echo "test nr $i (ex$i.in)"
  a=`time ./sdr < "tsts/ex$i.in"`
  echo "sdr:  $a"
  b=`time ./corr < "tsts/ex$i.in"`
  echo "corr: $b"
  if [ $a -ne $b ];
  then
    echo BLAD
    exit 1;
  fi;
  echo ++++++++++++++
done
