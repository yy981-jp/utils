# utils

This repository contains small standalone utility applications.

## Build

Initialize the app-local dependencies:

```sh
git submodule update --init --recursive
```

Configure and build one application (recommended while working on individual utilities):

```sh
cmake -S . -B build -G Ninja -DUTILS_APP=BlankWindow
cmake --build build
```

Set `UTILS_APP` to the directory name under `apps/`. Use `UTILS_APP=ALL` to configure every application; this requires every external dependency used by all 55 utilities to be available. On MSYS2 UCRT64, use the UCRT64 CMake, compiler, pkg-config, and Ninja executables together rather than mixing `/usr/bin` tools with `/ucrt64/bin` tools.

Each application has its own `apps/<name>/CMakeLists.txt`. Executables are written directly to the repository's `build/` directory; intermediate files remain in CMake's build tree.

The original `.ybp` / `.ybp2` profiles are retained under `legacy/profiles/` for reference. Where both formats existed, the `.ybp2` settings were used.

`apps/typing` expects a runtime data file named `typing.db` in its working directory. That file was not included in the migration inputs, so the target can be built without it but the program cannot run normally until the data file is supplied.
