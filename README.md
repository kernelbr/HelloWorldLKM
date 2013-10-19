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
