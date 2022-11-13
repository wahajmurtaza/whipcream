<h1 align="center">
  <img src="assets/logo.png" width="370px" height="370px" alt="whipcream">
</h1>


### WhipCream — Never use printf() to debug again
WhipCream is inspired by <a href="https://github.com/gruns/icecream">IceCream - Python</a>


Do you ever use `printf()` or `print` to debug your code? Of course you
do. WhipCream, or `wc` for short, makes print debugging a little sweeter.

`wc()` is like `print()`, but better:

  1. It prints both expressions/variable names and their values.
  2. It's 60% faster to type.
  3. It can directly print by setting a default format or can be provided print format.
  4. A Single function can be used for multiple arguments / without arguments (to print code access)
  4. Output is syntax highlighted.
  5. It optionally includes program context: filename, line number, and parent function.
  6. *CAN BE USED WITH CUSTOM DEBUG FUNCTIONS!!!*
  7. Buffer size can be changed
  8. Colors can be disabled
  9. Prints can be disabled anytime
  10. Lite-weight (Single header file)

### Inspect Variables

Have you ever printed variables or expressions to debug your program? If
you've ever typed something like

```c
printf("%d", x);
printf("%d", max(2,3));
```

or the more thorough

```c
printf("x = %d", x);
printf("max = %d", max(2,3));
```

then `wc()` will put a smile on your face. With arguments, `wc()`
inspects itself and prints both its own arguments and the values of
those arguments.

```c
#include <stdio.h>
#include "whipcream.h"

int max(int a, int b){
    return a>b ? a : b;
}

int main(){
    int c;
    wc(c = 32*45); // Pass whole expression

    wc(c);  // check the variables, as value is stored in it

    wc(max(8,3)); // debug the ouput of function
    
    return 0;    
}

```

Prints

<img src="assets/images/output-1.jpg" alt="out1">

Similarly, You can pass a format for the variable if the data-type is not the default-format,

```c
char *str = "This is string output";
int a = 4;

wc(a);
wc(str, "%s");
```

Prints

<img src="assets/images/output-2.jpg" alt="out2">

Just give `wc()` a variable or expression and you're done. Easy.


### Inspect Execution

Have you ever used `printf()` to determine which parts of your program are
executed, and in which order they're executed? For example, if you've ever added
print statements to debug code like

```c
void foo(){
    printf("--0\n");
    first();

    if (expression){
        printf("--1\n");
        second();
    }
    else{
        printf("--2\n");
        third();
    }
}
```

then `wc()` helps here, too. Without arguments, `wc()` inspects itself and
prints the calling filename, line number, and parent function.

```c
void foo(){
    wc();
    first();

    if (expression){
        wc();
        second();
    }
    else{
        wc();
        third();
    }
}
```

Prints

<img src="assets/images/output-3.jpg" alt="out3">

Just call `wc()` and you're done. Simple.


### Custom Function
`wc()` can be used with external functions. The output can be used with external custom_debug function and can be used to log, serial print, broadcast data etc..

Just Define `CUSTOM_DEBUG` or uncomment in `whipcream.h`
```c
#define CUSTOM_DEBUG
```

```c
int custom_debug(char* raw_input){
    printf("DEBUG:: %s\n", raw_input);
    return 1;
}


int main(){
    int a = 964;
    wc(a);
    return 0;    
}
```

Prints

<img src="assets/images/output-4.jpg" alt="out4">

You might want to disable colours for this. (See configuration)


## Configuration

### DISABLE DEBUG

To disable debug simply define `PRINTS_DISABLED` or uncomment in `whipcream.h`
```c
#define PRINTS_DISABLED
```

The output is disabled but the function calls, and expressions are kept safe.

```c
int global_x = 23;

int set_global_x(int x){
    global_x = x;
    return global_x;
}

int main(){
    wc(set_global_x(21));
    printf("global_x = %d\n", global_x);
    int a=0;
    printf("a = %d\n", a);
    wc(a=3);
    wc(a);
    printf("a = %d\n", a);
    return 0;    
}
```

Prints

<img src="assets/images/output-5.jpg" alt="out5">


**DISABLING OUTPUT PRINTS**

<img src="assets/images/output-6.jpg" alt="out6">


### CUSTOM DEBUG EXTERNAL FUNCTION

To use custom debug function simply define `CUSTOM_DEBUG` or uncomment in `whipcream.h`
```c
#define CUSTOM_DEBUG
```

The function can be defined externally by 
```c
int custom_debug(char *);
```

```c
int custom_debug(char* raw_input){
    printf("DEBUG:: %s\n", raw_input);
    return 1;
}


int main(){
    int a = 964;
    wc(a);
    return 0;    
}
```

Prints

<img src="assets/images/output-4.jpg" alt="out4a">

You might want to disable colours for this.

### DISABLE COLOURED OUTPUT

To disable colours simply define `COLORS_DISABLED` or uncomment in `whipcream.h`
```c
#define COLORS_DISABLED
```

This is especially useful when logging or using custom debug function

### CHANGING DEFAULT FORMAT (1-argument)

When 1 argument is passed (without format) the default format is used for printing which can be changed in `whipcream.h` header file
```c
#define DEFAULT_FMT "%10d" //(default value)
```

lets set this to
```c
#define DEFAULT_FMT "str: %30s" //(str value)
```

```c
int main(){
    char *ss = "CRIMINAL MIND";
    wc(ss);
    return 0;    
}
```

prints

<img src="assets/images/output-7.jpg" alt="out7">


### OUTHER CONFIGURATIONS
These changes can be made in `whipcream.h`

`_FILE_COLOR` : The color for printing file name (default cyan)
`_VAR_COLOR` : The color for printing variable name (default yellow)
`_VALUE_COLOR` : The color for printing variable value (default green)
`CUSTOM_BUFFER_SIZE` : Buffer Size to Print Message (when used custom print function)  (default 300)
`_FILE_NAME_BUFF_SIZE` : Max string size for printing the file name  (default 30)
`_VAR_NAME_BUFF_SIZE` : Max string size for printing the variable name (default 20)


### Author

Name: `Wahaj Murtaza`

Email: `wahajmurtaza@gmail.com`

Github: https://github.com/wahajmurtaza/


