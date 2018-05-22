SHELL:=/bin/bash -O extglob
NAME = prezentacja

all: $(NAME).pdf

recompile: clean
	make 

$(NAME).pdf: *.tex *.bib
	pdflatex -file-line-error --max-print-line=200 -synctex=1  -shell-escape $(NAME) && bibtex $(NAME) && pdflatex -shell-escape $(NAME) && pdflatex -shell-escape $(NAME)

show: $(NAME).pdf
	xdg-open $<

clean:
	rm -rf !(*.tex|*.bib|przyklady|makefile|*.png)
