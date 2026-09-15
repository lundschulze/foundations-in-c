# Troubleshooting

Use this guide when a companion programme does not build, link, run or pass its tests. Start with the first error message: later messages are often consequences of the first one.

## Quick diagnostic check

From the repository root, run:

```bash
pwd
git status
cc --version
make --version
./scripts/test-all.sh
```

The output answers five useful questions:

1. Are you in the expected directory?
2. Are there uncommitted changes?
3. Is a C compiler available?
4. Is Make available?
5. Does the problem affect one example or the complete repository?

To select a compiler explicitly:

```bash
CC=gcc ./scripts/test-all.sh
CC=clang ./scripts/test-all.sh
```

## Identify the stage that failed

A C programme normally passes through four stages:

1. **Preprocessing** expands `#include` and macros.
2. **Compilation** checks and translates C source.
3. **Linking** combines object files and libraries into an executable.
4. **Execution** runs the finished programme.

The wording of an error usually identifies the stage:

| Message contains | Likely stage |
|---|---|
| `No such file or directory` after an `#include` | Preprocessing |
| `error:`, `warning:` or a source line number | Compilation |
| `undefined reference`, `duplicate symbol` or `multiple definition` | Linking |
| `Segmentation fault`, sanitizer output or incorrect text | Execution |
| `expected`, `FAILED` or a non-zero test result | Testing |

## Terminal and directory problems

### `make: command not found`

Make is not installed or is not on the shell's search path.

- **macOS:** run `xcode-select --install`.
- **Windows:** open **MSYS2 UCRT64** and install the packages in [Getting Started](getting-started.md).
- **Ubuntu or Debian:** run `sudo apt install build-essential`.
- **Fedora:** install the **Development Tools** group.

Close and reopen the terminal after installation.

### `No targets specified and no makefile found`

The current directory does not contain a `Makefile`.

```bash
pwd
ls
```

Enter the required example directory, then run `make` again. The chapter README lists its example paths.

### `Permission denied` for a test script

From the repository root:

```bash
chmod +x scripts/test-all.sh scripts/test-sanitizers.sh
```

Then retry the command.

### `/usr/bin/env: 'bash\r': No such file or directory`

The script has Windows CRLF line endings. Do not edit repository shell scripts in an editor configured to replace LF with CRLF. In Visual Studio Code, select **CRLF** in the status bar, change it to **LF**, save the file and review the change with `git diff`.

### A path containing spaces fails

Quote the complete path:

```bash
cd "My C Projects/foundations-in-c"
```

## Compiler problems

### `cc`, `gcc` or `clang` is not found

Install a compiler as described in [Getting Started](getting-started.md), reopen the terminal and verify it:

```bash
gcc --version
clang --version
```

Only the compiler you intend to use must be present.

### `fatal error: 'header.h' file not found`

Check the header name, capitalisation and location. On Linux, `Guide.h` and `guide.h` are different files.

For project headers in another directory, the Makefile may need a preprocessor search path:

```make
CPPFLAGS := -Iinclude
```

Use angle brackets for standard-library headers and quotation marks for project headers:

```c
#include <stdio.h>
#include "guide.h"
```

### A warning becomes an error

The automated tests use `-Werror`, so every warning must be fixed. For example:

```text
error: unused variable 'count' [-Werror,-Wunused-variable]
```

Remove the unused variable or use it as intended. Do not silence warnings globally merely to make the test green; warnings often reveal a real error.

Reproduce the strict build locally:

```bash
make clean
make CFLAGS="-std=c17 -Wall -Wextra -Wpedantic -Werror"
```

### The compiler rejects newer syntax

The repository targets C17. Ensure `CFLAGS` contains `-std=c17` and avoid features introduced only in later C standards.

## Linker problems

### `undefined reference to ...` or `undefined symbol: ...`

A declaration was visible while compiling, but the linker could not find the corresponding definition.

Suppose `main.c` calls `calculate_total`, which is defined in `calculations.c`. This command omits the required file:

```bash
cc -std=c17 -Wall -Wextra -Wpedantic main.c -o journey
```

It must include both translation units:

```bash
cc -std=c17 -Wall -Wextra -Wpedantic main.c calculations.c -o journey
```

With object files:

```bash
cc main.o calculations.o -o journey
```

Check that:

- the source file containing the definition is part of the link command;
- the declaration and definition use exactly the same function name;
- the function is not incorrectly declared `static` in another source file;
- every required library is listed after the object files that use it.

### A maths function produces an undefined reference

On systems that require the maths library explicitly:

```bash
cc main.o -lm -o calculator
```

In a Makefile, place `-lm` in `LDLIBS`:

```make
LDLIBS := -lm
```

`LDFLAGS` is for linker options, such as sanitizer settings or library search paths. `LDLIBS` is for the libraries themselves.

### `multiple definition` or `duplicate symbol`

The same externally visible function or global variable has been defined more than once.

Common causes are:

- placing a function definition in a header included by several source files;
- defining a global variable in a header;
- listing the same object file twice on the link command.

Headers should normally contain declarations. Put one definition in one `.c` file. A shared global variable, when genuinely required, can be declared in a header with `extern` and defined once in a source file.

### Sanitizer linking fails

Sanitizer options are required at both compilation and linking. The repository's sanitizer script supplies them correctly:

```bash
./scripts/test-sanitizers.sh
```

For a manual Make build:

```bash
make clean
make \
  CC=clang \
  CFLAGS="-std=c17 -Wall -Wextra -Wpedantic -Werror -O1 -g -fsanitize=address,undefined -fno-omit-frame-pointer" \
  LDFLAGS="-fsanitize=address,undefined"
```

If `LDFLAGS` is omitted from the Makefile's final link command, compilation may succeed while linking fails. The correct recipe keeps it in the link step:

```make
program: main.o
	$(CC) $(LDFLAGS) main.o $(LDLIBS) -o $@
```

## Programme and input problems

### The programme appears to hang

It may be waiting for input. Read the example README and look for a prompt. Enter the requested value and press Return.

For repeatable input, redirect a small text fixture:

```bash
./program < test-input.txt
```

Or pipe one line:

```bash
printf '42\n' | ./program
```

### Invalid input causes repeated prompts

Input-validation examples deliberately reject malformed text. Test with one invalid line followed by a valid line:

```bash
printf 'not-a-number\n42\n' | ./program
```

If a loop never advances, check that the invalid input is consumed before the next attempt.

### Output looks correct but the test fails

Automated comparisons are exact. Check for:

- missing or extra spaces;
- different capitalisation;
- missing punctuation;
- an extra or missing newline;
- prompts printed to the wrong stream;
- output appearing in a different order.

Reveal otherwise invisible characters:

```bash
./program | cat -vet
```

### `Segmentation fault`

The programme accessed memory incorrectly. Common causes include:

- dereferencing a null or invalid pointer;
- using an array index outside its bounds;
- using memory after `free`;
- writing beyond a string buffer;
- reading an uninitialised pointer.

Run the sanitizer checks and use the first reported source location:

```bash
./scripts/test-sanitizers.sh
```

### AddressSanitizer reports a leak

Every successful allocation should have a matching `free` along every ownership path. Identify who owns the allocation, then make the cleanup responsibility explicit. Do not merely disable leak detection.

### UndefinedBehaviourSanitizer reports signed overflow

Signed integer overflow is undefined in C. Validate the range before performing the operation, or select a suitable type and define the accepted bounds clearly.

## Make and stale-build problems

### A change does not appear in the programme

Remove existing generated files and rebuild:

```bash
make clean
make
```

Then confirm that you are running the executable from the same directory:

```bash
pwd
ls -l
./program-name
```

### `make test` has no target

Not every introductory example has a dedicated test. Read its README or use the repository-wide runner, which executes `test` only where the Makefile provides it:

```bash
./scripts/test-all.sh
```

### One compiler passes and another fails

Compiler diagnostics differ, and one compiler may detect a portability problem that the other misses. Reproduce both builds:

```bash
make clean && make CC=gcc test
make clean && make CC=clang test
```

Treat either failure as something to investigate. GitHub Actions requires both compilers to pass.

## GitHub Actions problems

### Find the useful error

1. Open the repository's **Actions** tab.
2. Select the failed **C17 validation** run.
3. Open the red GCC, Clang or sanitizer job.
4. Expand **Build and test every chapter** or **Build and test with Clang sanitizers**.
5. Search upwards for the first `error:`, `FAILED`, `undefined reference` or sanitizer heading.

The repository-wide script prints `[build]`, `[starter]` and `[test]` before each directory, so the nearest such line identifies the affected example.

### It passes locally but fails on GitHub

GitHub Actions runs on Linux with a clean checkout. Check for:

- filename capitalisation that macOS or Windows did not expose;
- an uncommitted local file required by the build;
- reliance on a generated file left from an earlier build;
- non-portable compiler extensions;
- assumptions about the current working directory;
- tests depending on locale, time or interactive input.

Review what Git actually contains:

```bash
git status
git ls-files
```

Then reproduce a clean, strict build:

```bash
make clean
CFLAGS="-std=c17 -Wall -Wextra -Wpedantic -Werror" ./scripts/test-all.sh
```

### Rerunning a failed job

Rerun only after understanding the failure or when GitHub reports an infrastructure problem. A deterministic compiler or test failure is expected to fail again until the source is corrected.

## Platform differences

### Windows

Use the **MSYS2 UCRT64** terminal. An executable may be stored as `answer.exe`, but it can normally be started there with:

```bash
./answer
```

Use forward slashes in shell paths. Do not mix commands from Command Prompt, PowerShell and the MSYS2 shell without checking their syntax.

### macOS

Apple's default compiler command may identify itself as Clang even when invoked as `cc`. This is normal. Install or refresh the Command Line Tools if headers or build tools disappear after a system update:

```bash
xcode-select --install
```

### Linux

Linux filenames are case-sensitive. It is also the environment used by GitHub Actions, so a case mismatch may surface there first.

## Before asking for help

Include:

- the exact command you ran;
- the first complete error message;
- the example directory;
- your operating system;
- `cc --version` and `make --version`;
- whether `make clean` changed the result;
- whether the failure occurs with GCC, Clang or both.

Do not include passwords, access tokens, private keys, manuscript files or private publishing material in logs or screenshots.
