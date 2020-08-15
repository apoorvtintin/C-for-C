BINS = hw1 djikstras_hw2 mst_hw3

.PHONY: app clean hw1 djikstras_hw2 mst_hw3

app:
	mkdir -p bin obj
	make -C src djikstras_hw2

djikstras_hw2:
	make -C src djikstras_hw2

clean:
	make -C src clean
	rm -rf bin obj