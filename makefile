exe=pro_1
cc=g++
config=-Wall -g -o
pro_1:pro_1.o
	$(cc) $(config) $@ $^

*.o:*.cpp
	$(cc) -c $^

.PHONY:clean
clean:
	@echo "---clean---"
	-rm -rf $(exe) *.o *.out
