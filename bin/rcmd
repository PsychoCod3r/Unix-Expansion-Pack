#!/usr/bin/env bash
#
# Execute a command on every file
# in a hierarchy
#
# Directions:
# Go to root of hierarchy.
# Enter:
# rcmd <cmd> <args minus filename>
# (filename inserted at the end)

function usage(){
cat << END
Usage:
At root of hierarchy:
rcmd [-d|-f] (([-x] -s <script>) | <cmd>)
-d: Execute command inside each directory traversed
-f: Execute command on every file in hierarchy
-s: Execute commands given in <script>
-x: Run <script> as an executable file
Use either <cmd> or <script>, not both.
---
If -f is used:
<cmd> or <script> must take a single argument;
this argument is the name of the file operated on.
Argument should be omitted from the command string;
it will be inserted by the script.
---
Note: Type options in the order given in this help.
I've gotten undefined behavior from using different
orders and I can't figure out why.
END
}

script=""	# Script to use, if applicable
ftype="dir"	# Operate on individual files or entire directories?
exe="false"	# Run script as executable?

SAVEDPWD="$OLDPWD"
# Allows user to cd back to the previous directory after running
# the script

while getopts ":dfxs:" opt
do
	case $opt in
		d ) ftype="dir";;
		f ) ftype="file";;
		x ) exe="true";;
		s ) script="$OPTARG";;
		* ) usage; exit 1;;
	esac
done

shift $(($OPTIND-1))

export cmd="$@"

# Get absolute filepath for script:
if [[ "$script" != "" ]]
then
	pushd . 1>/dev/null
	cd $(dirname "$script")
	scriptdir="$PWD"
	scriptbase=$(basename "$script")
	popd 1>/dev/null
fi

# Main procedure for traversing directory tree:
function proc(){
	if [[ $ftype == "file" ]]
	# Execute command on individual files
	then
		for f in *
		do
			if [[ -d "$f" ]]
			then
				cd "$f"
				proc
				cd ..
			else
				if [[ $script == "" ]]
				# Execute command string
				then
					eval "$cmd $f"
				elif [[ $exe == "true" ]]
				# Run executable script
				then
					eval "$scriptdir/$scriptbase $f"
				elif [[ $exe == "false" ]]
				# Run non-executable script
				then
					source "$scriptdir/$scriptbase" "$f"
				fi
			fi
		done
	elif [[ $ftype == "dir" ]]
	# Execute command on entire directories
	then
		for f in *
		do
			if [[ -d "$f" ]]
			then
				cd "$f"
				proc
				cd ..
			fi
		done
		if [[ $script == "" ]]
		# Execute command string
		then
			eval "$cmd"
		elif [[ $exe == "true" ]]
		# Run executable script
		then
			eval "$scriptdir/$scriptbase"
		elif [[ $exe == "false" ]]
		# Run non-executable script
		then
			source "$scriptdir/$scriptbase"
		fi
	fi
}

proc

# Cleanup:
OLDPWD="$SAVEDPWD"
unset SAVEDPWD usage ftype script exe cmd scriptdir scriptbase proc f
