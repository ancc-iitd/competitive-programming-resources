# Understanding the template
* `bits/stdc++.h` is a header which contains all the commonly used headers we need, like `iostream`, `algorithm` etc. This is for our convenience so we can write code without worrying if we have included the appropriate header for the function/template we are using. It is also provided in all online judges when you select the gcc compiler option. Note that it will not be present on `clang` or `vsc++` compiler by default.
* Namespaces are used to organize code into logical groups and to prevent name collisions that can occur especially when your code base includes multiple libraries. `std` namespace contains most of the functions we will be using, if we don't use this line, we will have to write `std::cout<<` to specify the namespace.
* The line `cin.tie(nullptr)->sync_with_stdio(false);` ties the `std::cin` stream with the `nullptr` (and hence input becomes faster, since it doesn't need to care about the relative ordering of
  input and output; for more information, have a look at [this](https://codeforces.com/blog/entry/90775)), and then turns off the sync of input and output streams with `stdio` which makes them even
  faster.
* `solve()` function is for convenience and making the code look cleaner, so that the main logic of your code for that problem resides in this function. **TL;DR: This is where you will be writing most of your solution.**
* The lines under this block will execute only if `LOCAL` is defined using `#define`, this is done so that these lines execute only on your computer and not on the online judge, note that some have `ONLINE_JUDGE` defined, but that is not reliable for all websites. Note that using the compiler flag `-DLOCAL`, we can get this behaviour.
* `freopen` lines will open the `input.txt` and `output.txt` from the current folder and assign them to `stdin` and `stdout`, so your program will read input from `input.txt`, and write the output to `output.txt`, this makes it convenient to take large test cases and also running against the same case many times without mistake by hand.
* We also have a timer, it will give a very accurate measurement of the execution time of your code, excluding the compilation time.
* Some problems require you to run your code `t` times. If the problem has only a single test case and so does not give `t`, you can comment out that line easily.

