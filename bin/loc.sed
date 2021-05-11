#!/usr/bin/sed -f
# Pipe into wc -l

/^[ 	]*\/\//d
/^\r*\n*$/d
/^[ 	]*\/\*/{
	:start
	N
	/.*\*\/.*/bend
	bstart
	:end
	d
}
