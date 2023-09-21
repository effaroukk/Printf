#include "main.h"

/* PRINT UNSIGNED NUMBER */
/**
 * print_unsigned -unsigned number to be printed
 * @types: arguments list
 * @buffer: Buffer array handle to be printed
 * @flags: active flags to be calculated
 * @width: get width
 * @precision: Precision specs
 * @size: specifing the size
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

/*PRINT UNSIGNED NUMBER IN OCTAL*/
/**
 * print_octal - unsigned number in octal notation to be printed
 * @types: arguments list
 * @buffer: Buffer array  handle to be printed
 * @flags: active flags calculation
 * @width: get width
 * @precision: Precision specs
 * @size: specifing the size
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

/*PRINT UNSIGNED NUMBER IN HEXADECIMAL */
/**
 * print_hexadecimal - unsigned number in hexadecimal notation to be printed
 * @types: arguments list
 * @buffer: Buffer array handle to be printed
 * @flags:  Calculating the active flags
 * @width: get width
 * @precision: Precision specs
 * @size: Size specifier
 * Return: Number of chars to be printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL */
/**
 * print_hexa_upper - unsigned number in
 * upper hexadecimal notation to be printd
 * @types: arguments list
 * @buffer: Buffer array handle to be printed
 * @flags:  active flags calculation
 * @width: get width
 * @precision: Precision specs
 * @size: specifing the size
 * Return: Number of chars to be printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/* PRINT HEXX NUM IN LOWER OR UPPER */
/**
 * print_hexa - hexadecimal number in lower or upper to be printed
 * @types: arguments list
 * @map_to: Array of values to map the number
 * @buffer: Buffer array to handle printed value
 * @flags: active flags calculations
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specs
 * @size: specifing the size
 * @size:specification the size
 * Return: Number of chars to be printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[a--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[a--] = flag_ch;
		buffer[a--] = '0';
	}

	a++;

	return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}

