#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) 
{
	va_list args;
	va_start(args, format);

	int charCount = 0;

	while (*format)
	{
	if (*format == '%')
	{
		format++;

		switch (*format)
		{
			case 'c':
				{
					char c = va_arg(args, int);
					putchar(c);
					charCount++;
					break;
	    			}
			case 's':
				{
					char *str = va_arg(args, char *);
					while (*str)
					{
						putchar(*str);
						str++;
						charCount++;
					}
					break;
				}

			case '%':
				putchar('%');
				charCount++;
				break;
			default:
				putchar('%');
				putchar(*format);
				charCount += 2;
				break;
		}
	} else 
	{
		putchar(*format);
		charCount++;
	}

	format++;

	}

	va_end(args);
	return charCount;
}

	int main() 
{
	int count = _printf("Hello, %s! This is our project %c. This is a percent sign: %%.\n", "Nkcubeko Mbali", 'M');
	printf("\nNumber of characters printed: %d\n", count);
	return 0;
}

