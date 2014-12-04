ifeq ($(OS), Windows_NT)
  TECMAKE_CMD = $(MAKE) --no-print-directory -f tecmakewin.mak TEC_UNAME=$(TEC_UNAME)
else
  TECMAKE_CMD = $(MAKE) --no-print-directory -f tecmake.mak
endif

all: lualib lua luac bin2c

lualib:
	@$(TECMAKE_CMD)

lua:
	@$(TECMAKE_CMD) MF=lua

luac:
	@$(TECMAKE_CMD) MF=luac

bin2c:
	@$(TECMAKE_CMD) MF=bin2c
