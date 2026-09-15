# Chapter 11 — Scope, lifetime and storage

Companion code and exercises for Chapter 11 of *Foundations in C*.

## Material

- [Block scope](examples/block-scope/) — observe where names from nested blocks are available
- [Remembered calls](examples/remembered-calls/) — retain local state between function calls with `static`
- [Two counters](exercises/two-counters/) — compare automatic and static local objects directly

The examples keep scope—the region where a name can be used—separate from storage duration—the lifetime of the object it names.

