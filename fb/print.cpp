#include "fb.h"
#include "print.h"

#include <mkmi.h>

void FB_Printf(char *format, ...) {
        va_list ap;
        va_start(ap, format);

	FB_VPrintf(format, ap);

        va_end(ap);
}

static void FB_PrintChar(char ch) {
	FB_PutChar(ch);
}

static void FB_PrintString(char *string) {
	FB_PrintScreen(string);
}

void FB_VPrintf(char *format, va_list ap) {
        char message[1024];
	Memset(message, '\0', 1024);

	char *position = message;
        char *ptr = format;

        while(*ptr) {
                if (*ptr == '%') {
			ptr++;
                        switch (*ptr++) {
                                case 's': {
					char *str = va_arg(ap, uint8_t*);

					FB_PrintString(str);
					}
                                        break;
                                case 'u':
                                case 'd': {
					char buffer[256];
                                        Itoa(buffer, 'd', va_arg(ap, long long int));

					FB_PrintString(buffer);
					}
                                        break;
                                case 'x': {
					char buffer[256];
                                        Itoa(buffer, 'x', va_arg(ap, long long int));

					FB_PrintString(buffer);
					}
                                        break;
                                case '%':
					FB_PrintString("%%");
                                        break;
                                case 'c':
                                        FB_PrintChar(va_arg(ap, char));
                                        break;

                        }
                } else {
			FB_PrintChar(*ptr++);
                }
        }
}
