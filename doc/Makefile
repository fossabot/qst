# Minimal makefile for Sphinx documentation
#
MAKEFILE_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
MAKEFILE_DIR := $(dir $(MAKEFILE_PATH))


# You can set these variables from the command line.
SPHINXOPTS    = -c $(MAKEFILE_DIR)
SPHINXBUILD   = sphinx-build
SPHINXPROJ    = Qst
SOURCEDIR     = "$(MAKEFILE_DIR)"
BUILDDIR      = "$(MAKEFILE_DIR)/../build-results/doc/"

.PHONY: html

# Catch-all target: route all unknown targets to Sphinx using the new
# "make mode" option.  $(O) is meant as a shortcut for $(SPHINXOPTS).
html:
	@$(SPHINXBUILD) -b html $(SPHINXOPTS) "$(SOURCEDIR)" "$(BUILDDIR)"

