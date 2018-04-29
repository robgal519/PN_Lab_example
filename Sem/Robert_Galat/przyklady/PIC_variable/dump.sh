#!/bin/bash
	sed -n '/foo/,/^$/p' <(objdump -d libfoo.so)
