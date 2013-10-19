HelloWorldLKM
=============

A simple example of Linux Kernel Module

```
$ make
# insmod helloworld.ko
# rmmod helloworld.ko
```

You will see on dmesg something like:

```
[ 6519.343791] Hello world!
[ 6525.014934] Cleaning up module.
```

Interesting related topics:

* http://elinux.org/Deferred_Initcalls
* http://www.tldp.org/LDP/lkmpg/2.4/html/x354.html

