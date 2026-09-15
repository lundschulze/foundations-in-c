# Milestone 02 — Guide Entry Catalogue

Build a menu-driven catalogue for a small collection of guide entries. Each entry describes a destination, records a rating and remembers whether the traveller has visited it.

This is an independent project. You receive requirements, acceptance scenarios and a compilable starting file, but no complete implementation or automated answer checker.

## Prerequisites

Complete Chapters 1–17 before starting. The project combines:

- loops, decisions and functions;
- fixed-size arrays;
- C strings and safe line input;
- structures and `typedef`;
- pointers used to inspect and modify entries.

Dynamic memory, file storage and multiple implementation files are not required.

## Data requirements

Store at most five entries. Each entry must contain:

- a destination name with room for 39 characters plus the terminating null character;
- a rating from 1 to 5;
- a visited value represented as true or false.

Keep the entries in a fixed-size array and track how many positions are currently used.

## Menu requirements

The programme must repeatedly offer these operations until the user chooses to quit:

1. Add an entry.
2. List all entries.
3. Find an entry by its exact destination name.
4. Mark an entry as visited.
5. Quit.

## Behaviour requirements

Your implementation must:

1. define one structure type for a guide entry;
2. use `fgets` for destination names and remove the newline safely;
3. reject an empty name or a name that does not fit;
4. validate the rating and menu selection;
5. refuse a sixth entry without writing beyond the array;
6. search only the initialised part of the array;
7. report when a requested destination is absent;
8. modify the stored entry—not a copy—when marking it as visited;
9. use at least one function that receives or returns a pointer to an entry;
10. print an understandable list containing name, rating and visited state.

The programme should return zero after the user quits normally and a non-zero value if input ends unexpectedly.

## Acceptance scenarios

Check these manually. The exact wording and layout are your design decision.

- Listing an empty catalogue reports that no entries exist.
- Adding `Earth` with rating 3 makes it appear as not visited.
- Searching for `Earth` finds that entry.
- Marking `Earth` as visited changes the value shown by the next list operation.
- Searching for `earth` does not find `Earth` unless you implement the optional case-insensitive extension.
- Adding a sixth entry is rejected and leaves the first five unchanged.
- Ratings 0 and 6 are rejected.
- An empty destination name is rejected.

## Suggested milestones

1. Define the entry type and the five-element array.
2. Display the menu repeatedly and implement quitting.
3. Add safe menu and rating input.
4. Add and list entries.
5. Write a search function.
6. Use the returned pointer to mark a stored entry as visited.
7. Handle full capacity and invalid names.
8. Work through every acceptance scenario.
9. Simplify repeated input and printing logic.

Compile after each milestone:

```bash
make
./guide-entry-catalogue
```

Remove the executable with:

```bash
make clean
```

## Starter

`starter.c` compiles and prints a reminder. Replace the placeholder behaviour with your own design. There is intentionally no `answer.c`.

## Optional extensions

After the required version works, consider:

- case-insensitive searching;
- preventing duplicate destination names;
- sorting entries by name or rating;
- changing or removing an existing entry;
- after Chapter 18, growing the catalogue dynamically;
- after Chapter 20, saving and loading the catalogue;
- after Chapter 21, separating the catalogue into several source files.

## Self-review

- Are all array accesses within the five valid positions?
- Is every string terminated correctly?
- Can an overlong input line affect the next prompt?
- Does the search function return a pointer to the stored entry?
- Is a missing entry handled without dereferencing a null pointer?
- Do functions that only inspect data use `const` where appropriate?
- Does marking an entry update the array itself?
- Does the programme compile without warnings?
- Can another reader understand each function's responsibility?
