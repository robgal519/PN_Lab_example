(TeX-add-style-hook
 "konspekt"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-class-options
                     '(("article" "12pt")))
   (TeX-add-to-alist 'LaTeX-provided-package-options
                     '(("inputenc" "utf8")))
   (TeX-run-style-hooks
    "latex2e"
    "article"
    "art12"
    "polski"
    "natbib"
    "url"
    "inputenc"
    "amsmath"
    "graphicx"
    "parskip"
    "fancyhdr"
    "vmargin")
   (TeX-add-symbols
    "thetitle"
    "theauthor"
    "thedate")
   (LaTeX-add-labels
    "ex1"))
 :latex)

