# utils

This repository contains small standalone utility applications.

## Build

Initialize the app-local dependencies:

```sh
git submodule update --init --recursive
```

Configure with CMake and Ninja:

```sh
cmake -S . -B build -G Ninja
cmake --build build
```

Each application has its own `apps/<name>/CMakeLists.txt`. Executables are written directly to the repository's `build/` directory; intermediate files remain in CMake's build tree.

The original `.ybp` / `.ybp2` profiles are retained under `legacy/profiles/` for reference. Where both formats existed, the `.ybp2` settings were used.

`apps/typing` expects a runtime data file named `typing.db` in its working directory. That file was not included in the migration inputs, so the target can be built without it but the program cannot run normally until the data file is supplied.
