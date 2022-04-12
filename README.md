[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![Latest Release][releaselateststable-shield]][releaselateststable-url]



<!-- PROJECT LOGO -->
<br />
<p align="center">
  <a href="https://github.com/core-hacked/">
    <img src="logo.png" alt="Logo" width="120" height="120">
  </a>

  <h3 align="center">CoreScript Programming Language</h3>

  <p align="center">
    CoreScript, is a simple batch like programming language that has an addons feature called "cores".
    <br />
    <a href="https://github.com/core-hacked/CoreScript-lang/issues">Report Bug</a>
    ·
    <a href="https://github.com/core-hacked/CoreScript-lang/issues">Request Feature</a>
    ·
    <a href="#documentation">View Documentation</a>
  </p>
</p>



<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary><h2 style="display: inline-block">Table of Contents</h2></summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#documentation">Documentation</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>

<br/>

<!-- ABOUT THE PROJECT -->
## About The Project

### Built With

* [Python (as a compilation method)](https://www.python.org/)

* [C-Programming Language](https://en.wikipedia.org/wiki/C_(programming_language))

* [JSON (For vscode syntax highlighting)](https://www.json.org/json-en.html)

<br/>

<!-- GETTING STARTED -->
## Getting Started

To get a local copy up and running follow these simple steps.

### Prerequisites

<b>Linux</b>

* Anaconda (Optional)<br/>
  [Installation Instructions](https://docs.anaconda.com/anaconda/install/linux/)

* Python (Option 1 for building) (Optional)
  ```sh
  $ sudo apt install python3
  ```
* Make (Option 2 for building) (Optional | Build essentials includes it)
   ```
   $ sudo apt-get install make
   ```
* Build essentials or just install GCC
  ```sh
  $ sudo apt-get install build-essential
  ```

<b>Windows</b>

* Anaconda (Recommended | Optional)<br/>
  [Get here](https://www.anaconda.com/products/individual)
  
* Python (Option 1 for building)<br/>
  [Get here](https://www.python.org/)
  
* Make (Option 2 for building)<br/>
  [Get Here](http://gnuwin32.sourceforge.net/packages/make.htm)
  
* GCC (MinGW)<br/>
 [Installation Tutorial](https://www.youtube.com/watch?v=sXW2VLrQ3Bs)<br/>
 [Get here](https://www.mingw-w64.org/downloads/)
 
 
### Installation
1. Clone the repo
   ```sh
   $ git clone https://github.com/core-hacked/CoreScript-lang.git
   ```
2. Compile
* Compilation method 1:
   ```sh
   $ python3 compile.py
   ```
   ```sh
   arguments:
   # -w / --win | Compile for windows/on windows
   # -a / --autorun | autorun after compilation
   ```
* Compilation method 2:
  ```sh
  $ make
  ```
* Put the corescript binary into your bin folder (Optional | Linux)
  ```sh
  $ mv corescript /bin/corescript
  ```

* Put the corescript binary into the ``C:\`` folder and set an environment variable (Optional | Windows)
  ```bat
  > move corescript.exe C:\corescript\corescript.exe
  ```
  [How to add an environment variable](https://docs.microsoft.com/en-us/previous-versions/office/developer/sharepoint-2010/ee537574(v=office.14)) | add it as ``C:\\corescript\\`` then save, restart, and after that open command prompt or powershell and type ``corescript`` if it gets recognized you did everything right. 

<br/>

* Getting Syntax Highlighting for VSCode
  
  <b>For Linux</b>

  Copy the contents of the ``syntax/corescript`` to your ``home/.vscode/extensions`` folder.

  ```sh
  $ mv syntax/corescript ~/.vscode/extensions/corescript
  ```

  <b>For Windows</b>

  Copy the contents of the ``syntax\corescript`` folder to the ``C:\Users\YourUsr\.vscode\extensions`` folder.

  ```bat
  > move syntax\corescript C:\Users\YourUsr\.vscode\extensions\corescript
  ```

<br/>

## Usage
* Running corescript (Linux)
  ```sh
  $ ./corescript <file>
  ```
  or just ``./corescript`` to view version and usage

* Running corescript (Windows)
  ```bat
  > .\corescript.exe <file>
  ```
  or just ``.\corescript.exe`` to view version and usage
  (You can remove ``.exe`` at the end if you want)
  
  <br/>
  <br/>
<!-- DOCUMENTATION -->
## Documentation
<details closed>
<summary><b>CoreScript v1.0.0 Documentation</b></summary>

<br/>

To Start create a file ending in ``.cos`` or ``.corescript`` and open it in your editor of choice.

<br/>

<b> Basics </b>

* Text Output
  ```
  # Print text with a new-line character at the end.
  print Hello World! 
  ```
  ```
  # Print text without a new-line character at the end.
  nprint Hello World! 
  ```

<BR/>

* Comments
  ```
  # this is a comment
  ```
  or the classic shebang for linux
  ```
  #!/bin/corescript
  ```

<b>Functions/labels, goto and return</b>

* Functions/Labels
  ```
  :ThisIsAlabel
  ```

  Functions are a little different than in other languages, since corescript works like batch, <br/> labels won't act like functions, which means that they are not being called, but rather marked
  as a point in the code that can be called to.

  ```
  # creating a label in corescript:
  :label-name
  # code to execute at this point here.
  ```

  To go to a label you can use ``goto label-name`` and the code below it will be executed. <br/> 
  Keep in mind that labels will be ignored and the code will be run anyways if you don't put them
  above your main label/function intern making them unreachable.

  If you need multiple functions after another, you can spare yourself the time of making a return-label. <br/><br/>
  All you need to do, to return to the original position of the code, ignoring the ``goto`` call is ``return``. 

  Keep in mind that ``return`` needs the name of your current function which it then uses to determine where it was last called.


  ```bat
  # example:

  goto main

  :my-function
  print example
  return my-function

  :main
  print hi
  goto my-function

  # code below here will be executed after the return function
  ```

<b>Variables</b>

* Creating variables
  ```js
  var VariableName = value
  ```
  Creating variables is very simple and doesn't require the type of the variable, var represents a multi-type-variable which can be a string, integer etc. as long as it can be represented as a value in memory.
  <br/><br/>

* Setting or changing the value of a variable
  ```bat
  set VariableName = newValue
  ```
  As simple as creating one, simply replace ``var`` with ``set``.
  <br/><br/>

* Using Variables
  
  To use variables you need brackets ``[]``.
  Inside of which you put the name of a variable.

  ```bat
  # example:
  print [VariableName]
  ```
<br/>

* Special Variables

  These speical variables can be used to get special characters or make null checks inside the code.

    1. ``[cos.empty]`` is as the name suggest an empty variable.

    2. ``[cos.space]`` if you are special and want to have a variable with the value of the <kbd>space</kbd> key, there you go.

    3. ``[cos.newline]`` since ``\n`` doesn't always work, you can use this variable to add a newline value somewhere in your code.

    4. ``[os.pinpoint]`` since CoreScript runs on both Windows, Linux and MacOS, you can get the users operating system with this variable.

```bat
# example os checking:

goto main

:platform-linux
print you are on linux ([os.pinpoint])
goto exit

:platform-win
print you are on windows ([os.pinpoint])
goto exit

:platform-apple
print you are on mac/an apple device ([os.pinpoint])
goto exit

:platform-unix
print you are on unix ([os.pinpoint])
goto exit

:platform-posix
print you are on posix ([os.pinpoint])
goto exit

:platform-unknown
print you are on an unknown platform ([os.pinpoint])
goto exit

:main
# windows x86 / x64 
if os.pinpoint = win32:platform-win
if os.pinpoint = win64:platform-win

# linux
if os.pinpoint = linux:platform-linux

# apple / mac os
if os.pinpoint = apple:platform-apple
if os.pinpoint = apple-unknown:platform-apple

# unix
if os.pinpoint = unix:platform-unix

# posix
if os.pinpoint = posix:platform-posix

# unknown / default if it is unable to pinpoint the os
if os.pinpoint = unknown:platform-unknown
goto exit

:exit
stop
```
<br/>

<b>if statements</b>

  Currently you can only check if something is equal to something, then execute code based on the result.

  To do this, you need a function/label which will be ran after it comes back as true and the if statement itself.

  ```py
  :LabelToExecute
  # if it comes back true run the code below..

  if [VariableName] = something:LableToExecute
  # every piece of code below the if will be the else statement.
  ```

<br/>

<b>User Input</b>

  ```
  input VariableName = Text you want to display.
  ```

  You can grab the users input into the variable specified after input and print text that can ask the user something after the ``=`` sign.

<br/>
<b>System or Filesystem operations</b>

* ``sys [command]`` execute any system command.

* ``mkdir [dirname]`` create a directory.

* ``rmdir [dirname]`` delete a directory.

* ``mk [filename]`` create a file.

* ``rm [filename]`` delete a file.

These are only officially tested on Windows and Linux, please submit a bug report if something doesn't work on your OS.
<br/>
<br/>
  
  <b>Mathematical Operators</b>
  
```js
    var a = 12
    set a = [add a 48]
    print [a]
```
  
* add (+)
* sub (-)
* mult (*)
* div (/)
* rem (%)
* rand rand should be used as "min, max". Ex: print [rand 1 10]
  
Their purposes should be self-explainable
  
<br/>

<b>cores/addons</b>

* This feature is currently W.I.P and will come in V2.<Br/>
More information soon.

****

</details>

<br/>

<!-- ROADMAP -->
## Roadmap

See the [open issues](https://github.com/core-hacked/CoreScript-lang/issues) for a list of proposed features (and known issues).

<br/>

<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to be... learn, inspire, and create. Any contributions you make are **greatly appreciated**.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<br/>

<!-- LICENSE -->
## License

This repository is distributed under the GNU GPLv3 License. See `LICENSE` for more information.

<br/>

<!-- CONTACT -->
## Contact

[info@corehacked.cf](mailto:info@corehacked.cf)


<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/core-hacked/corescript-lang.svg?colorA=1e1e28&colorB=E38C8F&style=for-the-badge&logo=starship%20style=for-the-badge
[contributors-url]: https://github.com/core-hacked/corescript-lang/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/core-hacked/corescript-lang.svg?colorA=1e1e28&colorB=A4B9EF&style=for-the-badge&logo=starship%20style=for-the-badge
[forks-url]: https://github.com/core-hacked/corescript-lang/network/members
[stars-shield]: https://img.shields.io/github/stars/core-hacked/corescript-lang.svg?colorA=1e1e28&colorB=EBDDAA&style=for-the-badge&logo=starship%20style=for-the-badge
[stars-url]: https://github.com/core-hacked/corescript-lang/stargazers
[issues-shield]: https://img.shields.io/github/issues/core-hacked/corescript-lang.svg?colorA=1e1e28&colorB=B1E3AD&style=for-the-badge&logo=starship%20style=for-the-badge
[issues-url]: https://github.com/core-hacked/corescript-lang/issues
[license-shield]: https://img.shields.io/github/license/core-hacked/corescript-lang.svg?colorA=1e1e28&colorB=F9C096&style=for-the-badge&logo=starship%20style=for-the-badge
[license-url]: https://github.com/core-hacked/corescript-lang/blob/master/LICENSE
[releaselateststable-shield]: https://img.shields.io/badge/Release-Stable%3A%20v1.0.0-blue?colorA=1e1e28&colorB=A4B9EF&style=for-the-badge&logo=starship%20style=for-the-badge
[releaselateststable-url]: https://github.com/core-hacked/corescript-lang/releases/latest
