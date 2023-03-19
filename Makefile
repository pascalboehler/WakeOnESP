.DEFAULT_GOAL := build

build:
	pio run

genFS:
	pio run -t buildfs
	pio run -t uploadfs

upload:
	piro run -t upload
