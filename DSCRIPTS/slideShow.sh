#!/bin/bash

while true; do
  for f in ~/DSYS/DPICTURES/sinOpp/*; do
    feh -z --bg-scale --no-fehbg "$f"
    sleep 2
  done
done