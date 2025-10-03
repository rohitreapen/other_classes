# Course plan for Introduction to C++ (32 hours)

1. Class 1 - Installing an environment for C++ and C++ mental model (2 h)
    - Installing and configuring a C++ environment using MSYS2 and VS Code
    - C++ compilation steps
    - Standard Template Library (STL)

2. Types, declarations and initialization (2 h)
3. Functions and lambdas (2 h)
4. Classes - fundamentals (2 h)
5. Move semantics and RAII (2 h)
6. Memory and smart pointers (2 h)
7. STL Containers and sequences (2 h)
8. STL Containers II --- Associative/Unordered** *(2 h)*\
    Topics: `std::map/set`, `std::multimap/multiset`;
    `std::unordered_map/set`; custom comparator/hash; iterator usage.

9.  **Algorithms I --- Core Patterns** *(2 h)*\
    Topics: non-modifying (e.g., `find`, `count`), modifying (`copy`,
    `remove`), sorting (`sort`, `stable_sort`), numeric (`accumulate`);
    functors vs lambdas; erase--remove idiom.

10. **Algorithms II --- Iterators & Idioms** *(2 h)*\
    Topics: iterator categories; partitioning and selection;
    `transform`; `iota`; composing algorithm pipelines (C++11
    techniques); performance notes.

11. **I/O Streams & Formatting** *(2 h)*\
    Topics: `iostream` model; state bits/exceptions; `iomanip`
    formatting; file I/O (`fstream`, binary vs text); `stringstream`;
    locales (overview).

12. **Templates I --- Fundamentals** *(2 h)*\
    Topics: function/class templates; template parameters (type &
    non-type); deduction; alias templates; **type traits** overview;
    `constexpr` functions (C++11).

13. **Templates II --- Specialization & Techniques** *(2 h)*\
    Topics: full/partial specialization; templates + inheritance; CRTP
    mention; **SFINAE** basics with `std::enable_if`; compile-time
    computations (intro).

14. **Error Handling** *(2 h)*\
    Topics: exceptions (`throw/try/catch`); `noexcept`; exception safety
    levels (basic/strong/nothrow); assertions; documenting error
    contracts.

15. **Standard Libraries: Utilities** *(2 h)*\
    Topics: `<chrono>` (durations, time points), `<random>` (engines,
    distributions), `<regex>` (basics); `std::pair/tuple`;
    `std::bitset`; `<functional>` (`bind`, `ref`).

16. **Concurrency (C++11) & Consolidation** *(2 h)*\
    Topics: `std::thread`, `mutex`, `lock_guard`/`unique_lock`,
    `condition_variable`; futures/`async`/promises; atomics (overview);
    brief code review & integration of course idioms.

**Total:** 16 sessions × 2 hours = **32 hours**.

> Notes:\
> • All examples and practices target **C++11** as presented in the
> textbook.\
> • Prefer STL containers/algorithms, RAII, move semantics, and standard
> C++11 concurrency; avoid later standards' features (e.g., ranges,
> concepts, filesystem, format).
