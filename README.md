# Unix Expansion Pack
Scripts implementing additional Unix commands and hacks

----

## Included commands:

`calendar-cpp`: Adds full CPP capabilities to the BSD `calendar` program. You can alias the `calendar` command to this script, although the options may be somewhat different.

`factorial`: Arbitrary precision factorial calculator - takes a positive integer of any size as its argument and computes the factorial. (Anything other than a positive integer causes an error.)

`loc`: Lines Of Code calculator - takes a C file as its parameter and computes how many non-comment, non-whitespace lines are in that file.

`radix`: Converts a number from one base to another. Can use any base.

`randline`: Selects a random line from a file, or one random line each from a list of files. Great for people like me who suffer from choice paralysis. I figured someone else might find it useful too.

`rchmod`: Works just like the `chmod` command except it changes permissions for all files in a directory tree, including the root of that tree. This is most useful for adding permissions to files hosted on a server so you can access them remotely.

----

## Dependencies:

For `calendar-cpp` to work, the `calendar` program must be installed. `loc` is dependent on `sed` while `factorial` and `radix` are dependent on `dc`, but these two programs come preinstalled on almost every Unix/Linux system, so it shouldn't be a problem.

----

## Installation:

To install, set execute permission for all scripts and then copy them to /usr/local/bin.

    $ cd bin
    $ chmod a+x *
    $ sudo cp * /usr/local/bin

Or just run the install script:

    $ source install

----

## Notes:

Certain scripting features used by these scripts don't work on modern versions of Cygwin. I can get them to work on actual Unix/Linux systems and on old versions of Cygwin, but the current version doesn't run these scripts correctly for some reason. Features that no longer work on Cygwin include the `getopts` shell command and the branching commands in sed. So if you're a Unix person who uses Windows for convenience, consider using actual Unix/Linux to run these scripts. Sorry for the inconvenience.
