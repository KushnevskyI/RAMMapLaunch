#### RAMMapLaunch

There is problem on Windows Server 2008 when its works with many small files, Metafile grows to huge size. 

Sysinternals do cool tool - RAMMap, but it can't run by schedule. 

RAMMapLaunch running RAMMap and using handler of Window sending commands to clean Metafile. 

It dumb tool, but for me it works. 

How to build: 

I using Codeblocks with MinGW

Usage:

RAMMapLaunch.exe path-to-rammap.exe


