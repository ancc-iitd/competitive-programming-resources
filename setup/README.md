# Setting up an environment for Competitive Programming

#### [Installing the g++ compiler](#installing-g-compiler)
##### * [Installing g++ on Windows using Cygwin](#installing-g-on-windows-using-cygwin)
##### * [Installing g++ on Ubuntu using apt](#installing-g-on-ubuntu-using-apt)
##### * [Installing g++ on Mac using Homebrew](#installing-g-on-mac-using-homebrew)
##### * [Compiling code with g++](#compiling-code-with-g)
#### [Setting up a text editor](#setting-up-a-text-editor)

## Installing g++ compiler

### Installing g++ on Windows using Cygwin
* Download and run [cygwin installer](https://cygwin.com/setup-x86_64.exe)
* Next > Next > Note down the path of this root directory (`C:\cygwin64`)
* Next > Next > Next > Select any mirror
* Next > Now select `View > Category`, Then find the package at `All > Devel > gcc-g++`, and in the dropdown menu select the latest stable version (depends on when you are installing this).
* Next > Next > Finish
* Now open the powershell and enter command `setx PATH "$Env:PATH;C:\cygwin64\bin"`. If you are using old cmd prompt, enter command `setx PATH "%PATH%;C:\cygwin64\bin"`
* Now close the terminal window, and open it again, the path would be updated, try to run `g++ -v` It should work and show the gcc version and configuration settings

### Installing g++ on Ubuntu using apt
* Open the terminal (`Ctrl+Alt+T`)
* Enter command `g++ -v` to check if gcc is installed
* Enter command `$ sudo apt install g++`
* Type in `Y` whenever prompted
* Once the installation is over, type in `g++ -v` to verify if it is installed successfully.

### Installing g++ on Mac using Homebrew
* First open up the terminal by `Cmd+Space` then search for `Terminal.app` (it is a good idea to keep this in the dock). 
* Install homebrew package manager by entering command `/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"`
* Install g++-11 by command `brew install gcc` (as of writing, `g++-11` is the latest version of `g++`, and it might change in the future).
* Run `g++-11 -v` to see if it has been installed correctly
* Enter command `where g++-11` and note down the path where brew has installed g++ version 11. It should be something similar to `/opt/homebrew/bin/g++-11`, but it might vary.
* Now note here that Mac comes with its own apple `clang++` compiler which is linked to `g++` command, so we should avoid using that.
* While using the zsh terminal, to make `g++` stand for the brew `g++-11`, we can create an alias. Enter command `echo "alias g++='/opt/homebrew/bin/g++-11';" >> ~/.zshrc`
* If you're using the bash terminal instead, you would need to run this instead of the above: `echo "alias g++='/opt/homebrew/bin/g++-11';" >> ~/.bashrc`
* Note that this alias won't work on Sublime Text, so we will have to create a custom build script for it.
* Note that if `bits/stdc++.h` doesn't work, you should consider looking at [this blog on Codeforces](https://codeforces.com/blog/entry/70957).

### Compiling code with g++
For C++, your `.cpp` file is compiled to an executable before it can be executed. For Windows, the extension is `.exe`, and for Linux/Mac it can be empty or `.out`.

To compile your code in the simplest way possible, the command `g++ <file>.cpp` works, and gives you an executable called `a.out`. For compiling to a specific executable, `g++ -o <executable-name>
<file>.cpp` works. Here `-o` is a compiler flag that tells us where the output of the compiler (i.e., the executable) needs to go.

A list of standard compiler flags can be found on the [ICPC Programming Environment](https://icpc.global/worldfinals/programming-environment) and [CodeChef](https://discuss.codechef.com/t/what-are-the-compiler-options-that-the-judge-uses/)
* `-std=...` specifies the version of C++ we are using, and we will use `std=c++17` for the latest standard whose features can be used and successfully compiled in `g++` at the time of writing.
* `-O2` flag is an optimizing flag, and is usually used on most competitive programming websites.
* `-Wall` is a flag which enables all warnings, so that you can write better code.
* `-g` is a flag which allows you to use `gdb` debugger, which is a very powerful tool to debug your code. Check this [video](https://www.youtube.com/watch?v=svG6OPyKsrw) out to learn more about it.
* `-o` sets the name of the executable file, it is `a.out` or `a.exe` if not specified.

## Setting up a text editor

For this, please navigate to one of the directories for more information about how to set up the text editors.
