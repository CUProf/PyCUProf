.PHONY: all install clean

all: install

install:
	cd CUProf && ./bin/install && cd ..
	python3 setup.py bdist
	@echo ""
	@echo "The package has been built successfully."
	@echo "To install the package, run the following command:"
	@echo "pip install ."
clean:
	rm -rf build dist *.egg-info
	cd CUProf && ./bin/clean && cd ..
