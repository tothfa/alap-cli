# alap

A minimal command-line template generator written in C.

`alap` is a small CLI utility that creates starter source files for supported programming languages. It is intended for quickly bootstrapping simple projects from the terminal.

## Features

- Creates starter files for multiple programming languages
- Supports C, Java, Python, and Bash templates
- Prints template source to standard output with `--stdout`
- Shows built-in help and version information
- Does not overwrite files that already exist

## Supported templates

| Template ID | Generated file |
|------------|----------------|
| `c` | `main.c` |
| `java` | `Main.java` |
| `py` | `main.py` |
| `sh` | `main.sh` |

## Getting started

There are two common ways to use `alap`:

1. Download a prebuilt binary from the Releases page
2. Build it from source with a C compiler

Prebuilt binaries are useful if you want to try the tool quickly. Building from source is useful if you want to inspect, modify, or package it yourself.

## Build from source

`alap` is written in standard C and can be built with a compatible C compiler.

### Example with GCC or Clang

```bash
cc src/alap.c -O2 -Wall -Wextra -pedantic -o alap
```

If your system does not provide `cc`, you can usually use `gcc` or `clang` directly:

```bash
gcc src/alap.c -O2 -Wall -Wextra -pedantic -o alap
```

or

```bash
clang src/alap.c -O2 -Wall -Wextra -pedantic -o alap
```

On Windows, the output file is typically named `alap.exe`.

## Usage

Run the program with a template identifier:

```bash
alap c
alap java
alap py
alap sh
```

Print a template to standard output instead of creating a file:

```bash
alap py --stdout
```

Show help:

```bash
alap --help
```

Show version information:

```bash
alap --version
```

## Examples

Create a C source file:

```bash
alap c
# [main.c] was created.
```

Create a Python source file:

```bash
alap py
# [main.py] was created.
```

Print the Bash template to standard output:

```bash
alap sh --stdout
```

## Behavior

- If the target file does not exist, `alap` creates it
- If the target file already exists, `alap` leaves it unchanged
- If an unknown template is provided, the program prints an error message
- If an unknown option is provided, the program prints an error message

## Platform notes

The program itself is portable because it uses standard C library functionality. However, binaries are platform-specific and should be built for the target operating system.

The generated Bash script template (`main.sh`) requires a Bash-compatible environment. On Windows, that usually means a tool such as Git Bash, MSYS2, Cygwin, or WSL.

## Releases

Prebuilt binaries, when available, can be found on the [Releases](../../releases) page.

Typical release assets may include:

- `alap-linux-x86_64`
- `alap-windows-x86_64.exe`

## License

MIT
