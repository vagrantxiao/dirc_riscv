#!/bin/bash

for i in {1..10000}
do
  echo ''
  echo ''
  echo 'Current time is :'$(date "+%Y-%m-%d %H:%M:%S")
  squeue
  sleep 10
done
