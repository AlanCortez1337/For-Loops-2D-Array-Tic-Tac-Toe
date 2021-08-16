.PHONY: solution_test

# Checks that cppaudit and cpputils at their current versions are working to
# make a graphics lab that builds and tests.

problem/starter:
	@mkdir problem/starter
	@cp problem/*.cc problem/starter/
ifneq ("$(wildcard $(problem/*.h))", "")
	@cp problem/*.h problem/starter/
endif

solution_test: problem/starter
	@cp solution/* problem/
	@cd problem && make build && make all && make clean
	@cd ..
	@mv problem/starter/* problem/
	@rmdir problem/starter
