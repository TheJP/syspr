//For gcc and linux
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	if (argc != 3){
		fprintf(stderr, "my_cp <source> <destination>\n");
		exit(1);
	}
	int handle = open(argv[1], O_RDONLY);
	int handle2 = open(argv[2], O_WRONLY | O_CREAT | O_EXCL); //Only works, if the file does not exist already
	char buf[512];
	int nbytes;
	do {
		nbytes = read(handle, buf, 512);
		write(handle2, buf, nbytes);
	} while (nbytes > 0);
	close(handle);
	close(handle2);
}