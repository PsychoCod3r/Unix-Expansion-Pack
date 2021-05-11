#!/usr/bin/awk -f

BEGIN { idx = 0 }
$0 !~ /^\r*$/ { array[++idx] = $0 }
END { srand()
      r = int( rand() * idx )
      print array[r] }
