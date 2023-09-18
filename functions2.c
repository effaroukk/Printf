#include "main.h"

/* NON PRINTABLE */
/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @types: argument list
 * @buffer: The buffer array that handles print
 * @flags: This calculates the active flags
 * @width: This gets the width
 * @precision: This specifies the precision
 * @size: This specifies the size
 * Return: Number of chars printed
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int z = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[z] != '\0')
	{
		if (is_printable(str[z]))
			buffer[z + offset] = str[z];
		else
			offset += append_hexa_code(str[z], buffer, z + offset);

		z++;
	}

	buffer[z + offset] = '\0';

	return (write(1, buffer, z + offset));
}



/* POINTER */
/**
 * print_pointer - Prints the value of a pointer variable
 * @types: argument list
 * @buffer: The buffer array that handles print
 * @flags: This calculates the active flags
 * @width: This gets the width
 * @precision: This specifies the precision
 * @size: This specifies the size
 * Return: Number of chars printed.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, start_padd = 1;
	unsigned long addrs_num;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	addrs_num = (unsigned long)addrs;

	while (addrs_num > 0)
	{
		buffer[ind--] = map_to[addrs_num % 16];
		addrs_num /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	return (write_pointer(buffer, ind, length,
		width, flags, padd, extra_c, start_padd));
}


/* STRING IN ROT13 */
/**
 * print_rot13string - Print a string in rot13.
 * @types: argument list
 * @buffer: The buffer array that handles print
 * @flags: This calculates the active flags
 * @width: This gets the width
 * @precision: This specifies the precision
 * @size: This specifies the size
 * Return: Numbers of chars printed
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int z, j;
	int count_num = 0;
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (z = 0; str[z]; z++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[z])
			{
				x = out[j];
				write(1, &x, 1);
				count_num++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[z];
			write(1, &x, 1);
			count_num++;
		}
	}
	return (count_num);
}



/* PRINT REVERSE */
/**
 * print_reverse - Prints reverse string.
 * @types: argument list
 * @buffer: The buffer array that handles print
 * @flags: This calculates the active flags
 * @width: This gets the width
 * @precision: This specifies the precision
 * @size: This specifies the size
 * Return: Numbers of chars printed
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int z, count_num = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (z = 0; str[z]; z++)
		;

	for (z = z - 1; z >= 0; z--)
	{
		char z = str[z];

		write(1, &z, 1);
		count_num++;
	}
	return (count_num);
}


