CMP = gcc
MAIN = flag
FUNC = flagfunc
EXEC = ctf
GFX = gfx

$(EXEC): $(FUNC).o $(MAIN).o $(GFX).o
	$(CMP) $(FUNC).o $(MAIN).o $(GFX).o -lX11 -lm -o $(EXEC)

$(FUNC).o: $(FUNC).c $(FUNC).h 
	$(CMP) -c $(FUNC).c -o $(FUNC).o 

$(MAIN).o: $(MAIN).c $(FUNC).h
	$(CMP) -c $(MAIN).c -o $(MAIN).o 



clean:
	rm $(EXEC)