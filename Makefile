CPP=cpp-4.9

%.txt: %.ksp
	@$(CPP) -P $< | perl -0777 -p -e 's/@@@\s*/\n/msg;' > $@
