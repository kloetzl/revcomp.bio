LANGUAGES=python c

CHECKLANGUAGES=$(LANGUAGES:%=check-%)
CLEANLANGUAGES=$(LANGUAGES:%=clean-%)

.PHONY: all clean check implementations.md

all: $(LANGUAGES)
$(LANGUAGES) check: $(CHECKLANGUAGES)
clean: $(CLEANLANGUAGES)

$(CHECKLANGUAGES):
	@echo "check $(@:check-%=%)"
	@$(MAKE) -C $(@:check-%=%) check

$(CLEANLANGUAGES):
	@echo "clean $(@:clean-%=%)"
	@$(MAKE) -C $(@:clean-%=%) clean

implementations.md:
	python3 web/build.py > $@
