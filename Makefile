# This is a regular comment, that will not be displayed

## ----------------------------------------------------------------------
## This is the Makefile for Rumi project. 
## ----------------------------------------------------------------------

DIRS=out out/linux linux_build

RUMI := ./rumi
PWD = $(shell pwd)
LINUX = ~/workspace/linux/
LINUX_BUILD = ~/workspace/linux/build

.PHONY: setup-environment rumi

setup-environment:
	sudo apt-get install -y libssl-dev flex bison libelf-dev

help:	## Show this help.
	@sed -ne '/@sed/!s/## //p' $(MAKEFILE_LIST)

build:	## Build something.
	ls $(LINUX_BUILD)

generate_doc: ## generate documentation
	cd documentation && doxygen

clean: 	## clean all builds
	rm -rf out

linux-image-config: ## build default linux config
	make -C $(LINUX) O=$(LINUX_BUILD) tinyconfig

linux-image:  
	$(MAKE) -C $(LINUX) O=$(LINUX_BUILD) -j8

initfs: ## create sysroot folder
	rm initramfs/custom-initramfs.cpio.gz
	cd initramfs && find . -print0 | cpio --null --create --verbose --format=newc | gzip --best > custom-initramfs.cpio.gz

rumi: ## build rumi 
	$(MAKE) -C $(RUMI) all

qemu: rumi initfs ## run linux kernel with qemu ctrl-a x exits from qemu
	qemu-system-x86_64 -kernel $(LINUX_BUILD)/arch/x86/boot/bzImage -nographic -append "earlyprintk=serial,ttyS0 console=ttyS0 debug" --initrd initramfs/custom-initramfs.cpio.gz 

$(shell mkdir -p $(DIRS))
