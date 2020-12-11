# C++ for C Programmers Workshop

## Introduction

C++ (or as the original name indicated _C with Classes_) is a language
that was based originally on C's semantics and model.

### Objectives
 * As performant as C
 * Interoperable with C code
 * Safer
 * Ability to build better abstractions (with no extra cost)

## What's similar

 * Types (char, int, pointers, double, etc)
 * Able to access C's standard library - `#include <cmath>` is the
    equivalent of `#include <math.h>`
 * Can manage memory manually (pointers, allocation, etc.)

# New Things
## IO, the C++ way - Streams

Instead of:

```c
#include <stdio.h>

int main(void)
{
    printf("Mary had %d lambs\n", 6);
    return 0;
}
```

We can do:

```cpp
#include <iostream>

int main(void)
{
    std::cout << "Mary had " << 6 << "lambs\n";
    return 0;
}
```
### Advantages

 * Type safe (in C you might format with %d and pass a string in by
    mistake, and it will print the first 4 chars as a number)
 * You can chain all the printing together!

## Safer (and easier!) strings

The C++ string type is a string you can dinamically change and use with
many included functions.

```cpp
using namespace std;

string s = "Mary had a little ";

size_t len = string.length(); // 18

s.append("lamb."); // now s is the whole sentence!

string mary = s.substr(0, 4); // "Mary"
```

```cpp
using namespace std;

string s1 = "Jane";
string s2 = "John";
string s3 = "John";

int comp1 = s1.compare(s2); // -1 (less than)
int comp3 = s2.compare(s3); // 0 (equal)
int comp2 = s3.compare(s1); // 1 (more than)
```

# Object Oriented Programming

A useful way we can organize our programs is thinking, for each concern,
the data and the associated operations.

An abstraction for this purpose is objects:
 * Hide the data away
 * Only comunicate through messages (function calls)
 * (some other principles... but you can learn that later :D)

Let's see how we can use C++ (and classes) to do this.

## Example: vector (growing array of ints)

Example #1 - in C

 * See files c/vector.h c/main.c c/vector.c

Example #2 - with C++ classes

 * See files cpp/vector_class.h cpp/main.cpp

Example #3 - using the standard library

 * See file cpp/main2.cpp

# Some (more) C++ Concepts

## Namespaces

We previously saw `std::cout` and `std::string`. What is that std::
thing?

**Example:**

Library 1 is a map navigation library. It defines maps as
a graph: `struct graph`.

Library 2 is a drawing and charting library. It can draw
a graph diagram: `struct graph`.


**How can we use both?**

Library 1 defines `namespace lib1{/*...*/}`.

Library 2 defines `namespace lib2{/*...*/}`.

We can now use both `lib1::graph` and `lib2::graph`.

If we only use one library we can say `using namespace lib` and omit
the specifier.

## RAII (Resource Aquisition is Initialization)

C++ objects feature constructors (function run when we make the object)
and destructors (function run when the object goes out of scope).

Uses:
 * File objects can close the OS's file handle when we stop using them
 * We can make smart pointers and arrays that free their memory by
    themselves, and avoid both manually freeing memory and using a GC

# The Standard Library - Overview
## Container Templates

No need to reinvent the standard data structures!

 * Fixed-size array -> array
 * Dynamic array -> vector
 * Linked lists -> list and forward_list
 * Queues -> stack, queue and deque
 * Heap -> priority_queue
 * Search trees -> set and map
 * Hash tables -> unordered_set and unordered_map

# Challenge: shopping cart

Let's build a shopping cart!

# Even more concepts!

## Templates

Often we build structures and fuctions whose code is the same for any
type (e.g. the vector we built before). If we don't mind the overhead,
we can shuffle superclass or void pointers around, but for maximum
performance we need to implement the structure for each type.

In C you could use macros (dirty work!), but in C++ we have templates.
We write the code for a generic type _T_ as a template, and then we
can instantiate it for the type we are using (the compiler generates
the code by itself!).

Remember that we used the standard library vector? We declared
`std::vector<int>`, because the standard library is based on
templates (STL = Standard Template Library), and we wanted an
`int` vector.

# Example: vector using templates

See files cpp/vector_template.h and main_template.cpp

## Exceptions

In every domain we need to account for errors or other abnormal states
of execution. In C we mostly use the return code of a fuction to
indicate errors, e.g., returning a null pointer if we could not create
an object, or using 0 as OK and -1 as error.

One other way C++ allows us to handle errors is to use exceptions.

## More stuff from the standard library
### <algorithm>

As long as you are using standard containers, many algorithms
are already implemented!

 * find and binary_search
 * copy
 * replace
 * random_shuffle
 * sort
 * many more!

### A lot more!

 * chrono -> time related stuff
 * thread, mutex -> for multiprocessing
 * utility -> some random stuff like swapping variables, pairs, etc.
 * regex -> regular expressions to match strings and patterns
