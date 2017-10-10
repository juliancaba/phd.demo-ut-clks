VERSION=2015

all:
	@cd core;\
	make -f create.mk clean all VERSION=$(VERSION); cd -;\
	cp -rL core/src hw_src

clean:
	$(RM) -rf hw_src *~
