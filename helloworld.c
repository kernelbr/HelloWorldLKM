#ifndef __KERNEL__
#define __KERNEL__ /* We're part of the kernel */
#endif
#ifndef MODULE
#define MODULE     /* Not a permanent part, though. */
#endif

#include <linux/module.h> /* included for all kernel modules       */
#include <linux/kernel.h> /* included for KERN_INFO                */
#include <linux/init.h>   /* included for __init and __exit macros */

/*
 * Related to __init macro (from init.h):
 *
 * These macros are used to mark some functions or
 * initialized data (doesn't apply to uninitialized data)
 * as `initialization' functions. The kernel can take this
 * as hint that the function is used only during the initialization
 * phase and free up used memory resources after
 */
static int __init helloworld_init(void)
{
    printk(KERN_INFO "Hello world!\n");
    return 0;
}

/*
 * Related to __exit macro (from init.h):
 *
 * modpost check for section mismatches during the kernel build.
 * A section mismatch happens when there are references from a
 * code or data section to an init section (both code or data).
 * The init sections are (for most archs) discarded by the kernel
 * when early init has completed so all such references are potential bugs.
 * For exit sections the same issue exists.
 *
 * The following markers are used for the cases where the reference to
 * the *init / *exit section (code or data) is valid and will teach
 * modpost not to issue a warning.
 */
static void __exit helloworld_cleanup(void)
{
    printk(KERN_INFO "Cleaning up module.\n");
}

/*
 * Interesting topic about initcalls:
 * http://elinux.org/Deferred_Initcalls
 */

module_init(helloworld_init);    /* #define module_init(x)  __initcall(x); */
module_exit(helloworld_cleanup); /* #define module_exit(x)  __exitcall(x); */

MODULE_LICENSE("GPL"); /* License to be shown in modinfo */
