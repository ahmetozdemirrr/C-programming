all: compile run clean

compile: main.c
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@gcc -o test main.c

run:
	@echo "-------------------------------------------"
	./test

clean:
	@echo "-------------------------------------------"
	@echo "Removing compiled files..."
	@rm -f *.o	
	
	