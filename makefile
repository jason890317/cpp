exe=pro_1 pro_21 pro_9 pro_13
cc=g++
config=-Wall -g -o

pro_13:pro_13.o
	$(cc) $(config) $@ $^

pro_9:pro_9.o
	$(cc) $(config) $@ $^


pro_21:pro_21.o
	$(cc) $(config) $@ $^


pro_1:pro_1.o
	$(cc) $(config) $@ $^



*.o:*.cpp
	$(cc) -c $^

.PHONY:clean
clean:
	@echo "---clean---"
	-@rm -rf $(exe) *.o *.out
