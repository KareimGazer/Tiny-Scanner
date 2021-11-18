# Tiny-Scanner
The Scanner part of a compiler for the Tiny Language

# Abstract
Scanners represent the first stage in compilation, where the parser gets tokens from a
stream of characters.
In this paper, we represent an implementation of a scanner of the Tiny language based on
the description mentioned in the reference “Compiler Construction Principles and Practice”.
We exceed basic implementation by handling Error detection, text Buffers, end of file (EOF),
and reserved lookups

# Features
- Output was compared to match exactly that of the reference.
- Errors are detected.
- points to the last character before the error.
- description of the tokens line by line.
- tested with all given examples in addition to the reference example in fig 2.11
