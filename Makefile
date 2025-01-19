LANGUAGES=python c

CHECKLANGUAGES=$(LANGUAGES:%=check-%)
CLEANLANGUAGES=$(LANGUAGES:%=clean-%)

.PHONY: all clean implementations.md

all: $(LANGUAGES)
$(LANGUAGES): $(CHECKLANGUAGES)
clean: $(CLEANLANGUAGES)

$(CHECKLANGUAGES):
	@echo "check $(@:check-%=%)"
	@$(MAKE) -C $(@:check-%=%) check

$(CLEANLANGUAGES):
	@echo "clean $(@:clean-%=%)"
	@$(MAKE) -C $(@:clean-%=%) clean

implementations.md:
	for lang in $(LANGUAGES); do \
		$(MAKE) -C $$lang print; \
		echo ''; \
	done > $@
