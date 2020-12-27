
# "all" is the default target (because it is first).
# run the targets "init", "clean" and "run" in that order.
all: init clean compile run

# make the bin directory, if it does not alreay exist.
init:
	mkdir -p bin

# remove the previous executable, if it exists.
clean:
	rm -f bin/helloworld

# compile, link, and name the executable "helloworld"; save it in the bin directory.
compile:
	gcc -o bin/helloworld src/HelloWorld.c

# run the executable.
run:
	bin/helloworld
	