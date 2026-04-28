# alap

Minimal CLI template generator for C, Java, Python and Bash.

## Features

- Generate starter files quickly
- Supports C, Java, Python and Bash
- Print template to stdout with `--stdout`
- Show help and version info

## Build

```bash
gcc src/alap.c -o alap -O2
```

## Usage

```bash
./alap c
./alap java
./alap py
./alap sh
./alap py --stdout
./alap --help
./alap --version
```

## Example

```bash
./alap c
# [main.c] was created.
```

## Download

Prebuilt binaries are available on the Releases page.

## License

MIT
