set LUA_DIR=..\lua5.1
..\mingw\bin\gcc -O2 -shared -s -I %LUA_DIR%\src -L %LUA_DIR%\src -o lpeg.dll lptree.c lpvm.c lpcap.c lpcode.c lpprint.c -llua51