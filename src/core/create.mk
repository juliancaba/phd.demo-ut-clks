PRJ=tmp

VERSION=2015


all: clean gen cpy run dcp


dcp:
	@ cd src;\
	for i in `find ../tmp/tmp.srcs -name *.dcp`; do \
	 ln -sf $$i; \
	done

gen: 
	@cd ./hls; make; cd -

cpy:
	@mkdir src
	cd src; ln -sf ../hls/prj.TDD/solution/syn/vhdl/*.vhd .; \
	cd -

run: create_$(VERSION).tcl
	vivado -mode batch -source $^


clean:
	$(RM) -rf src $(PRJ) *~ *.jou *.log




