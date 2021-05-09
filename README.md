# Unix-Expansion-Pack
Scripts implementing additional Unix commands and hacks

----

## Included commands:

`calendar-cpp`: Adds full CPP capabilities to the BSD `calendar` program so you can use macros with arguments and other features not normally accessible in `calendar`. You can alias the `calendar` command to this script, although the options may be somewhat different.

`factorial`: Arbitrary precision factorial calculator - takes a positive integer of any size as its argument and computes the factorial. Just be careful not to give it anything other than a positive integer or bad stuff might happen (I haven't tested this part, so IDK).

----

To install, set execute permission for all scripts and then copy them to /usr/local/bin.

    $ cd bin
    $ chmod a+x *
    $ sudo cp * /usr/local/bin
