```
                                                                                
                                                                                
    @@@@                                                                        
  @@@@@@ @@@@                                                                   
  @@@&   @@@@                                                                   
@@@@@@@@@@@@@@@                                                                 
  @@@&   @@@@                                                                   
  @@@&   @@@@                                                                   
  @@@&   @@@@                                                                   
  @@@&   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ @@@@@                                                                
  @@@&   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ @@@@@                        @@@@@
                                                                        @@@@@@@
                                  @@@@   @@@@ @@@@@ @@@@@@&   @@@@@     @@@@@   
       @@@@           @@@@@@@     @@@@@@@@@@@ @@@@@@@@@@@@@@  @@@@@     @@@@@   
        @@@@@      @@@@@@@@@@@@   @@@@@    @@ @@@@@    @@@@@@@@@@@@@@@@@@@@@@@@@
          @@@@@@@@@@@@       @@@  @@@@@       @@@@@    @@@@@@@@@@@@@@@@@@@@@@@@@
           @@@@   @@@@       @@@@ @@@@#       @@@@@    @@@@@  @@@@@     @@@@@   
            @@@@  @@@@       @@@@ @@@@#       @@@@@    @@@@@  @@@@@     @@@@@   
    .@@@@@.   @@@% @@@@     @@@@  @@@@#       @@@@@    @@@@@  @@@@@     @@@@@   
  @@@@@@@@@@@@ @@@@ @@@@@@@@@@@   @@@@#       @@@@@    @@@@@  @@@@@     @@@@@   
 @@@@      @@@@ @@@@    @@@       @@@@#       @@@@@    @@@@@  @@@@@     @@@@@   
 @@@#       @@@   @@@             @@@@#       @@@@@    @@@@@  @@@@@@    @@@@@   
 @@@%       @@@    @@@@                                        @@@@@@@  @@@@@   
 @@@@      @@@@     @@@@                                                        
  &@@@@@@@@@@@       %@@@                                                       
     #@@@@@            @@@                                                      
                                                                                
                                                                                
whoAmI(campus=42barcelona, login=mporras-, mail=manuel.porras.ojeda@gmail.com)
Feel free to write!                                                               
```

# ft_printf Library

`ft_printf` is a custom implementation of the classic C library function `printf`. It provides a set of functions designed to format and print data to the standard output, allowing developers to use specific format specifiers for different data types.

This project is a good example of how different a task can be focused depending on your experience. Nowadays, I'm sure that I would change a few things, specially at bonus part. However, this was my approach as it was evaluated.

Grade: 125%.

### IMPORTANT

This project uses libft (my last version) as submodule. So, there is a mini tutorial to work with them:

## Working with Git Submodules

### 1. **Clone the repository with submodules**

When you clone the repository, make sure to use the `--recursive` flag to also clone the submodules:

   ```bash
   git clone --recursive [Repository URL]
   ```

If you've already cloned the repository but forgot to initialize the submodules:

   ```bash
   git submodule update --init
   ```

### 2. **Update submodules**

After pulling changes with `git pull` or switching branches, the submodules might have been updated. Ensure they're synchronized:

   ```bash
   git submodule update --recursive
   ```

### 3. **Add a new submodule**

If you wish to add a new submodule to the project:

   ```bash
   git submodule add [Submodule URL] [path/to/submodule]
   ```

Then, commit the changes to include the new submodule in the project.

### 4. **Remove a submodule**

Removing a submodule involves several steps:

- Delete the relevant entry from the `.gitmodules` file.
- Run `git add .gitmodules`.
- Delete the relevant entry from `.git/config`.
- Run `git rm --cached [path/to/submodule]` (without trailing slash).
- Delete the relevant directory within `.git/modules`.
- Commit the changes.


#### WARNING:

I haven't check my Makefile to work 100% with my new libft.

## Prototype

```c
int	ft_printf(const char *s, ...);
```
ft_printf, as printf, return the number of chars that were printed.

## Variadic Functions

Variadic functions are a feature in C (and some other languages) that allow functions to accept an indefinite number of arguments. The classic example of a variadic function in C is `printf`. Depending on the format string, `printf` can take any number of arguments.

To declare a variadic function, one typically specifies at least one named argument (often used to determine how many of the additional arguments are expected or how to interpret them) followed by an ellipsis `...` to capture the additional arguments.

In C, the `stdarg.h` header provides macros to retrieve these additional arguments. The process typically involves the following steps:

1. Declare a `va_list` type variable to hold the arguments.
2. Use `va_start` macro to initialize the `va_list` variable to point to the first unnamed argument.
3. Use `va_arg` macro to retrieve each argument in succession.
4. Use `va_end` macro to clean up the `va_list` variable.

The exact type and number of arguments must be known at runtime for the program to behave correctly, as the mechanism itself doesn't provide a way to determine the number or types of the arguments passed after the ellipsis.

To play with variadic functions, I began with a calculator function. It was a good way to understand how they work.

## Workflow Description

1. The main entry point for the library is `ft_printf`. Here, the format string is parsed character by character.
2. For every character in the format string, if the character is a `%`, the library interprets the next character as a potential token.
3. `ft_input_to_tokens` will determine if the next character is a recognized token using `ft_is_token`.
4. Once recognized, each token is processed by its corresponding handler function:
    - Integer tokens (`i`, `d`, `u`) are processed by `ft_process_numbers`.
    - String and char tokens (`s`, `c`, `%`) are processed by `ft_process_strings`.
    - Hexadecimal tokens (`x`, `X`, `p`) are processed by `ft_process_hexa`.
5. Each handler function then calls specific print functions (`ft_print_int`, `ft_print_strings`, `ft_print_chars`, `ft_print_hexa`) that recursively break down the value and print it character by character.

## Workflow Diagram

```
+-------------+
| ft_printf   |
+------+------+
       |
       v
+------+-------------+
| ft_input_to_tokens +--> ft_is_token -> NO: keep printing 'base' string
+------+-------------+  
       |
       v
+------+-------------+    +----------------+       +------------------+
| ft_process_strings | <--+ ft_process_hexa | <--+ ft_process_numbers |
+------+-------------+    +----------------+       +------------------+
       |                        |                           |
       v                        v                           v
+------------------+   +-------------------+  +----------------------------+
| ft_print_strings |   | ft_print_hexa     |  | ft_print_int               |
+------------------+   +-------------------+  +----------------------------+
       |
       v
+----------------+
| ft_print_chars |
+----------------+
       |
       V
+-------------+
| ft_printf   | = Number of chars printed.
+------+------+    
```

## Considerations for Testing

To ensure the robust functionality of the `ft_printf` library, consider the following test scenarios:

1. **Basic Format Strings**: Test with simple format strings without tokens.
    - Example: `Hello, World!`
2. **Integer Tokens**: Test with positive, negative, and zero values.
    - Example: `%d`, `%i`, `%u`
3. **String Tokens**: Test with regular strings, empty strings, and NULL strings.
    - Example: `%s`
4. **Character Tokens**: Test with printable and non-printable chars.
    - Example: `%c`, `%%`
5. **Hexadecimal Tokens**: Test with varying integer sizes, and especially focus on boundary values.
    - Example: `%x`, `%X`, `%p`
6. **Mixed Tokens**: Combine different tokens in a single format string.
7. **Edge Cases**: Consider format strings that end with `%`, and strings with multiple consecutive `%` characters.
8. **Large Inputs**: Test with long strings and large numbers.

## Edge Cases and Potential Pitfalls

When testing the `ft_printf` library, it's essential to consider certain edge cases that might lead to unexpected behaviors or even crashes:

1. **Unterminated Format Specifiers**: A format string that ends with a `%` can be problematic if not handled correctly.
    - Example: `"This string ends with a %"`
2. **Unrecognized Tokens**: While `ft_printf` handles known tokens, unpredictable behavior can arise from unrecognized ones.
    - Example: `"Unknown: %z"`
3. **Large Numbers**: Especially for formats like hexadecimal, testing with the upper limits of the data type can be insightful.
    - Example: `INT_MAX`, `UINT_MAX`
4. **Memory Considerations**: Check how the function handles large strings, especially if there's any memory allocation involved.
5. **Null Pointers**: While the library handles NULL strings with a `(null)` print, it's good to ensure that other pointers, if passed unintentionally, don't cause crashes.
    - Example: Using `%s` but passing an integer by mistake.
6. **Multiple Modifiers**: Although not shown in the initial functions, if the library expands to include modifiers (like width, precision), combinations of these can be edge cases.
    - Example: `"%0.5d"`
7. **Overflow Scenarios**: Test with values that could potentially overflow the buffer or exceed the data type's limit.

Always ensure that during testing, proper error handling mechanisms are in place. This not only ensures the robustness of the library but also aids in debugging potential issues.

## Bonus Features

### Enhanced Flag Handling
- **Variable Width and Precision**:
   - Dynamically set the width and precision of the output using `*`.
   - Width and precision can be passed as additional arguments to `ft_printf`.

- **Extended Flags**:
   - `#` (Hash): For alternative form of the output.
   - `+` (Plus): Forces to prepend the result with a plus or minus sign (`+` or `-`) even for positive numbers.
   - `0` (Zero): Pads the result with leading zeros.
   - ` ` (Space): Inserts a space before the result.
   - `-` (Minus): Left-justifies the result.

Keep in mind that some flags overlap its behaviour. That can be a little tricky.

### Advanced Token Parsing
- The bonus version of `ft_printf` is more robust in its parsing of format specifiers. It can recognize a wider range of tokens and flags, making it more versatile and closely aligned with the original `printf` function.

### Improved Hexadecimal Printing
- The bonus version includes advanced handling for hexadecimal output, ensuring correct representation and considering the hash (`#`) flag for alternate forms.

### Memory Efficiency
- Dynamic memory allocations are used more wisely, with a more systematic approach towards initialization and freeing of memory, ensuring no memory leaks.

### Considerations and Testing:
- **Memory Leaks**: Given the usage of dynamic memory allocation, it's vital to check for memory leaks. Tools like `valgrind` can be helpful.
- **Edge Cases**: Test with maximum and minimum possible values for data types. Also, check the behavior when using multiple flags together.
- **Compatibility**: Ensure that the output of the bonus `ft_printf` matches the output of the system's `printf` function for similar inputs.

## Generating Documentation with Doxygen

To generate detailed, and more friendly documentation for this project, follow the steps outlined below:

### 1. Install Doxygen:

If you haven't already installed Doxygen, you can do so using your system's package manager.

* Debian/Ubuntu-based systems:

```bash
sudo apt-get install doxygen
```

* On macOS:

```bash
brew install doxygen
```

### 2. Generate the Documentation:

From the root directory of the project, where the `Doxyfile` is located, run:

```bash
doxygen Doxyfile
```

### 3. View the Documentation:

Once Doxygen completes the documentation generation, you can view it by opening the `html/index.html` file in your preferred web browser:

```bash
open docs/html/index.html   # On macOS
xdg-open docs/html/index.html   # On Linux systems
```