Calculators to demonstrate dynamic linking in pure C
=======

This is an RPN calculator with pluggable modules, designed to
demonstrate a crude, simplistic form of dynamic linking. The
`addplug`/`divplug`/`multplug`/`subtplug` programs generate the actual
plug in modules, while `plugcalc` uses them. `plugcalc.cfg` configures
what modules plugcalc will know about.

It works by grabbing a function pointer, and reading in a big block of
memory after the function pointer, and writing that to a file as the
plug-in module. The program that uses the module reads it into memory,
and makes a function pointer point to it. 

I tested this on a half-dozen different platforms, and it worked on
all. The disadvantage of this approach is that on most platforms, you
need to explicitly pass a data structure to the modules full of any
external functions they're gonna use.

I wrote this back in high school. 