#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 * @file: The name of the file buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(char *file)
{
	char *buff;

	buff = malloc(sizeof(char) * 1024);

	if (buff == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buff);
}

/**
 * close_file - Closes file descriptors.
 * @c: The file descriptor to be closed.
 */
void close_file(int c)
{
	int i;

	i = close(c);

	if (i == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close c %d\n", c);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	char *buff;
	int before, after, r, w;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buff = create_buffer(argv[2]);
	before = open(argv[1], O_RDONLY);
	r = read(before, buff, 1024);
	after = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (before == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buff);
			exit(98);
		}

		w = write(after, buff, r);
		if (after == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buff);
			exit(99);
		}

		r = read(before, buff, 1024);
		after = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);
	free(buff);
	close_file(before);
	close_file(after);
	return (0);
}
