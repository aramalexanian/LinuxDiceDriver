#include <linux/module.h>
#include <linux/init.h>
#include <linux/usb.h>

/* Meta Inofmration */
MODULE_AUTHOR("Aram Alexanian");
MODULE_DESCRIPTION("A driver for a dice rolling device");

/*
 * This function is called hwen the module is loaded into the kernel
*/
static int __init my_init(void) {
	printk("Hello Ketnel!\n");
	return 0;
}

/*
 * This function is called hwen the module is removed from the kernel
*/
static void __exit my_exit(void){
	printk("Goodbye Ketnel\n");
}

module_init(my_unit);
module_exit(my_exit);
