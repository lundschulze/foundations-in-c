# Milestone 03 — Galactic Field Log

Build a persistent command-line field log for observations gathered across several destinations. The number of records is not known in advance, so the collection must grow dynamically and survive between programme runs.

This is the final independent project for the book. It combines the complete C17 foundation without supplying a reference implementation or automated answer checker.

## Prerequisites

Complete Chapters 1–23 before starting. You will use:

- structures, arrays, strings and pointers;
- dynamic allocation and explicit ownership;
- defensive copying and input validation;
- text files and checked stream operations;
- header files and multiple implementation files;
- deliberate cleanup on every exit path.

## Record requirements

Each field-log record must contain:

- a destination name of up to 39 characters;
- a priority from 1 to 5;
- an observation of up to 79 characters.

Reject empty text and any name or observation containing the file-format separator `|`, a carriage return or an embedded newline.

## Required operations

The programme must repeatedly offer:

1. Add a record.
2. List all records.
3. Search by exact destination name.
4. Remove a record.
5. Save the log.
6. Load the log.
7. Quit.

Use `field-log.txt` as the default data file.

## Dynamic collection

Start with capacity for four records. When the collection is full:

- check that the larger allocation cannot overflow `size_t`;
- grow the capacity, normally by doubling it;
- store the result of `realloc` in a temporary pointer;
- leave the original collection unchanged if growth fails;
- initialise all count and capacity values explicitly.

Removing a record must close the gap while preserving the order of the remaining records.

## File format

Store one record per line:

```text
destination|priority|observation
```

For example:

```text
Aurora Station|4|Signs of planetary construction
Earth|2|Ready for departure
```

Saving must check every write and the result of `fclose`.

Loading must:

- validate every separator, number and line length;
- reject priorities outside 1–5;
- reject a final truncated or unterminated line;
- build the loaded records in a temporary collection;
- replace the current collection only after the entire file is valid;
- preserve the current data if loading fails.

## Multi-file requirement

Organise the finished programme into at least:

```text
main.c
field_log.c
field_log.h
storage.c
storage.h
Makefile
```

A reasonable division is:

- `main.c`: menu and user interaction;
- `field_log.c/.h`: collection ownership and record operations;
- `storage.c/.h`: saving, loading and parsing.

You may choose different names if ownership and responsibilities remain clear.

## Acceptance scenarios

Check these manually; the exact output design is yours.

- A new log starts empty when no data has been loaded.
- Four records fit without growth.
- Adding a fifth record grows the collection and preserves the first four.
- Removing the first, middle and last record leaves the correct order.
- Searching reports both present and absent destinations correctly.
- Saving and loading reproduces every record exactly.
- A malformed priority, missing separator or overlong line rejects the complete load.
- A failed load leaves the previous in-memory log unchanged.
- Quitting after unsaved changes asks for confirmation or clearly documents that they will be lost.
- Every allocated block and every opened stream is released before exit.

Run the programme under the repository's sanitizer configuration while testing memory ownership.

## Suggested milestones

1. Design the record and collection types in a header.
2. Create and destroy an empty collection.
3. Add records without growth.
4. Implement checked growth with `realloc`.
5. List, search and remove records.
6. Build the menu and robust line input.
7. Save a small valid file.
8. Load into a temporary collection.
9. Reject malformed and overlong records.
10. Split storage from collection logic.
11. Exercise every acceptance scenario.
12. Run compiler warnings and sanitizers, then review cleanup paths.

Build frequently:

```bash
make
./galactic-field-log
```

Remove generated files with:

```bash
make clean
```

## Starting point

`main.c` is only a compilable placeholder. Replace it gradually and extend the Makefile as you add implementation files. There is intentionally no `answer.c`.

## Optional extensions

After the required version works, consider:

- editing an existing record;
- sorting by destination or priority;
- case-insensitive searching;
- saving through a temporary file before replacing the old file;
- tracking whether the in-memory log has unsaved changes;
- accepting an alternative path through a command-line argument;
- exporting a human-readable report in addition to the storage format.

## Self-review

- Is ownership of the dynamic array unambiguous?
- Can allocation-size multiplication overflow?
- Is the original pointer preserved when `realloc` fails?
- Does every error path close open files and free temporary storage?
- Can malformed input change the existing collection?
- Are strings always terminated and within capacity?
- Are internal helper functions declared `static`?
- Do headers expose only what other files need?
- Does the Makefile rebuild files when their headers change?
- Does the programme pass with warnings treated as errors?
- Does it run cleanly with AddressSanitizer and UndefinedBehaviorSanitizer?
