#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/stat.h>
#include <inttypes.h>
#include <fcntl.h>

#define SHUTTER_UINT16_ADDR	0x95D

int main(int argc, char *argv[])
{
	int fd = -1;
	uint16_t shutter_count = 0;
	uint16_t int_buf = 0;

	printf("Canon 20D Shutter Count\n");
	printf("by: Daria Juniper\n\n");

	if ( argc != 2 )
	{
		printf("usage: %s <IMG_XXXX.CR2>\n\n", argv[0]);
		exit(-1);
	}

	// open raw file and read out bytes if we can open it.
	if ( fd = open(argv[1], O_RDONLY) )
	{
		// teh magicks >_<
		if ( lseek(fd, SHUTTER_UINT16_ADDR, 0) >= 0 )
		{
			// read byte if we can, and dump count. simple, right?!
			if ( read(fd, &int_buf, sizeof(uint16_t)) )
			{
				shutter_count = (int_buf>>8) | (int_buf<<8); // camera is big-endian, x86 is little endian, fix it.
				printf("Shutter Count: %hu\n\n", shutter_count);
				close(fd);
			} else {
				printf("fatal: unable to read data from file.\n\n");
				close(fd);
				exit(-1);
			}
		} else {
			printf("fatal: unable to seek to 0x95D, invalid file?\n\n");
			close(fd);
			exit(-1);
		}
	} else {
		// failed to open file
		printf("fatal: failed to open %s.\n\n", argv[1]);
		exit(-1);
	}


 return 0;
}



