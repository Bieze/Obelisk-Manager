# Obelisk manager

## Building

Not sure on other systems but I personally use MinGW-W64 through MSYS2, so I keep the libraries in
C:\msys64\mingw64\bin\lib-boost..-.a and since the compiler is at C:\msys64\mingw64\bin\g*.exe I run
this command to compile my program.

```powershell
mkdir build
cd build
cmake -DCMAKE_C_COMPILER=C:/msys64/mingw64/bin/gcc.exe -DCMAKE_CXX_COMPILER=C:/msys64/mingw64/bin/g++.exe
```

Modify it so it works for you system

directory structure

```
|----------------------------------------------------|
| / (root)                                           |
|_                                                   |
| |_                                                 |
|   |_ Project and CMAKE files                       |
|                                                    |
|_ msys64                                            |
| |_ mingw64                                         |
|   |_ bin                                           |
|   | |_ libboost_..._x64.a (library)                |
|   |                                                |
|   |_ include                                       |
|     |_ boost                                       |
|       |_ program_options/ (directory)              |
|       |_ program_options.hpp (file)                |
|----------------------------------------------------|
```

If you found a bug or anything please open an [issue](https://github.com/abdulh4ni/Obelisk-manager/issues/new). If you would like to contribute please do the same and open a [pull request](https://github.com/abdulh4ni/Obelisk-manager/pulls/).