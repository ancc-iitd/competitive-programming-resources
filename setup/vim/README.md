## Table of Contents

#### [About Vim](#about)
#### [Installing Vim](#installing)
##### [On Windows](#windows)
##### [On Ubuntu/Debian-based Linux distros (using `apt-get`)](#debian)
##### [On Arch-based Linux distros (using `pacman`)](#arch)
##### [On Mac](#mac)
#### [Basic Vim Commands](#commands)
#### [Configuring Vim with a `vimrc`](#vimrc)
#### [Adding plugins to Vim](#plugins)
#### [Recommended plugins](#recommended)
#### [An example of a workflow in Vim](#workflow)
##### [On Linux/MacOS](#linux-workflow)
##### [On Windows](#windows-workflow)

## <a name="about"></a>About Vim

According to the [official website](https://www.vim.org/about.php),

> Vim is a highly configurable text editor built to enable efficient text editing. It is an improved version of the vi editor distributed with most UNIX systems.

> Vim is often called a "programmer's editor," and so useful for programming that many consider it an entire IDE. It's not just for programmers, though. Vim is perfect for all kinds of text editing, from composing email to editing configuration files.

Many competitive programmers use Vim as their primary text editor, and take advantage of its highly configurable nature to do things that other "IDE"s would find really hard to do otherwise.
What's more, the dual-mode nature of editing makes it much more intuitive and faster to write code in it, and you can do everything using keybindings which will make it possible to edit documents
in the most complicated of ways at typing speed.

Vim has both terminal and GUI versions (Vim and gVim respectively). The following instructions will install the terminal versions except in Windows. You can install gVim instead too, but for
the sake of simplicity, we will give installation instructions for Vim.

## <a name="installing"></a> Installing Vim

The [official website](https://www.vim.org/download.php) offers many options to download Vim. We outline some of the more popular ways to install Vim.

### <a name="windows"></a> On Windows

* Go to [this website](https://www.vim.org/download.php#pc) and click on `gvim82.exe` (might be different if you are reading this in the future) and follow the instructions on the screen. Note that
  on Windows, this will install gVim, which is a GUI application for Vim.

### <a name="debian"></a> On Ubuntu/Debian-based Linux distros (using `apt-get`)

* In a terminal, run the command `sudo apt-get install vim`, and select `Y` at each prompt. To check whether `vim` has been installed, run the command `vim --version`.
* To install gVim instead, run the command `sudo apt-get install vim-gtk3` instead.

### <a name="arch"></a> On Arch-based Linux distros (using `pacman`)

* In a terminal, run the command `sudo pacman -Syu vim`, and follow the usual instructions. To check whether `vim` has been installed, run the command `vim --version`.
* To install gVim instead, run the command `sudo pacman -Syu vim` and `sudo pacman -Syu gvim`.

### <a name="mac"></a> On Mac

* Assuming you have Homebrew installed (if not, run the command `/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"` in your terminal), run the
  command `brew install vim` on the terminal and follow the instructions (if any). To check whether `vim` has been installed, run the command `vim --version` on your terminal.
* To install MacVim (the gVim port for MacOS) instead, assuming you have Homebrew installed, run `brew install vim && brew install macvim` and then `brew link macvim`. To run MacVim, you can run
  `mvim` in the terminal.

## <a name="commands"></a> Basic Vim commands

* Running `vim` on the terminal (for Linux and Mac) starts Vim. For gVim, there should be an application that you can open like a usual GUI application.
* Typing `:q!<Enter>` exits Vim.
* To get help when you are in vim, `:help` works, and in the terminal, `vim --help` works.
* For learning more commands in a hands-on fashion, `vimtutor` is an awesome resource you should definitely consider going through. It is an interactive application that teaches you how to work with Vim using activities in the
  application itself. To run it in the terminal, run `vimtutor`. For Windows, you need to go the directory where gVim was installed, and search for an executable called `vimtutor` and run it.
* For more commands, [this website](https://vim.fandom.com/wiki/Vim_Tips_Wiki) is a pretty good resource, and here;s a [Vim FAQ](https://vimhelp.org/vim_faq.txt.html).

## <a name="vimrc"></a> Configuring Vim with a `vimrc`

Coming to the configuration part, you can read more about it in the above links. We have included a `vimrc` in this directory, which is a minimal Vim configuration file. To use it, if you're not
on Windows, you need to copy it to your home folder and rename it to `.vimrc`, and for Windows, you need to copy it to your user folder (`C:/Users/<username>`) and rename it to `_vimrc` or `_gvimrc`.

A brief explanation of what it does is as follows:
* `set nocp` or `set nocompatible` sets the mode to not compatible, and is needed to use Vim features as opposed to vi features.
* `set ai` or `set autoindent` switches on autoindent
* `set si` or `set smartindent` switches on smartindent
* `set ts=N` or `set tabstop=N` sets the tabstop to N (where N is an integer) (this and the following three are needed to render tab widths correctly, the default N = 8 is a bit too much for most
  people).
* `set sts=N` or `set softtabstop=N` sets the soft tabstop to N (where N is an integer)
* `set sw=N` or `set shiftwidth=N` sets the shift width to N (where N is an integer)
* `set et` expands the tabs (needed if you want to use indentation to be in terms of spaces instead of tabs)
* `set history=N` remembers your last N commands in command-mode
* `set bg=dark` sets the background to dark (needed for dark mode)
* `set enc=utf8` sets the file encoding to UTF-8
* `set ch=N` or `set cmdheight=N` sets the commandline window height to N
* `set cb=...` or `set clipboard=...` sets the clipboards (if you want to copy or paste from default clipboards, you need to run `"+y` and `"+p` in visual mode).
* `set ffs=...` or `set fileformats=...` sets the global file formats (to render endlines in files generated in different OSes correctly)
* `set bs=...` or `set backspace=...` defines the behaviour for the backspace key
* `syntax on` turns on syntax highlighting for Vim
* `filetype plugin indent on` turns on filetype detection, plugins, and autoindent
* `inoremap <something> <something else>` expands `<something>` to `<something else>` non-recursively (for the recursive variant, use `map` instead). Hence the three lines correspond to
  autocompletion of brackets, and the next two lines correspond to remapping space in normal mode for searching, and similarly for searching in reverse order
* The next few lines define the display properties for certain terminals and gVim
* `packadd termdebug` adds `gdb` support to Vim, so that you can debug using `gdb` in Vim itself without having to go to the terminal

## <a name="plugins"></a> Adding plugins to Vim

For adding plugins to Vim, consider using package managers like `Vundle`, `Pathogen` and `vim-plug`. Some installation instructions can be found [here](https://opensource.com/article/20/2/how-install-vim-plugins).

## <a name="recommended"></a> Recommended plugins

* [UltiSnips](https://github.com/SirVer/ultisnips) - This is a plugin for handling snippets in Vim.
* [coc.nvim](https://github.com/neoclide/coc.nvim) - This is a useful autocomplete plugin.
* [NerdCommenter](https://github.com/preservim/nerdcommenter) - This is a plugin for commenting code in a much faster way than usual.
* [GruvBox](https://github.com/morhetz/gruvbox) - This is a plugin for the gruvbox colorscheme in Vim.
* [ClangFormat](https://github.com/rhysd/vim-clang-format) - This is a plugin for autoformatting code in a single keystroke using ClangFormat (needs `clang-format` to be installed on the system).

## <a name="workflow"></a> An example of a workflow in Vim

Note that in command mode, you can run commands in Vim. What follows is how you can automate compilation and executing your code inside Vim (if you don't want to exit Vim to use the terminal).

### <a name="linux-worflow"></a> On Linux/MacOS

The command for compiling the file `a.cpp` into an executable with a name `a` is `g++ -o a a.cpp`. More about compilation is in the top-level README in the `setup` directory.

To execute this from within Vim, you can type `:g++ -o a a.cpp` in normal mode to compile the file (the `:` takes you to command mode and when you hit `<Enter>` it runs the command). Similarly, to run the executable `a`, you can type `:./a` and it will run in command mode.

It is usually a good idea to use a Makefile or some other automated build system than to write out all these commands explicitly. To use the Makefile provided in this directory, you first need to install `make` (using `sudo apt install make` on Ubuntu/Debian-based Linux distros, `sudo pacman -Syu make` on Arch-based Linux distros, or `brew install make` on MacOS), copy the Makefile to the current working directory, and then run `:make <file>` in command mode if your filename is `<file>.cpp`. This will compile your file with the `NORMAL_FLAGS` in the Makefile.

To compile in a paranoid debug mode, run `:make <file> D=1` instead, and it will turn on a lot of warnings while compiling (more specifically, it will compile using `PEDANTIC_FLAGS`), and when your program crashes, it'll give you some useful information rather than just a segmentation fault. You can potentially use `gdb` to debug the code as well if you want to.

To optionally clear all executables in the current directory, you can run `:make clean` (this uses GNU `find`, and hasn't been tested on anything except Linux).

### <a name="windows-workflow"></a> On Windows

The same thing holds true for Windows as well. However, if you want to use the Makefile, you'll need to install `make` on Windows first. For more details on how to do that, you can follow
instructions [here](https://stackoverflow.com/questions/2532234/how-to-run-a-makefile-in-windows).

