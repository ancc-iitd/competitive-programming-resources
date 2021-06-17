## Setting up Sublime Text 4
* Install the latest version of [Sublime Text](https://www.sublimetext.com/).
* Follow Sublime Text's [doc](https://www.sublimetext.com/docs/command_line.html) to make sure you can launch `subl` command.
* Launch the application, then click on `Preferences > Browse Packages...` then download the packages from this directory and put them in this folder.
* Create folder somewhere you can access frequently. **We want to write and keep our codes here.**
* Open this folder in Sublime Text, and create/open files `template.cpp`, `input.txt` and `output.txt`.
* Click on `View > Groups > New Group` two times.
* Now feel free to drag and drop the files where you want them to be. Ideally, you would want to keep the `.cpp file` in the main left group, `input.txt` in the top right group and `output.txt` in bottom right group.
* If you are on Windows or Linux, select `Tools > Build System > c++17`. If you are on Mac, select `Tools > Build System > c++17_mac`. If your g++-11 path was different from `/opt/homebrew/bin/g++-11`, then change it accordingly in the User Preferences package of `c++17_mac.sublime-build`
* Now go back to your `template.cpp`, Click on `Build With...` and select the option with `Run`
* If it compiles well, it would show the execution time of the code (which should be negligible) and the total time it finished in (which includes the compilation time so it should be around 1 second). Next time, you can just use the shortcut `Ctrl+B` in windows/linux or `Cmd+B` in mac to build and run your code.

### Understanding the build system
Our build system is in the `c++17.sublime-build` file in this directory, read the syntax from Sublime's [documentation](https://www.sublimetext.com/docs/build_systems.html)

When Sublime Text executes shell commands, it does not follow the aliases, hence in mac, we had to give full path for the executable of `g++-11`.

### Using snippets to write code fast
While coding, sometimes there are blocks of code we use frequently. To avoid having to write them by hand every time, we can create snippets to insert those lines of code quickly into our project.

Read the [documentation](https://docs.sublimetext.io/guide/extensibility/snippets.html) for syntax of snippets. In the [User](https://github.com/ancc-iitd/competitive-programming-resources/tree/main/setup/User) folder, we have provided some `.sublime-snippet` files for example.

* To get the skeleton of the `template.cpp` file in a new code, rather than having to copy paste, just type in `cpp` and press `Tab` on keyboard, it will also take you to the `solve()` function body.
* To create a for loop for repeating `N` times, type in `rep`, then the initial variable, then tab, then initial value, then tab, then upper value, then tab. To leave them to default, just keep pressing `tab` and move on. You can write similar snippets for taking input or output of a vector or other data structures.
* A common `#define` is for replacing `pb` as `push_back` and `pii` as `pair<int,int>`, but using `#define` for everything like this is **not a good practice** especially in bigger projects, hence it is a better idea to create snippets for them.
* Sometimes, you encounter special algorithms which help in problems, to save custom functions for them and be able to access them quickly, create a snippet. For example, here typing in `fgcdi` and tab will give you a custom function to calculate gcd quickly. Check out this [CodeBook](https://github.com/NavneelSinghal/CodeBook) for more such ideas.

After practicing these keybindings, you will be able to use them very quickly. Do try to create more such snippets according to how you prefer to write code.
