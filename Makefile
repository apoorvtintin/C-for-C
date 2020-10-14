BINS = hw1 djikstras_hw2 mst_hw3

.PHONY: app clean hw1 djikstras_hw2 mst_hw3

app:
	mkdir -p bin obj
	make -C src djikstras_hw2
	make -C src mst_hw3

djikstras_hw2:
	make -C src djikstras_hw2

mst_hw3:
	mkdir -p bin obj
	make -C src mst_hw3

clean:
	make -C src clean
	rm -rf bin obj