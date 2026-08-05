
#include <stdio.h>
#include <stdbool.h> // Required to use the 'bool' data type

int main()
{
  // ----------------------------------------------------------------------------------------------------
  // TABLE: SUMMARY OF C DATA TYPES
  // ----------------------------------------------------------------------------------------------------
  printf("=======================================================================================================================\n");
  printf("| %-20s | %-6s | %-16s | %-52s | %-16s |\n",
         "Data Type", "Size", "Format Specifier", "Description", "Example Value");
  printf("=======================================================================================================================\n");

  // BASIC TYPES
  printf("| %-20s | %-2zu B   | %-16s | %-52s | %-16s |\n",
         "char", sizeof(char), "%c", "Single character or small integer (-128 to 127)", "'A'");

  printf("| %-20s | %-2zu B   | %-16s | %-52s | %-16s |\n",
         "int", sizeof(int), "%d or %i", "Standard whole number (integer)", "42");

  printf("| %-20s | %-2zu B   | %-16s | %-52s | %-16s |\n",
         "float", sizeof(float), "%f", "Single-precision decimal (6-7 digits accuracy)", "3.141590f");

  printf("| %-20s | %-2zu B   | %-16s | %-52s | %-16s |\n",
         "double", sizeof(double), "%lf", "Double-precision decimal (15-17 digits accuracy)", "3.1415926535");

  printf("| %-20s | %-2zu B   | %-16s | %-52s | %-16s |\n",
         "bool", sizeof(bool), "%d", "Boolean flag: true (1) or false (0)", "true");

  printf("-----------------------------------------------------------------------------------------------------------------------\n");

  // MODIFIED INTEGER TYPES
  printf("| %-20s | %-2zu B   | %-16s | %-52s | %-16s |\n",
         "unsigned int", sizeof(unsigned int), "%u", "Positive-only whole number (doubles positive range)", "4000000000U");

  printf("| %-20s | %-2zu B   | %-16s | %-52s | %-16s |\n",
         "short", sizeof(short), "%hd", "Small integer (uses less memory, -32768 to 32767)", "1234");

  printf("| %-20s | %-2zu B   | %-16s | %-52s | %-16s |\n",
         "long", sizeof(long), "%ld", "Large integer (at least 32 bits)", "1000000000L");

  printf("| %-20s | %-2zu B   | %-16s | %-52s | %-16s |\n",
         "long long", sizeof(long long), "%lld", "Very large integer (at least 64 bits)", "9223372036854775807LL");

  printf("-----------------------------------------------------------------------------------------------------------------------\n");

  // EXTENDED & DERIVED TYPES
  printf("| %-20s | %-2zu B   | %-16s | %-52s | %-16s |\n",
         "long double", sizeof(long double), "%Lf", "Extra-precision floating point decimal", "3.14159265358979L");

  printf("| %-20s | %-2zu B   | %-16s | %-52s | %-16s |\n",
         "pointer (int*)", sizeof(int *), "%p", "Stores the memory address of another variable", "&my_var");

  printf("| %-20s | %-2zu B   | %-16s | %-52s | %-16s |\n",
         "string (char*)", sizeof(char *), "%s", "Sequence of characters (text string)", "\"Hello, C!\"");

  printf("=======================================================================================================================\n\n");

  // ----------------------------------------------------------------------------------------------------
  // PRACTICAL CODE EXAMPLES: HOW TO DECLARE AND PRINT
  // ----------------------------------------------------------------------------------------------------
  printf("--- PRACTICAL PRINTING EXAMPLES ---\n");

  // 1. Basic Variables
  char my_char = 'A';
  int my_int = 42;
  float my_float = 3.14159f;
  double my_double = 3.141592653589793;
  bool my_bool = true;

  // 2. Modified Variables
  unsigned int my_unsigned = 4000000000U;
  short my_short = 1234;
  long long my_long_long = 9223372036854775807LL;

  // 3. Derived Variables
  char my_string[] = "Hello, C!";
  int *my_pointer = &my_int; // Points to the memory address of my_int

  // Executing the printf statements
  printf("char            : %c\n", my_char);
  printf("int             : %d\n", my_int);
  printf("float           : %.2f (formatted to 2 decimal places)\n", my_float);
  printf("double          : %.10lf (formatted to 10 decimal places)\n", my_double);
  printf("bool            : %d (prints as 1 for true, 0 for false)\n", my_bool);
  printf("unsigned int    : %u\n", my_unsigned);
  printf("short           : %hd\n", my_short);
  printf("long long       : %lld\n", my_long_long);
  printf("string          : %s\n", my_string);
  printf("pointer         : %p (memory location in hexadecimal)\n", (void *)my_pointer);

  return 0;
}
