#include "get_next_line.h"

#include <stdio.h>
#include <string.h>

// compiling & running: 
// 1. make
// 2 ./get_next_line <file_name>
// (e.g.: ./get_next_line file.txt)

// testing specific functions: 
// ./get_next_line <file_name> test_<function_name>
// (e.g.: ./get_next_line file.txt test_set_line)

// debugging (don't forget the flag -g): 
// 1. change file "launch.json", field "args": ["file.txt", "test_<function_name>"] (no need to add "test_<function_name>" while testing get_next_line in general)
// (e.g.: "args": ["file.txt", "test_fill_test"] or "args": ["file.txt"])
// 2. cc -g get_next_line.c get_next_line_utils.c <test_name> 
// (ex.: cc -g get_next_line.c get_next_line_utils.c test.c)

// possible options for test_<function_name>: [test_fill_line, test_set_line, test_get_next_line]

// int *test_set_line(int fd)
// {
// 	char *buffer;
// 	char *leftover;
// 	int read_elements = 1;
// 	int iteration_number = 1;
// 	int max_numbers = 3;

// 	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
// 	if (!buffer)
// 		free(buffer);

// 	while ((read_elements > 0) & (iteration_number <= max_numbers))
// 	{
// 		read_elements = read(fd, buffer, BUFFER_SIZE);
// 		buffer[read_elements] = '\0';
// 		printf("Iteration number: %d\n", iteration_number);
// 		printf("Initial buffer: %s\n", buffer);
// 		leftover = divide_line(buffer);
// 		printf("Changed buffer: %s\n", buffer);
// 		printf("New leftover: %s\n\n", leftover);
// 		iteration_number++;
// 	}
// 	if (buffer)
// 		free(buffer);
// 	if (leftover)
// 		free(leftover);
// 	return (0);
// }

// int *test_fill_line(int fd)
// {
// 	char *buffer;
// 	char *leftover = "|THIS IS LEFTOVER|";
// 	char *empty_leftover = "";
// 	// char *empty_leftover = NULL;
// 	char *filled_line;
// 	int iteration_number = 1;
// 	int max_numbers = 3;

// 	int leftover_flg = 0;

// 	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
// 	if (!buffer)
// 		free(buffer);

// 	while (iteration_number <= max_numbers)
// 	{
// 		if (leftover_flg == 1)
// 			filled_line = read_line(fd, leftover, buffer);
// 		else if (leftover_flg == 0)
// 			filled_line = read_line(fd, empty_leftover, buffer);

// 		printf("Filled line: %s\n\n", filled_line);
// 		iteration_number++;
// 	}
// 	if (buffer)
// 		free(buffer);
// 	if (filled_line)
// 		free(filled_line);
// 	return (0);
// }

int test_get_next_line(int fd)
{
	char *line;
	int iteration_number = 1;
	int max_numbers = 3;

	while (iteration_number <= max_numbers)
	{
		printf("Iteration number: %d\n", iteration_number);
		line = get_next_line(fd);
		printf("LINE: %s\n\n", line);
		iteration_number++;
	}
	if (line)
		free(line);
	return (0);
}

int main(int argc, char **argv)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		printf("Error with opening a file");
	else
		printf("File was opened successfully. fd = %d\n\n", fd);

	if (argc == 2)
	{
		printf("Testing get_next_line\n\n");
		test_get_next_line(fd);
	}
	// else if (argc == 3)
	// {
	// 	if (!strcmp(argv[2], "test_set_line"))
	// 	{
	// 		printf("Testing set_line\n\n");
	// 		test_set_line(fd);
	// 	}
	// 	else if (!strcmp(argv[2], "test_fill_line"))
	// 	{
	// 		printf("Testing fill_line\n\n");
	// 		test_fill_line(fd);
	// 	}
	// }
	close(fd);
	return (0);
}

	// printf("String before new line symbol: %s\nLen of string: %d\n", buffer, ft_strlen(buffer));
	// printf("Leftover after: %s\n\n", leftover);

	// printf("Full buffer: %s\nLen of full buffer: %d\n", buffer, ft_strlen(buffer));
	// printf("Leftover before: %s\n\n", leftover);