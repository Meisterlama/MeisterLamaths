#MeisterLamaths

This is my work in progress math library that I intend
to use for my personal and school projects.

***At this state this library is nowhere from usable 
   so I would recommend against using it***.

It's designed to be _header only_, _simple to use_, and oriented for
_game programming_. Hence, I'll firstly develop specialized structures,
trying to optimize as much as I can, and when I'll reach a state where
my library is usable, I _might_ extend it to a more general usage.

I'm using [GoogleTest](https://github.com/google/googletest) to ensure
the code I'm writing is correct, even if I find myself rewriting
major parts later on (That'll arrive for sure since I'm learning)

How to use
---

You simply have to download the `include` folder and add it to your
include directories. Then simply add the following line at the top of
the file where you need the lib features
```cpp
#include "MeisterLamaths.hpp"
```

The library's functionality is located inside the namespace `MeisterLamaths`\
Everything might not be functional in the latest commit,
but I try to always commit something compilable. If that
is not so, please look for a working one before.

Development State
---

Currently, nearly nothing is implemented, but in large, these features
will make it through :

- Vectors (2D, 3D)
- Matrices (3x3, 4x4)
- Quaternions
- 3D Geometry functions
- Random number generators

Some functions are straight up wrappers for functions from the standard
library (like `cos` or `sin`) for simplicity, but they _should_ change
for my own implementation later on.

How To Help
---

Since I am learning I do not want help by someone directly implementing features,
but you can always open an issue to point out errors or give out tips.
I'll read carefully and might correct it soon after.

License
---
See [LICENSE](https://github.com/Meisterlama/MeisterLamaths/blob/master/LICENSE)
