# Hello, world!

This is the first runnable programme in *Foundations in C*. It demonstrates the complete path from a C source file to terminal output. Chapter 2 examines each part of the source code.

## Files

| File | Purpose |
| --- | --- |
| `hello.c` | The C17 source code |
| `Makefile` | The instructions used by `make` to build the programme |

## Build and run

Open a terminal in this directory and enter:

```bash
make hello
./hello
```

The output should be:

```text
Hello, world!
```

`make hello` compiles `hello.c` into an executable named `hello`. The command `./hello` runs that executable from the current directory.

The Makefile selects C17 and enables useful compiler warnings:

```text
-std=c17 -Wall -Wextra -Wpedantic
```

## Try it

Change `world` to your name, save `hello.c`, then build and run it again. Restore `world` afterwards so the example matches the book.

## Clean the directory

Remove the generated executable with:

```bash
make clean
```

On Windows, use an MSYS2 UCRT64 Bash terminal for the commands shown above. In PowerShell, the executable is normally run with `.\hello.exe`.
