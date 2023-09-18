#include "main.h"


/**
 * print_unsigned - Printing an unsigned num
 * @types: arguments list
 * @buffer: Buffer array
 * @flags:  Calculating the active flags
 * @width: get width
 * @precision: Precision specification
 * @size: specifing size
 * Return: Number of chars to be printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int z = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[z--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[z--] = (num % 10) + '0';
		num /= 10;
	}

	z++;

	return (write_unsgnd(0, z, buffer, flags, width, precision, size));
}


/**
 * print_octal - Printing an unsigned octal notation
 * @types: arguments list
 * @buffer: Buffer array
 * @flags:  Calculating the active flags
 * @width: get width
 * @precision: Precision specification
 * @size: specifing size
 * Return: Number of chars to be printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int z = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[z--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[z--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[z--] = '0';

	z++;

	return (write_unsgnd(0, z, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - Printing an unsigned  hexadecimal notation
 * @types: arguments list
 * @buffer: Buffer array
 * @flags:  Calculating the active flags
 * @width: get width
 * @precision: Precision specification
 * @size: specifing size
 * Return: Number of chars to be printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}


/**
 * print_hexa_upper - Printing an unsigned  upper hexadecimal numbers
 * @types: arguments list
 * @buffer: Buffer array
 * @flags:  Calculating the active flags
 * @width: get width
 * @precision: Precision specification
 * @size: specifing size
 * Return: Number of chars to be printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}


/**
 * print_hexa - Printing a hexadecimal lower or upper numbers
 * @types: arguments list
 * @map_to: Array of values
 * @buffer: Buffer array
 * @flags:  Calculating the active flags
 * @flag_ch: active flags
 * @width: get width
 * @precision: Precision specification
 * @size:  specifing size
 * @size: Size spec
 * Return: Number of chars to be printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int z = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[z--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[z--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[z--] = flag_ch;
		buffer[z--] = '0';
	}

	z++;

	return (write_unsgnd(0, z, buffer, flags, width, precision, size));
}

