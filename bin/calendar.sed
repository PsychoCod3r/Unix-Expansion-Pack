#!/usr/bin/sed -f

/^#/d
/^[0-9][0-9]*\/[0-9][0-9]* /s/ /\	/
/^[A-Z][a-z]* [0-9][0-9]* /{
	s/ /\	/
	s/ /\	/
	s/\	/ /
}
