
# Course Plan (32 hours)

1. Class 1 - Installing an environment for C++ and C++ mental model (2 h)
    - Installing and configuring a C++ environment using MSYS2 and VS Code
    - C++ compilation steps
    - Standard Template Library (STL)

2. Class 2 - Types, initialization, references, `const`, copy and move (2 h)

3. Class 3 - Functions and lambdas (2 h)
    - overloading
    - default parameters
    - pass-by-value and pass-by-reference
    - lambdas

4. Class 4 - Classes and objects (2 h)

5. Class 5 - RAII and smart pointers (2 h)
    Topics: Resource ownership; `unique_ptr`, `shared_ptr`, `weak_ptr`;
    move-only types; exception safety (basic/strong).\
    Outcome: Refactor raw resource handling to RAII with well-defined
    ownership.

6.  **Class 6 --- STL Containers I (Sequences)** *(2 h)*\
    Topics: `vector`, `string`, `deque`, `list`; iteration patterns;
    iterator basics; complexity and locality considerations.\
    Outcome: Informed container selection for sequential data.

7.  **Class 7 --- STL Containers II (Associative/Unordered)** *(2 h)*\
    Topics: `map/set`, `unordered_map/unordered_set`; custom
    comparators/hash; overview of heterogeneous lookup.\
    Outcome: Effective key--value and set operations with correct
    performance expectations.

8.  **Class 8 --- Algorithms & C++20 Ranges** *(2 h)*\
    Topics: Core algorithms (`sort`, `find`, `transform`, `accumulate`);
    iterator categories; ranges pipelines
    (`views::filter|transform|take`); projections.\
    Outcome: Replacing loops with readable, efficient algorithm/ranges
    code.

9.  **Class 9 --- I/O, Formatting, and Filesystem** *(2 h)*\
    Topics: Stream I/O patterns; robust file handling; `std::filesystem`
    paths and directory traversal; note on `std::format` availability.\
    Outcome: Reliable file/directory processing utilities.

10. **Class 10 --- Templates I (Fundamentals)** *(2 h)*\
    Topics: Function/class templates; deduction; traits and simple
    metafunctions; `constexpr` basics.\
    Outcome: Authoring basic generic code with light metaprogramming.

11. **Class 11 --- Templates II (Concepts & Forwarding)** *(2 h)*\
    Topics: `requires` clauses; standard concepts; constraining
    templates; perfect forwarding and reference qualifiers (overview).\
    Outcome: Readable constraints in place of SFINAE; correct forwarding
    patterns.

12. **Class 12 --- Error Handling Models** *(2 h)*\
    Topics: Exceptions vs status returns; `std::optional`,
    `std::variant` (and error aggregation patterns); documenting error
    contracts.\
    Outcome: Consistent error-handling strategy per API.

13. **Class 13 --- Concurrency Basics** *(2 h)*\
    Topics: `std::thread`, `mutex`, `lock_guard`, `condition_variable`;
    producer--consumer; basic performance and race-avoidance notes.\
    Outcome: Correctly synchronized minimal concurrent workflow.

14. **Class 14 --- Tooling for Quality** *(2 h)*\
    Topics: CMake targets and options; compiler warnings configuration;
    sanitizers (ASan/UBSan on GCC/Clang); static analysis (`clang-tidy`,
    cppcheck); debugging workflow.\
    Outcome: Ability to detect and diagnose undefined behavior and
    common defects.

15. **Class 15 --- Design & Idioms in Modern C++** *(2 h)*\
    Topics: Composition over inheritance; NVI (non-virtual interface);
    type erasure with `std::function`; `std::variant` + visitor for
    alternatives.\
    Outcome: Modern design choices that reduce coupling and improve
    clarity.

16. **Class 16 --- Consolidation & Advanced STL/Ranges Clinic** *(2
    h)*\
    Topics: Integrative refactoring of prior exercises; advanced ranges
    patterns; performance/complexity audit; Q&A and code review
    checklist.\
    Outcome: Consolidated mastery of course idioms; readiness for
    independent project work.

**Total:** 16 Classs × 2 hours = **32 hours**.
