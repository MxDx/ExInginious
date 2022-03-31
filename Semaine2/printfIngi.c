#include<stdio.h>
#include <stdlib.h>
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

/* print_digit
 * @n: an integer
 *
 * result: print to stdout "The magic number is NUMBER.\n"
 */
void print_digit(int number) {
    printf("The magic number is %d. \n", number);
}

void testPrintfFloat(float number) {
    printf("float = %.4f. \n", number);
}

void print_foo() {
    printf("foo\n");
}

/* format_str, example:
 * format_str(buf, 42, "Olivier", 'B') will write into buf
 * the string "Mister Olivier B. has 42 eggs" (no line feed)
 * The given buffer is guaranteed to be big enough
 */
void format_str(char *buffer, unsigned int d, char *name, char initial) {
    sprintf(buffer,"Mister %s %c. has %d eggs", name, initial, d );
}

int main() {
    print_digit(4);
    testPrintfFloat(3.14159);
    print_foo();
    char *buf;
    format_str(buf, 42, "Olivier", 'B');
    return 0;
}