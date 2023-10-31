#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_elf_header(char *filename);
void close_elf(int elf);
void read_elf_header(int elf, Elf64_Ehdr *header);
void print_elf_info(Elf64_Ehdr *header);

/**
 * check_elf - Checks if a file is an ELF file.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void check_elf(unsigned char *e_ident)
{
	int index;

	for (index = 0; index < 4; index++)
{
	if (e_ident[index] != 127 &&
	e_ident[index] != 'E' &&
	e_ident[index] != 'L' &&
	e_ident[index] != 'F')
{
	dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
	exit(98);
	}
	}
}
/**
 * print_elf_header - Prints the ELF header information.
 * @filename: The name of the ELF file.
 */
void print_elf_header(char *filename)
{
	Elf64_Ehdr *header;
	int elf;

	elf = open(filename, O_RDONLY);
	if (elf == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't read file %s\n", filename);
	exit(98);
	}

	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
	close_elf(elf);
	dprintf(STDERR_FILENO, "Error: Can't read file %s\n", filename);
	exit(98);
	}

	read_elf_header(elf, header);
	print_elf_info(header);

	free(header);
	close_elf(elf);
}

/**
 * close_elf - Closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf);
	exit(98);
	}
}

/**
 * read_elf_header - Reads the ELF header from a file.
 * @elf: The file descriptor of the ELF file.
 * @header: A pointer to an Elf64_Ehdr structure to store the header.
 *
 * Description: If the read operation fails - exit code 98.
 */
void read_elf_header(int elf, Elf64_Ehdr *header)
{
	int r;

	r = read(elf, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
	close_elf(elf);
	dprintf(STDERR_FILENO, "Error: Failed to read ELF header\n");
	exit(98);
	}
}

/**
 * print_elf_info - Prints the information contained in the ELF header.
 * @header: A pointer to an Elf64_Ehdr structure representing the ELF header.
 */
void print_elf_info(Elf64_Ehdr *header)
{
	check_elf(header->e_ident);
	printf("ELF Header:\n");
}

/**
 * main - The entry point of the program.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 * the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	if (argc < 2)
	{
	printf("Usage: %s <filename>\n", argv[0]);
	return (1);
	}

	print_elf_header(argv[1]);
	return (0);
}
