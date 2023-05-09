#include "main.h"
#include <elf.h>

void print_osabi_more(Elf64_Ehdr hs);

/**
 * print_magic - prints ELF magic bytes
 * @hs: the ELF header struct
 */
void print_magic(Elf64_Ehdr hs)
{
	int d;

	printf("  Magic:   ");
	for (d = 0; d < EI_NIDENT; d++)
		printf("%2.2x%s", hs.e_ident[d], d == EI_NIDENT - 1 ? "\n" : " ");
}

/**
 * print_class - prints ELF class
 * @hs: the ELF header struct
 */
void print_class(Elf64_Ehdr hs)
{
	printf("  Class:                             ");
	switch (hs.e_ident[EI_CLASS])
	{
		case ELFCLASS64:
			printf("ELF64");
		break;
		case ELFCLASS32:
			printf("ELF32");
		break;
		case ELFCLASSNONE:
			printf("none");
		break;
	}
	printf("\n");
}

/**
 * print_data - prints ELF data
 * @hs: the ELF header struct
 */
void print_data(Elf64_Ehdr hs)
{
	printf("  Data:                              ");
	switch (hs.e_ident[EI_DATA])
	{
		case ELFDATA2MSB:
			printf("2's complement, big endian");
		break;
		case ELFDATA2LSB:
			printf("2's complement, little endian");
		break;
		case ELFDATANONE:
			printf("none");
		break;
	}
	printf("\n");
}

/**
 * print_version - prints ELF version
 * @hs: the ELF header struct
 */
void print_version(Elf64_Ehdr hs)
{
	printf("  Version:                           %d", hs.e_ident[EI_VERSION]);
	switch (hs.e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)");
		break;
		case EV_NONE:
			printf("%s", "");
		break;
		break;
	}
	printf("\n");
}

/**
 * print_osabi - prints ELF osabi
 * @hs: the ELF header struct
 */
void print_osabi(Elf64_Ehdr hs)
{
	printf("  OS/ABI:                            ");
	switch (hs.e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris");
			break;
		case ELFOSABI_AIX:
			printf("UNIX - AIX");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64");
			break;
		default:
			print_osabi_more(hs);
			break;
	}
	printf("\n");
}


/**
 * print_osabi_more - prints ELF osabi more
 * @hs: the ELF header struct
 */
void print_osabi_more(Elf64_Ehdr hs)
{
	switch (hs.e_ident[EI_OSABI])
	{
		case ELFOSABI_MODESTO:
			printf("Novell - Modesto");
			break;
		case ELFOSABI_OPENBSD:
			printf("UNIX - OpenBSD");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App");
			break;
		case ELFOSABI_ARM:
			printf("ARM");
			break;
		default:
			printf("<unknown: %x>", hs.e_ident[EI_OSABI]);
			break;
	}
}

/**
 * print_abiversion  - prints ELF ABI version
 * @hs: the ELF header struct
 */
void print_abiversion(Elf64_Ehdr hs)
{
	printf("  ABI Version:                       %d\n",
		hs.e_ident[EI_ABIVERSION]);
}

/**
 * print_type - prints the ELF type
 * @hs: the ELF header struct
 */
void print_type(Elf64_Ehdr hs)
{
	char *p = (char *)&hs.e_type;
	int x = 0;

	printf("  Type:                              ");
	if (hs.e_ident[EI_DATA] == ELFDATA2MSB)
		x = 1;
	switch (p[x])
	{
		case ET_NONE:
			printf("NONE (None)");
			break;
		case ET_REL:
			printf("REL (Relocatable file)");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)");
			break;
		case ET_CORE:
			printf("CORE (Core file)");
			break;
		default:
			printf("<unknown>: %x", p[x]);
		break;
	}
	printf("\n");
}

/**
 * print_entry - prints the ELF entry point address
 * @hs: the ELF header struct
 */
void print_entry(Elf64_Ehdr hs)
{
	int x = 0, lon = 0;
	unsigned char *p = (unsigned char *)&hs.e_entry;

	printf("  Entry point address:               0x");
	if (hs.e_ident[EI_DATA] != ELFDATA2MSB)
	{
		x = hs.e_ident[EI_CLASS] == ELFCLASS64 ? 7 : 3;
		while (!p[x])
			x--;
		printf("%x", p[x--]);
		for (; x >= 0; x--)
			printf("%02x", p[x]);
		printf("\n");
	}
	else
	{
		x = 0;
		lon = hs.e_ident[EI_CLASS] == ELFCLASS64 ? 7 : 3;
		while (!p[x])
			x++;
		printf("%x", p[x++]);
		for (; x <= lon; x++)
			printf("%02x", p[x]);
		printf("\n");
	}
}

/**
 * main - program
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 1 on success 0 on failure
 */
int main(int ac, char **av)
{
	int fl;
	Elf64_Ehdr hs;
	ssize_t by;

	if (ac != 2)
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n"), exit(98);
	fl = open(av[1], O_RDONLY);
	if (fl == -1)
		dprintf(STDERR_FILENO, "Can't open file: %s\n", av[1]), exit(98);
	by = read(fl, &hs, sizeof(hs));
	if (by < 1 || by != sizeof(hs))
		dprintf(STDERR_FILENO, "Can't read from file: %s\n", av[1]), exit(98);
	if (hs.e_ident[0] == 0x7f && hs.e_ident[1] == 'E' && hs.e_ident[2] == 'L' &&
			hs.e_ident[3] == 'F')
	{
		printf("ELF Header:\n");
	}
	else
		dprintf(STDERR_FILENO, "Not ELF file: %s\n", av[1]), exit(98);

	print_magic(hs);
	print_class(hs);
	print_data(hs);
	print_version(hs);
	print_osabi(hs);
	print_abiversion(hs);
	print_type(hs);
	print_entry(hs);
	if (close(fl))
		dprintf(STDERR_FILENO, "Error closing file descriptor: %d\n", fl), exit(98);
	return (EXIT_SUCCESS);
}
