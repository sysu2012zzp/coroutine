.PHONY: all libco test sample clean

all: libco test sample


libco:
	mkdir -p objs/src
	(cd src && make)

test: libco
	mkdir -p objs/test
	(cd t && make)

runtest: test
	./objs/test/test

sample: libco
	mkdir -p objs/sample
	(cd sample && make)

clean:
	rm -rf objs/
