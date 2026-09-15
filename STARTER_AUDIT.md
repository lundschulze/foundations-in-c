# Starter Separation Audit

This read-only editorial audit checks that exercise starters provide useful scaffolding without accidentally reproducing their completed answers.

## Scope

Reviewed against `main` at commit `72bee4e073dea2bfa0c9f886d956a8638f2a1104` on 13 September 2026:

- 21 chapter exercise starters from Chapters 2–22, each compared with its adjacent `answer.c`;
- two milestone `starter.c` files;
- the placeholder `main.c` supplied for the final milestone project;
- the corresponding exercise and milestone instructions.

All 24 starting files also receive strict C17 compile validation through the repository-wide test workflow.

## Review criteria

A suitable starter may contain:

- required headers, declarations and type definitions;
- representative input values or test fixtures;
- a calling function that makes the required interface clear;
- comments describing the next step;
- behaviour already introduced before the exercise begins.

A starter must not contain the completed central calculation, decision, loop, transformation, ownership operation, file operation or other behaviour that the exercise asks the learner to implement.

## Findings

No complete exercise solution was found in a starter.

- **Chapter 2:** the starter intentionally reproduces the preceding `Hello, world!` programme. The exercise asks the learner to add a second fixed line with `puts`; that second line is not present.
- **Chapters 3–13:** the starters provide headers, `main` and task comments while leaving the required variables, decisions, loops, functions, arrays, input handling and string logic unwritten.
- **Chapters 14–15:** the required type definitions or sample objects are supplied, but the record construction, traversal and inspection output remain for the learner.
- **Chapter 16:** the array and calling loop are supplied as a pointer-use harness; the complete `clamp` algorithm remains absent.
- **Chapter 17:** the writable string and call are supplied; the underscore-replacement loop remains absent.
- **Chapter 18:** only the initial ownership state is supplied; allocation, growth, failure handling and cleanup remain absent.
- **Chapter 19:** the function contract and test data are supplied; capacity validation and copying remain absent.
- **Chapters 20–22:** file operations, multi-file ownership work and output-channel behaviour remain absent.
- **Milestone projects:** all three starting points are compilable placeholders. They contain planning hints but no reference implementation or automated answer checker.

The larger structural overlap in a few later starters comes from deliberately supplied interfaces and harness code, not from completed solution bodies.

## Conclusion

The starter/answer separation is appropriate for the current companion repository. No source change is required.

Repeat this audit whenever an exercise starter, completed answer, exercise brief or corresponding manuscript instruction changes. An automated text-similarity threshold should not replace this review: small exercises can legitimately share substantial scaffolding while differing in the one function that constitutes the learning objective.
