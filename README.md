# morse

Command-line utility to encode text to Morse code and decode Morse code back to text.

## Features

- Encode a text `STRING` to Morse (`-e`)
- Decode whitespace-separated Morse symbols back to text (`-d`)
- Uses `/` as the word separator in Morse (spaces encode to `/`)
- Plays `dot.wav` and `dash.wav` via `paplay` during encoding
- Supported input characters: A–Z (case-insensitive), 0–9, `. , ? ' ! / ( ) & : ; = + - _ " $ @`, and space
- Unknown Morse symbols during decoding are output as `#`

## Tech Stack

- C (standard headers: `stdio.h`, `stdlib.h`, `ctype.h`, `string.h`)
- POSIX (`unistd.h` for `usleep`/`dprintf`)
- External command used at runtime: `paplay` (called via `system()`)

## Build / Installation

```sh
make morse
```

## Usage

```sh
morse -h
morse -e STRING
morse -d STRING
```

From `-h` output:
- Use spaces to separate Morse symbols.
- Use `/` to separate words in Morse.
