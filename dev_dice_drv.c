#include <linux/module.h>
#include <linux/init.h>
#include <linux/usb.h>

/* Meta Inofmration */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Aram Alexanian");
MODULE_DESCRIPTION("A driver for a dice rolling teensy3.0");

#define VENDOR_ID 0x16c0
#define PRODUCT_ID 0x0483

static struct usb_device_id my_usb_table [] = {
	{USB_DEVICE(VENDOR_ID, PRODUCT_ID)},
	{}
};

MODULE_DEVICE_TABLE(usb, my_usb_table);

static int my_usb_probe(struct usb_interface *intf, const struct usb_device_id *id){
	printk("dev_dice_drv - probe function\n");
	return 0;
}

static void my_usb_disconnect(struct usb_interface *intf){
	printk("dev_dice_drv - exit function\n");
}

static struct usb_driver my_usb_driver = {
	.name = "dev_dice_drv",
	.id_table = my_usb_table,
	.probe = my_usb_probe,
	.disconnect = my_usb_disconnect,
};


/*
 * This function is called hwen the module is loaded into the kernel
*/
static int __init my_init(void) {
	int result;
	printk("dev_dice_drv - init function\n");
	result = usb_register(&my_usb_driver);
	if(result){
		printk("dev_dice_drv - Error during register\n");
		return -result;
	}
	return 0;
}

/*
 * This function is called hwen the module is removed from the kernel
*/
static void __exit my_exit(void){
	printk("dev_dice_drv - exit function\n");
	usb_deregister(&my_usb_driver);
}

module_init(my_init);
module_exit(my_exit);
