include "main.h"

#include <stdlib.h>

/**
 * read_textfile- function that reads & prints a text file to the POSIX stdout
 * @filename: the name of text file it should  read
 * @letters: the number of letters it should read and print
 * Return: w the actual number of letters it could read and print
 *        and 0 when function fails.
 */
ssize_t read_textfile(const char *filename, size_t letters)
	{
	char *buf;
	ssize_t o;
	ssize_t r;
	ssize_t w;

	o = open(filename, O_RDONLY);
	if (o == -1)
	return (0);
	buf = malloc(sizeof(char) * letters);
	r = read(o, buf, letters);
	w = write(STDOUT_FILENO, buf, r);

	free(buf);
	close(o);
	return (w);
	}
