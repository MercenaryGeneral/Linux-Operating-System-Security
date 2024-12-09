.PHONY: all clean

all:
    $(MAKE) -C libmysyslog
    $(MAKE) -C libmysyslog-text
    $(MAKE) -C libmysyslog-json
    $(MAKE) -C mysyslog-client
    $(MAKE) -C mysyslog-daemon

clean:
    $(MAKE) -C libmysyslog clean
    $(MAKE) -C libmysyslog-text clean
    $(MAKE) -C libmysyslog-json clean
    $(MAKE) -C mysyslog-client clean
    $(MAKE) -C mysyslog-daemon clean
