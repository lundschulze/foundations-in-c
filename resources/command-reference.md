# Command Reference

A compact reference for the commands used throughout the *Foundations in C* companion repository. Run commands in a terminal. Examples beginning with `./` use the current directory.

## Find your way around

| Command | Purpose |
|---|---|
| `pwd` | Show the current directory. |
| `ls` | List files and directories. |
| `ls -la` | Include hidden files and details. |
| `cd chapters` | Enter the `chapters` directory. |
| `cd ..` | Move up one directory. |
| `cd ../..` | Move up two directories. |
| `clear` | Clear the terminal display. |

Paths containing spaces must be quoted:

```bash
cd "a directory with spaces"
```

## Inspect files

| Command | Purpose |
|---|---|
| `cat README.md` | Print a short text file. |
| `less README.md` | Read a longer file one screen at a time; press `q` to leave. |
| `wc -l answer.c` | Count lines in a file. |
| `find . -name Makefile` | Find every Makefile below the current directory. |

## Build with Make

Run these commands inside a directory containing a `Makefile`.

| Command | Purpose |
|---|---|
| `make` | Build the default target. |
| `make answer` | Build a target named `answer`. |
| `make test` | Build and run the local tests, when provided. |
| `make clean` | Remove generated build files. |
| `make CC=clang` | Build with Clang instead of the default compiler. |
| `make CC=gcc` | Build with GCC. |
| `make clean && make` | Rebuild everything from a clean state. |

The `&&` operator runs the second command only if the first succeeds.

## Compile directly

For a programme contained in one source file:

```bash
cc -std=c17 -Wall -Wextra -Wpedantic answer.c -o answer
./answer
```

The parts mean:

| Part | Meaning |
|---|---|
| `cc` | Invoke the system C compiler. |
| `-std=c17` | Select the C17 language standard. |
| `-Wall -Wextra -Wpedantic` | Enable useful diagnostic warnings. |
| `answer.c` | Compile this source file. |
| `-o answer` | Name the executable `answer`. |
| `./answer` | Run that executable. |

Use `gcc` or `clang` in place of `cc` to select a compiler explicitly.

## Compile and link separately

Compilation translates each source file into an object file:

```bash
cc -std=c17 -Wall -Wextra -Wpedantic -c main.c -o main.o
cc -std=c17 -Wall -Wextra -Wpedantic -c calculations.c -o calculations.o
```

Linking combines the object files into one executable:

```bash
cc main.o calculations.o -o journey
```

The final command is the link step. A programme may compile successfully but still fail to link if a required function definition or library is missing.

## Make variables

A typical Makefile separates options by purpose:

```make
CC ?= cc
CPPFLAGS :=
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic
LDFLAGS :=
LDLIBS :=

journey: main.o calculations.o
	$(CC) $(LDFLAGS) main.o calculations.o $(LDLIBS) -o $@
```

| Variable | Used for |
|---|---|
| `CC` | The C compiler command. |
| `CPPFLAGS` | Preprocessor options such as `-Iinclude` and `-DDEBUG`. |
| `CFLAGS` | C-language and warning options used while compiling. |
| `LDFLAGS` | Linker options such as library search paths: `-Llib`. |
| `LDLIBS` | Libraries to link, commonly written as `-lm`. |

Keep `LDFLAGS` on the link command even when it is empty. This lets a user or automated build supply linker options without editing the Makefile:

```bash
make LDFLAGS="-fsanitize=address,undefined"
```

Libraries normally appear after the object files that require them. For example, a programme using the maths library may need:

```bash
cc main.o -lm -o calculator
```

Here, `-lm` belongs in `LDLIBS`, not `LDFLAGS`.

## Run repository tests

From the repository root:

```bash
./scripts/test-all.sh
```

This builds every example with strict C17 warnings and runs every available `test` target.

Run the sanitizer checks with Clang:

```bash
./scripts/test-sanitizers.sh
```

Run one example's tests:

```bash
cd chapters/08-repetition-and-loops/example-name
make test
```

Replace `example-name` with an actual directory listed in that chapter's README.

## Understand command results

A shell command reports an exit status:

- `0` means success.
- A non-zero value means failure.

Display the most recent status:

```bash
echo $?
```

GitHub Actions uses the same convention. A build or test command returning a non-zero status makes the job fail.

## Essential Git commands

Run Git commands from anywhere inside the cloned repository.

| Command | Purpose |
|---|---|
| `git status` | Show changed, staged and untracked files. |
| `git diff` | Review unstaged changes. |
| `git diff --staged` | Review changes prepared for a commit. |
| `git pull --ff-only` | Download and fast-forward to remote changes without creating a merge commit. |
| `git add path/to/file` | Stage one specific file. |
| `git commit -m "Describe the change"` | Create a local commit. |
| `git push` | Send local commits to GitHub. |
| `git log --oneline -5` | Show the five latest commits. |

Prefer adding named files over `git add .`. It makes accidental inclusion of unrelated files less likely.

Before committing:

```bash
git status
git diff
git add path/to/file
git diff --staged
```

Never commit passwords, tokens, private keys, manuscripts, production PDFs or backup archives. The repository's `.gitignore` reduces accidental additions, but `git status` and `git diff --staged` remain the final checks.

## GitHub without a terminal

The GitHub website can be used to:

- browse and review source files;
- inspect commits and their changes;
- view automatic tests under **Actions**;
- edit small text files;
- open Codespaces when organisation access permits it.

A local terminal or Codespaces terminal is required to run the C programmes interactively. Merely checking an existing GitHub Actions result works directly in a browser, including Safari on iPad.

## Common command patterns

Build, run and clean an example:

```bash
make
./program-name
make clean
```

Test with both common compilers:

```bash
make clean && make CC=gcc test
make clean && make CC=clang test
```

Return to the repository root from a two-level example directory:

```bash
cd ../../..
```

If uncertain where you are, use `pwd` before changing directories.
