# Getting Started

This guide sets up the tools needed to build and test the companion programmes for *Foundations in C*. Choose the section for your operating system, then follow [Build the first example](#build-the-first-example).

## What you need

- A compiler with C17 support
- GNU Make or a compatible `make` implementation
- Git
- A terminal
- A plain-text code editor, such as Visual Studio Code

Visual Studio Code is optional. If you use it, install the Microsoft **C/C++** extension from the Extensions view.

## macOS

Install Apple's Command Line Tools:

```bash
xcode-select --install
```

After the installer finishes, open a new Terminal window and check the tools:

```bash
clang --version
make --version
git --version
```

The supplied Clang compiler supports the C17 mode used by this repository.

## Windows

The recommended environment is **MSYS2 UCRT64**.

1. Download and install MSYS2 from [msys2.org](https://www.msys2.org/). The default location, `C:\msys64`, is recommended.
2. Open the **MSYS2 UCRT64** terminal from the Start menu.
3. Update MSYS2:

   ```bash
   pacman -Syu
   ```

4. If the terminal asks you to close it, reopen **MSYS2 UCRT64** and run `pacman -Syu` again.
5. Install the compiler, build tools and Git:

   ```bash
   pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain git
   ```

6. Check the tools:

   ```bash
   gcc --version
   make --version
   git --version
   ```

Use the **UCRT64** terminal for the repository commands in this guide. MSYS2 recommends UCRT64 for new 64-bit Windows setups.

## Linux

### Ubuntu and Debian

```bash
sudo apt update
sudo apt install build-essential clang git
```

### Fedora

```bash
sudo dnf group install "Development Tools"
sudo dnf install clang git
```

Check the installed tools:

```bash
gcc --version
clang --version
make --version
git --version
```

Only one C compiler is required for ordinary use. Having both GCC and Clang is useful when checking portable code.

## Get the repository

The repository is public, so cloning it does not require GitHub authentication.

```bash
git clone https://github.com/lundschulze/foundations-in-c.git
cd foundations-in-c
```

To open the folder in Visual Studio Code:

```bash
code .
```

If the `code` command is unavailable, open Visual Studio Code and choose **File > Open Folder**.

## Build the first example

From the repository root:

```bash
cd chapters/01-before-the-first-line/hello
make
./hello
```

Expected output:

```text
Hello, world!
```

Remove the generated executable when finished:

```bash
make clean
```

Each chapter README explains its examples and any input they expect.

## Run tests

In an example directory, use the local Makefile:

```bash
make test
```

Not every introductory example needs a separate test target. To build every example and run every available test, return to the repository root and run:

```bash
./scripts/test-all.sh
```

For additional memory and undefined-behaviour checks with Clang:

```bash
./scripts/test-sanitizers.sh
```

GitHub Actions runs the complete validation automatically after repository updates. Open the repository's **Actions** tab to inspect the result; no local terminal is required merely to view it.

## Compiler options used here

The Makefiles use:

```text
-std=c17 -Wall -Wextra -Wpedantic
```

- `-std=c17` selects the C17 language standard.
- `-Wall`, `-Wextra` and `-Wpedantic` ask the compiler to report common mistakes and non-standard code.
- Automated strict builds add `-Werror`, which makes warnings fail the build.

## iPad and Codespaces

On an iPad, you can browse the repository and GitHub Actions in Safari. To edit and run the code in a browser, use [GitHub Codespaces](https://docs.github.com/en/codespaces).

A Codespace can only be created when the GitHub account and organisation policies permit Codespaces for this repository. If `lundschulze/foundations-in-c` is greyed out in the repository selector, an organisation owner must first enable Codespaces access for the organisation or repository. This repository does not change that organisation-level setting.

When access is enabled:

1. Open the repository on GitHub.
2. Select **Code > Codespaces > Create codespace on main**.
3. Wait for the browser editor and terminal to open.
4. Use the same `cd`, `make` and test commands shown above.

A hardware keyboard makes terminal use on an iPad considerably easier, but it is not required for viewing files or test results.

## Common problems

### `make: command not found`

Install the build tools for your operating system. On Windows, make sure you opened the **MSYS2 UCRT64** terminal rather than Command Prompt.

### `gcc` or `clang` is not found

Repeat the compiler installation for your platform, then close and reopen the terminal.

### `No targets specified and no makefile found`

You are in the wrong directory. Use `pwd` and `ls`, then enter an example directory containing a `Makefile`.

### A test script is not executable

From the repository root:

```bash
chmod +x scripts/test-all.sh scripts/test-sanitizers.sh
```

Then run the script again.

## Official references

- [Apple Xcode resources](https://developer.apple.com/xcode/resources/)
- [MSYS2 installation](https://www.msys2.org/docs/installer/)
- [MSYS2 environments](https://www.msys2.org/docs/environments/)
- [Visual Studio Code C/C++ support](https://code.visualstudio.com/docs/languages/cpp)
- [GCC language standards](https://gcc.gnu.org/onlinedocs/gcc/Standards.html)
- [Clang user manual](https://clang.llvm.org/docs/UsersManual.html)
- [GNU Make manual](https://www.gnu.org/software/make/manual/)
