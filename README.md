```markdown
# Triangle Tree Exercise

This repository contains an exercise related to a triangle tree. The project structure includes source code, tests, and a Makefile for easy compilation and testing.

## Project Structure

The project is organized as follows:

- **src:** Contains the source code files for the triangle tree exercise.
- **tests:** Holds the test files to validate the correctness of the triangle tree implementation.
- **Makefile:** Defines compilation rules and targets to build the `tri_triangle` binary and run tests.

## Build

To build the `tri_triangle` binary, simply run:

```bash
make
```

This will compile the source code in the `src` directory and generate the executable `tri_triangle`.

## Run

You can run the `tri_triangle` binary on the input files provided in the repository. Two input files, `sum1.txt` and `triangle.txt`, represent different parts of the exercise.

```bash
./tri_triangle sum1.txt
```

Or, to run the binary with the contents of `triangle.txt`:

```bash
./tri_triangle triangle.txt
```

## Tests

To compile and run the tests, use the following command:

```bash
make test
```

This will compile the test files in the `tests` directory and execute them, providing feedback on the correctness of the implemented functionality.

## Files

- **sum1.txt:** Contains data relevant to part 1 of the exercise.
- **triangle.txt:** Contains data relevant to part 2 of the exercise.

Feel free to explore the code in the `src` and `tests` directories to understand the implementation details of the triangle tree exercise.

```
