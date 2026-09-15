# Exercise — Line inspector

Read a line into a character array with capacity 80. After checking `fgets`, remove a retained newline and display the text, its `strlen` result, its first character when non-empty and whether the newline fitted.

```bash
make starter
./starter
```

Compare your work with one possible solution:

```bash
make answer
./answer
```

Test an empty line, a short name and a line longer than the array. A long line remains a valid partial string, but unconsumed characters remain in `stdin` for a later read.

