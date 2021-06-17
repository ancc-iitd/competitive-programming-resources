# Setting up Environment for Competitive Programming

## Installing g++ compiler

### Installing g++ on Windows using Cygwin
* Download and run cygwin [installer](https://cygwin.com/setup-x86_64.exe)
* Next > Next > Note down the path of this root directory (`C:\cygwin64`)
* Next > Next > Next > Select any mirror
* Next > Now select `View > Category`, Then find the package at `All>Devel>gcc-g++`, in the dropdown menu select the latest stable version (`10.2.0-1`)
* Next > Next > Finish
* Now open the powershell and enter command `setx PATH "$Env:PATH;C:\cygwin64\bin"`. If you are using old cmd prompt, enter command `setx PATH "%PATH%;C:\cygwin64\bin"`
* Now close the terminal window, and open it again, the path would be updated, try to run `g++ -v` It should work and show the gcc version and configuration settings

### Installing g++ on Ubuntu using apt
* Open the terminal (`Ctrl+Alt+T`)
* Enter command `g++ -v` to check if gcc is installed
* Enter command `$ sudo apt install build-essential`
* Type in `Y` whenever prompted
* Once the installation is over, type in `g++ -v` to verify if it is installed successfully.

### Installing g++ on Mac using Homebrew
* First open up the terminal by `Cmd+Space` then search for `Terminal.app` (it is a good idea to keep this in the dock). 
* Install homebrew package manager by entering command `/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"`
* Install g++-11 by command `brew install gcc`
* Run `g++-11 -v` to see if it has been installed correctly
* Enter command `where g++-11` and note down the path where brew has installed g++ version 11. `/opt/homebrew/bin/g++-11`
* Now note here that Mac comes with its own apple `clang++` compiler which is linked to `g++` command, so we should avoid using that.
* While using the zsh terminal, to make `g++` stand for the brew `g++-11`, we can create an alias. Enter command `echo "alias g++='/opt/homebrew/bin/g++-11';" >> ~/.zshrc`
* Note that this alias won't work on Sublime Text, so we will have to create a custom build script for it.

## Setting up Sublime Text 4
* Install the latest version of Sublime Text from their [website](https://www.sublimetext.com/)
* Follow Sublime Text's [doc](https://www.sublimetext.com/docs/command_line.html) to make sure you can launch `subl` command
* Launch the application, then click on `Preferences > Browse Packages...` then download the packages from [User.zip]() and put them in this folder
* Download [CP.zip]() and unzip it. Put this folder somewhere you can access frequently. We want to write and keep our codes here.
* Open this folder in sublime text, and open template.cpp, input.txt and output.txt.
* Click on `View > Groups > New Group` two times.
* Now feel free to drag and drop the files where you want them to be. Ideally, you would want to keep the .cpp file in the main left group, input.txt in the top right group and output.txt in bottom right group, like ![this]()
* If you are on Windows or Linux, select `Tools > Build System > gnu++17`. If you are on Mac, select `Tools > Build System > gnu++17_mac`. If your g++-11 path was different from `/opt/homebrew/bin/g++-11`, then change it accordingly in the User Preferences package of gnu++17_mac.sublime-build
* Now go back to your template.cpp, Click on `Build With...` and select the option with `Run`
* If it compiles well, it would show the execution time of the code (which should be negligible) and the total time it finished in (which includes the compilation time so it should be around 1 second). Next time, you can just use the shortcut `Ctrl+B` in windows/linux or `Cmd+B` in mac to build and run your code.

### Understanding the template.cpp
* `bits/stdc++.h` is a header which contains all the commonly used headers we need, like `iostream`, `algorithm` etc. This is for our convenience so we can write code without worrying if we have included the appropriate header for the function/template we are using. It is also provided in all online judges when you select the gcc compiler option. Note that it will not be present on `clang` or `vsc++` compiler by default.
* When headers are included with `"..."`, it searches first in the current folder, and then it searches in the globally configured include paths. When `<...>` is used, it searches in the globally configured include path only. You can verify this by running `g++ template.cpp -v` in the terminal and seeing the `#include <...> search starts here:` lines, and also `g++ template.cpp -H` to see which headers are actually being used. 
* Here we are using a little trick, we have created a file `bits/stdc++.h` in our current CP folder, and appending the main `bits/stdc++.h` file to it, so this way we can add custom lines which we want to execute only when running on our local setup, but not when it is submitted online.
* The other two headers are used to get fast implementation of Tree Data Structures.
* When we write `cout<<"Hello World"<<endl;`, the endl first adds a new line character and also makes sure that the output is immediately given to the stdout, but when we write `cout<<'Hello World\n";`, it sometimes reduces no of times it has to call the output function by storing the string with \n in a "buffer", and then outputting all the strings at once to the stdout when the program has finished. This is why, using \n can be more efficient when the checker just needs to send all the input cases at once see the final output file after the program has finished. But, in interactive problems (Usually the last few toughest in a contest), the next line of input depends on the output you gave, hence we need to use `endl`. Comment out this line if the problem is interactive. Read codeforces [Interactive Problems: Guide for Participants](https://codeforces.com/blog/entry/45307)
* An `int` data type in C++ can store numbers roughly from `-2*10^9` to `2*10^9`, this may seem large, but in some problems, the numbers we are handling exceed this, so we use `long long` data type, which can store roughly from `-9*10^18` to `9*10^18`. `#define` here works like Find-and-Replace, it will find `int` in your code and replace it with `long long`, so it is a quick fix. You can also try `using int=long long;` or `using ll=long long;`
* Namespaces are used to organize code into logical groups and to prevent name collisions that can occur especially when your code base includes multiple libraries. `std` namespace contains most of the functions we will be using, if we don't use this line, we will have to write `std::cout<<` to specify the namespace.
* `1000000007` is a prime number and many problems ask you to take modulo by this number, so it is handy to uncomment it when needed.
* `solve()` function is for convenience and making the code look cleaner, so that the main logic of your code for that problem resides in this function. **TL;DR: This is where you will be writing most of your solution.**
* `signed` data type is same as `int`, but it does not get affected if you use `#define` statements for `int`. The C++ compiler wants the `main()` function to be `int` only and not other data type like `long long`, otherwise it may give errors.
* The `ios` and `tie` lines are believed to speed up i/o and make it faster.
* The lines under this block will execute only if `LOCAL` is defined using `#define`, this is done so that these lines execute only on your computer and not on the online judge, note that some have `ONLINE_JUDGE` defined, but that is not reliable for all servers. We can define `LOCAL` above our code, or in the custom `bits/stdc++.h` file we made.
* `freopen` lines will open the `input.txt` and `output.txt` and assign them to `stdin` and `stdout`, so your program will read input from `input.txt`, and write the output to `output.txt`, this makes it convenient to take large test cases and also running against the same case many times without mistake by hand.
* We also have a timer, it will give a very accurate measurement of the execution time of your code, excluding the compilation time.
* Most problems require you to run your code `t` times. If the problem has only a single test case and so does not give `t`, you can comment out that line easily.

### Understanding the build system, and g++ flags
Our build system is in the `gnu++17.sublime-build` file from User.zip, read the syntax from Sublime's [documentation](https://www.sublimetext.com/docs/build_systems.html)

When Sublime Text executes shell commands, it does not follow the aliases, hence in mac, we had to give full path for the executable of `g++-11`.

A list of standard compiler flags can be found on the [ICPC Programming Environment](https://icpc.global/worldfinals/programming-environment) and [CodeChef](https://discuss.codechef.com/t/what-are-the-compiler-options-that-the-judge-uses/)
* `std=gnu++17` specifies the version of C++ we are using, and writing gnu++17 instead of c++17 includes some extensions offered by GNU standard.
* `O2` flag optimises your code, and basically removes unnecessary lines which are not used so they will not be executed at runtime.
* `Wall` is a flag which enables all warnings, so that you can write better code.
* `g` is a flag which allows you to use `gdb` debugger, which is a very powerful tool to debug your code. Check this [video](https://www.youtube.com/watch?v=svG6OPyKsrw) out to learn more about it.
* `o` sets the name of the executable file, it is `a.out` or `a.exe` by default.
* The command after `&&` is executed after the previous command runs succesfully.
* If interested, you can view all compiler options by running `g++ --help`, also if you are interested to know how code is compiled, then run `g++ template.cpp -save-temps`, it will show all the intermediate files. Basically, the `.ii` file contains the complete pre-processed source code which resolves all #define #include instructions, the `.s` file contains the actual machine CPU instructions in x86 or arm64 depending on architecture, the `.o` contains object code, and `.out` or `.exe` finally links all the codes and the libraries to give the final executable.

### Using snippets to write code fast
While coding, sometimes there are blocks of code we use frequently. To avoid having to write them by hand every time, we can create snippets to insert those lines of code quickly into our project.

Read the [documentation](https://docs.sublimetext.io/guide/extensibility/snippets.html) for syntax of snippets. In the User.zip, we have provided some `.sublime-snippet` files for example.

* To get the skeleton of the `template.cpp` file in a new code, rather than having to copy paste, just type in `cpp` and press `Tab` on keyboard, it will also take you to the `solve()` function body.
* To create a for loop for repeating `N` times, type in `rep`, then the initial variable, then tab, then initial value, then tab, then upper value, then tab. To leave them to default, just keep pressing `tab` and move on. You can write similar snippets for taking input or output of a vector or other data structures.
* A common `#define` is for replacing `pb` as `push_back` and `pii` as `pair<int,int>`, but using `#define` for everything like this is **not a good practice** especially in bigger projects, hence it is a better idea to create snippets for them.
* Sometimes, you encounter special algorithms which help in problems, to save custom functions for them and be able to access them quickly, create a snippet. For example, here typing in `fgcdi` and tab will give you a custom function to calculate gcd quickly. Check out this [CodeBook](https://github.com/NavneelSinghal/CodeBook) for more such ideas.

After practicing these keybindings, you will be able to use them very quickly. Do try to create more such snippets according to how you prefer to write code.
