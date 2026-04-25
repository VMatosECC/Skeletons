# Skeletons
- Starting templates for CS1 and CS2 laboratory experiences.

- The example adds a reusable C++ class skeleton covering the canonical set of members expected in CS1/CS2 coursework.

## Files
- `CPPClassSkeleton.h` — class declaration
- `CPPClassSkeleton.cpp` — method definitions

## Structure

| Section | Detail |
|---|---|
| Private members | `int`, `double`, `string` |
| Mutators / Accessors | Inline setters and `const` getters |
| Constructor | All parameters defaulted (`= 0`, `= 0.0`, `= ""`, `={}`) |
| Copy constructor | Explicit deep-copy |
| Assignment operator | Self-assignment guard, returns `*this` |
| `toString` | Builds output via `stringstream`, returns `string` |
| `operator<<` | `friend`; delegates to `toString` |

## Example usage
```cpp
ClassName a;                          // default constructor
ClassName b(42, 3.14, "hello");       // parameterised constructor
ClassName c(b);                       // copy constructor
a = b;                                // assignment
cout << b << "\n";                    // operator<< → toString
// memberInt: 42, memberDouble: 3.14, memberString: hello
```

<!-- START COPILOT CODING AGENT SUFFIX -->



<!-- START COPILOT ORIGINAL PROMPT -->



<details>



</details>

