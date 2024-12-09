# mysyslog-client

A command-line client application using the `libmysyslog` library to log messages with customizable levels, drivers, formats, and paths.

## Building

To build the client, run the following command in the `libmysyslog-client` directory:

```bash
make all

mysyslog-client [options]

Options:
  -m, --message   Message to log
  -l, --level    Log level (DEBUG, INFO, WARN, ERROR, CRITICAL)
  -d, --driver   Driver to use (text, json)
  -f, --format   Format to use (text, json)
  -p, --path    Log file path
