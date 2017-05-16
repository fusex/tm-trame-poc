BIN := trame-poc 

CFLAGS := -ggdb

$(BIN) : $(BIN).c

clean:
	$(RM) $(BIN)
