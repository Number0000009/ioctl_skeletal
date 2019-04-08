#include <linux/module.h>
#include <linux/miscdevice.h>
#include <linux/version.h>
#include <linux/fs.h>
#include <linux/types.h>
#include <linux/debugfs.h>
#include <linux/seq_file.h>


#define IOC_API_VERSION 12

#define IOCIO 0xAF
#define IOC_CALL1N	_IO(IOCIO,	0x00)
#define IOC_CALL2N	_IO(IOCIO,	0x01)
#define IOC_CALL3N	_IO(IOCIO,	0x02)
#define IOC_CALL1R	_IOR(IOCIO,	0x03,	long)
#define IOC_CALL2R	_IOR(IOCIO,	0x04,	long)
#define IOC_CALL3R	_IOR(IOCIO,	0x05,	long)
#define IOC_CALL1W	_IOW(IOCIO,	0x06,	long)
#define IOC_CALL2W	_IOW(IOCIO,	0x07,	long)
#define IOC_CALL3W	_IOW(IOCIO,	0x08,	long)
#define IOC_CALL1RW	_IOWR(IOCIO,	0x09,	long)
#define IOC_CALL2RW	_IOWR(IOCIO,	0x0a,	long)
#define IOC_CALL3RW	_IOWR(IOCIO,	0x0b,	long)

static struct device *dev;

static int skeletal_open(struct inode *inode, struct file *filep)
{
	pr_info("%s\n", __func__);
	return 0;
}

static int skeletal_release(struct inode *inode, struct file *filep)
{
	pr_info("%s\n", __func__);
	return 0;
}

static long skeletal_ioctl(struct file *filep, unsigned int cmd, unsigned long arg)
{
	long ret = -EINVAL;

	switch (cmd) {
		case IOC_CALL1N:
			pr_info("IOC_CALL1N\n");
			ret = 0;
			break;

		case IOC_CALL2N:
			pr_info("IOC_CALL2N\n");
			ret = 0;
			break;

		case IOC_CALL3N:
			pr_info("IOC_CALL3N\n");
			ret = 0;
			break;

		case IOC_CALL1R:
			pr_info("IOC_CALL1R\n");
			ret = 0;
			break;

		case IOC_CALL2R:
			pr_info("IOC_CALL2R\n");
			ret = 0;
			break;

		case IOC_CALL3R:
			pr_info("IOC_CALL3R\n");
			ret = 0;
			break;

		case IOC_CALL1W:
			pr_info("IOC_CALL1W\n");
			ret = 0;
			break;

		case IOC_CALL2W:
			pr_info("IOC_CALL2W\n");
			ret = 0;
			break;

		case IOC_CALL3W:
			pr_info("IOC_CALL3W\n");
			ret = 0;
			break;

		case IOC_CALL1RW:
			pr_info("IOC_CALL1RW\n");
			ret = 0;
			break;

		case IOC_CALL2RW:
			pr_info("IOC_CALL2RW\n");
			ret = 0;
			break;

		case IOC_CALL3RW:
			pr_info("IOC_CALL3RW\n");
			ret = 0;
			break;

		default:
			pr_err("Unknown IOCTL\n");
			break;
	}

	return ret;
}

static int debug_show(struct seq_file *seq, void *data)
{
	seq_printf(seq, "henlo world\n");
	return 0;
}

static int debug_open(struct inode *inode, struct file *file)
{
	return single_open(file, debug_show, NULL);
};

static const struct file_operations fops =
{
	.owner = THIS_MODULE,
	.open = skeletal_open,
	.release = skeletal_release,
	.llseek = noop_llseek,
	.unlocked_ioctl = skeletal_ioctl
};

static const struct file_operations debug_fops = {
	.owner   = THIS_MODULE,
	.open    = debug_open,
	.read    = seq_read,
	.llseek  = seq_lseek,
	.release = single_release
};

static struct miscdevice misc_dev =
{
	.name = "skeletal",
	.fops = &fops
};

static struct dentry *debugfs_dir;

static int __init skeletal_init(void)
{
	int ret;

	ret = misc_register(&misc_dev);
	if (ret) {
		pr_err("Failed to register device!\n");
		return ret;
	}

	dev = misc_dev.this_device;

	debugfs_dir = debugfs_create_dir(misc_dev.name, NULL);
	if (IS_ERR(debugfs_dir))
		return PTR_ERR(debugfs_dir);

	debugfs_create_file("version", 0444, debugfs_dir, NULL, &debug_fops);

	return 0;
}

static void __exit skeletal_exit(void)
{
	misc_deregister(&misc_dev);
}

module_init(skeletal_init);
module_exit(skeletal_exit);

MODULE_DESCRIPTION("asd");
MODULE_LICENSE("GPL");
