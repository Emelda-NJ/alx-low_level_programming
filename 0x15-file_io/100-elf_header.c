#include "main.h"

/**
 * main - program entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 1 if successfull, 0 if unsuccessfull
 */
int main(int argc, char *argv[])
{
	const char *filename = argv[1];
	int fd = open(filename, O_RDONLY);
	Elf64_Ehdr header;
	ssize_t bytes_read = read(fd, &header, sizeof(header));

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	if (fd == -1)
	{
		fprintf(stderr, "Error opening file\n");
		exit(98);
	}

	if (bytes_read != sizeof(header))
	{
		fprintf(stderr, "Error reading ELF header\n");
		close(fd);
		exit(98);
	}

	if (_memcmp(header.e_ident, ELFMAG, SELFMAG) != 0)
	{
		fprintf(stderr, "Error: Not an ELF file\n");
		close(fd);
		exit(98);
	}

	print_elf_header(&header);

	close(fd);
	return (0);
}

/**
 * print_elf_header - print elf format
 * @header: elf header
 * Return: void
 */
void print_elf_header(const Elf64_Ehdr *header)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:   ");

	for (i = 0; i < EI_NIDENT; ++i)
		printf("%02x ", header->e_ident[i]);

	printf("\n");
	printf("  Class:                             %s\n",
			(header->e_ident[EI_CLASS] == ELFCLASS64) ?
			"ELF64" : "ELF32");
	printf("  Data:                              %s\n",
			(header->e_ident[EI_DATA] == ELFDATA2LSB) ?
			"2's complement, little endian" :
			"2's complement, big endian");
	printf("  Version:                           %d (current)\n",
			header->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %s\n",
			(header->e_ident[EI_OSABI] == ELFOSABI_SYSV) ?
			"UNIX - System V" : "Others");
	printf("  ABI Version:                       %d\n",
			header->e_ident[EI_ABIVERSION]);
	printf("  Type:                              EXEC (Executable file)\n");
	printf("  Entry point address:               0x%lx\n",
			(unsigned long)header->e_entry);
}

/**
 * _memcmp - copies memory area.
 * @s1: memory destination
 * @s2: memory source
 * @n: number of bytes to copy from src
 * Return: pointer to dest
 */
int _memcmp(unsigned char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++, s1++, s2++)
	{
		if (*s1 != *s2)
			return (*s1 < *s2 ? -1 : 1);
	}
	return (0);
}
