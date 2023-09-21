#include "main.h"


/* PRINT CHAR */

/**
 * print_char - char to be printed
 * @types: arguments list
 * @buffer: Buffer array handle to be printed
 * @flags:  active flags calculations
 * @width: Width
 * @precision: Precision specs
 * @size: specifing size
 * Return: Number of chars to be printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/* PRINT A STRING */
/**
 * print_string - Printing  string
 * @types: arguments list
 * @buffer: Buffer array handle to be printd
 * @flags:  active flags calculations
 * @width: get width.
 * @precision: Precision specs
 * @size: specifing size
 * Return: Number of chars to be printed
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, z;
	char *str = va_arg(types, char *);

	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	UNUSED(buffer);
	UNUSED(flags);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (z = width - length; z > 0; z--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (z = width - length; z > 0; z--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/* PRINT PERCENT SIGN */
/**
 * print_percent - Printing the  percentage sign
 * @types: arguments list
 * @buffer: Buffer array handle to be print
 * @flags:  active flags calculaions
 * @width: get width.
 * @precision: Precision specs
 * @size: specifing size
 * Return: Number of chars to be printed
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(flags);
	UNUSED(width);
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/* PRINT INT*/
/**
 * print_int - Printing int
 * @types: arguments list
 * @buffer: Buffer array handle
 * @flags: active flags calculations
 * @width: get width.
 * @precision: Precision specs
 * @size: specifing size
 * Return: Number of chars to be printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int z = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[z--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[z--] = (num % 10) + '0';
		num /= 10;
	}

	z++;

	return (write_number(is_negative, z, buffer, flags, width, precision, size));
}

/* PRINT BINARY */
/**
 * print_binary - unsigned number to be printed
 * @types: arguments list
 * @buffer: Buffer array
 * @flags: active flags calulation
 * @width: get width.
 * @precision: Precision specs
 * @size: Size specifing size
 * Return: Numbers of char to be printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, q, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(precision);
	UNUSED(size);
	UNUSED(flags);
	UNUSED(width);

	n = va_arg(types, unsigned int);
	m = 2147483648;
	a[0] = n / m;
	for (q = 1; q < 32; q++)
	{
		m /= 2;
		a[q] = (n / m) % 2;
	}
	for (q = 0, sum = 0, count = 0; q < 32; q++)
	{
		sum += a[q];
		if (sum || q == 31)
		{
			char z = '0' + a[q];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

