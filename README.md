# Liga Ciberseguridad 42 Barcelona

(Por consistencia con el resto de archivos, este README estará escrito en inglés)

## README Status

WIP, kinda sucks.

## Building

In each category directory (eg.: pwn) should be a Makefile, a simple `make` should either compile
the binaries, set up the challenge environments or give you information on how to proceed.

At the root of the project is a `compile.sh` shell script. This is used to compile the binaries
in an Ubuntu container to ensure compatibility with the 42 Terminals. Running the script creates
a directory named `binaries` containing all the executables compiled.

Please report any broken binaries or unsolvable challenges!!!

## Status

This project's modules are still work-in-progress, but a few modules have been added so far.

The platform we've made is called [Zynth](https://zynth-rho.vercel.app). We'll host everything there 
and set up a leaderboard along with a flag-validation system once we're done with the modules.

The site is still broken and hasn't had any content uploaded yet, but you can check it out if you want.

## Current Progress

Please keep in mind that the module count will probably change during development!!!

```
pwn      -> 3/9  modules done
crypto   -> 0/4  modules done
maldev   -> 0/8  modules done
rev      -> 0/7  modules done
web      -> 0/10 modules done

```

## Goals

This is our plan for the module tree:
```
```
├── crypto
│   ├── aes
│   ├── codecs
│   ├── xor
│   └── xor-otp
├── malware
│   ├── Analysis
│   ├── Development
│   ├── Evasion-Techniques
│   ├── Packing
│   ├── Persistence
│   ├── Powershell
│   ├── Self-Modification
│   └── Windows-Malware
├── pwn
│   ├── Buffer-Overflows
│   ├── Crashmes
│   ├── Format-String
│   ├── Heap-Exploits
│   ├── Kernel?
│   ├── ret2...
│   ├── ROP
│   ├── Shellcode
│   └── Stack-Pivots
├── rev
│   ├── asm-rev
│   ├── ast-dumping
│   ├── blackbox
│   ├── Crackmes
│   ├── deobfuscation
│   ├── rev-the-algo
│   └── rev-the-struct
└── web
    ├── CSRF
    ├── CVE-presentations
    ├── Enumeration
    ├── privesc
    ├── RCE
    ├── Reverse-Shells
    ├── SQLi
    ├── SSRF
    ├── tooling
    └── XSS
```
```

