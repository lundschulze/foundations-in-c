# Milestone 01 — Journey Cost Planner

Build a small command-line programme that calculates a journey quote. This is an independent project: the repository supplies requirements and a starting file, but not a complete solution or an automated answer checker.

## Prerequisites

Complete Chapters 1–10 before starting. The project can be solved with values, variables, formatted input and output, decisions, loops and functions. Arrays, string manipulation, pointers and dynamic memory are not required.

## Journey rules

The traveller selects one destination zone:

| Zone | Description | Fare per traveller |
| --- | --- | ---: |
| 1 | Nearby system | 120 credits |
| 2 | Outer system | 250 credits |
| 3 | Remote system | 420 credits |

The programme also asks for:

- the number of travellers, from 1 to 8;
- the total number of bags, from 0 to 12.

One bag per traveller is included. Each additional bag costs 35 credits.

The final quote is:

```text
traveller fares + additional-bag charge
```

## Requirements

Your programme must:

1. display the three destination zones and their fares;
2. read the zone, traveller count and bag count;
3. reject input that is not an integer;
4. reject values outside the stated ranges;
5. use at least one loop to give the user another attempt after invalid input;
6. use separate functions for zone fare, validation and the additional-bag calculation;
7. print a clear summary containing the selected zone, travellers, bags and total quote;
8. return zero after a successful quote.

Keep the functions small and initialise variables when they are declared.

## Acceptance examples

These are calculations to check manually, not prescribed output formatting.

- Zone 1, one traveller and no bags: 120 credits.
- Zone 2, three travellers and three bags: 750 credits.
- Zone 2, three travellers and five bags: 820 credits.
- Zone 3, eight travellers and twelve bags: 3,500 credits.
- Zone 0, nine travellers or thirteen bags must be rejected.

## Suggested milestones

1. Print the title and zone menu.
2. Read and validate one integer.
3. Validate all three selections.
4. Return the correct fare for each zone from a function.
5. Calculate included and additional bags.
6. Calculate and print the complete quote.
7. Try every acceptance example.
8. Re-read the programme and simplify repeated logic.

Compile frequently rather than writing the entire programme before the first build.

## Build and run

The starter initially prints a reminder and compiles cleanly. Replace its placeholder behaviour with your own programme:

```bash
make
./journey-cost-planner
```

Remove the executable afterwards with:

```bash
make clean
```

## Optional extensions

After the required version works, you may add one or more of these:

- allow several quotes in one run;
- add a ten-per-cent group discount for six or more travellers;
- add a priority-departure surcharge;
- after Chapter 13, replace numeric zones with destination names;
- after Chapter 20, save the final quote to a text file.

Treat extensions as separate changes. Keep the required version working while adding them.

## Self-review

- Can every invalid value be corrected without restarting the programme?
- Does each function have one clear responsibility?
- Are the range limits visible and easy to change?
- Is the additional-bag rule correct when bags equal travellers?
- Have you tested the lowest and highest accepted values?
- Does the programme compile without warnings?
- Could another reader understand the output without seeing the source code?
