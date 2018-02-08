#include<stdio.h>
#include<stdint.h>

union comm {
	struct by_dev {
		uint32_t dev_a : 8;
		uint32_t dev_b : 8;
		uint32_t dev_c : 8;
		uint32_t dev_d : 8;
	} dev;
	uint32_t msg;
};

int main()
{
	union comm message;
	message.msg	= 0x01020304;

	printf("the size of the structure is: %ld\n", sizeof(message));
	printf("the entire message 0x%x\n", message.msg);
	printf("device A: %d\ndevice B: %d\ndevice C: %d\ndevice D: %d\n",
			message.dev.dev_a, message.dev.dev_b, message.dev.dev_c, message.dev.dev_d);

	return 0;
}
