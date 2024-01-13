#include "get_next_line.h"
#include <fcntl.h>  // for open
#include <unistd.h> // for close
#include <stdio.h>

#define FILE_PATH "file.txt"

int main(void) {
	int fd = open(FILE_PATH, O_RDONLY);
	if (fd == -1) {
		perror("Error opening file");
		return 1;
	}

	char *line;

	do {
		line = get_next_line(fd);

		if (line) {
			printf("Line: %s\n", line);
			free(line);
		} else {
			printf("End of file\n");
		}
	} while (line != NULL);

	close(fd);

	return (0);
}
