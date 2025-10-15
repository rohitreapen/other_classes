# --------- config ---------
PANDOC        := pandoc
PDFTK         := pdftk

# Pandoc PDF settings
PDFENGINE     := xelatex
HSTYLE        := kate
MONOFONT      := DejaVu Sans Mono
GEOMETRY      := margin=1in
FONTSIZE      := 12pt

# Optional Lua filters (comment out if you don't use them)
# LUA_FILTERS   := include-files.lua include-code-files.lua
LUA_FILTERS   :=

# Pandoc filters
PANDOC_FILTERS :=  pandoc-include

# Header to wrap/line-break code blocks (fvextra + DefineVerbatimEnvironment)
WRAP_HEADER   := wrap_code.tex

# Source markdown files
SRC_DIR       := src
DOCS          := $(wildcard $(SRC_DIR)/*.md)
# DOCS          := $(SRC_DIR)/cover.md $(SRC_DIR)/larger_essay.md
# If you also want an appendix, uncomment:
# DOCS         := $(SRC_DIR)/cover.md $(SRC_DIR)/notes.md $(SRC_DIR)/appendix.md

# Build dir & outputs
BUILD_DIR     := build
PDFS          := $(DOCS:$(SRC_DIR)/%.md=$(BUILD_DIR)/%.pdf)
FINAL_PDF     := $(BUILD_DIR)/final.pdf

# Common flags for pandoc -> PDF
PANDOC_PDF_FLAGS := \
  --pdf-engine=$(PDFENGINE) \
  --syntax-highlighting=$(HSTYLE) \
  -V monofont="$(MONOFONT)" \
  -V geometry:$(GEOMETRY) \
  -V fontsize=$(FONTSIZE) \
  --include-in-header=$(WRAP_HEADER) \
  --filter $(PANDOC_FILTERS) \
  $(foreach f,$(LUA_FILTERS),--lua-filter=$(f))

# For HTML (optional): wrap long lines in code
HTML_CSS            := wrap_code.css
HTML_METADATA_TITLE := title="larger_essay"
PANDOC_HTML_FLAGS   := --standalone --highlight-style=$(HSTYLE) $(if $(wildcard $(HTML_CSS)),--css=$(HTML_CSS),) --metadata $(HTML_METADATA_TITLE)

# --------- targets ---------
.PHONY: all pdf final html clean tree

all: pdf final

pdf: $(PDFS)

# Pattern rule: src/foo.md -> build/foo.pdf
$(BUILD_DIR)/%.pdf: $(SRC_DIR)/%.md | $(BUILD_DIR)
	$(PANDOC) $< -o $@ $(PANDOC_PDF_FLAGS)

# Merge cover + notes (+ appendix if included) into final.pdf
final: $(FINAL_PDF)

$(FINAL_PDF): $(PDFS)
	$(PDFTK) $^ cat output $@

# Optional: build HTML versions of the same docs
html: $(DOCS:$(SRC_DIR)/%.md=$(BUILD_DIR)/%.html)

$(BUILD_DIR)/%.html: $(SRC_DIR)/%.md | $(BUILD_DIR)
	$(PANDOC) $< -o $@ $(PANDOC_HTML_FLAGS)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

# Show the plan
tree:
	@echo "Docs:     $(DOCS)"
	@echo "PDFs:     $(PDFS)"
	@echo "Final:    $(FINAL_PDF)"
