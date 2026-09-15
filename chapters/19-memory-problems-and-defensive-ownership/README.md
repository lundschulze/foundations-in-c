# Chapter 19 — Memory problems and defensive ownership

This chapter turns pointer safety into four explicit questions: target, lifetime, boundary and ownership.

## Examples

- [`owned-buffer`](examples/owned-buffer) — give an allocation one owner and leave it harmless after destruction.
- [`checked-copy`](examples/checked-copy) — preserve a destination when its capacity is insufficient.

## Exercise

- [`checked-copier`](exercises/checked-copier) — copy `double` elements under an explicit capacity contract.
