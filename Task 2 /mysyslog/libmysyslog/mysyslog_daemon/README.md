# mysyslog-daemon

A systemd service using the `libmysyslog` library to log messages to a file with configurable format and driver.

## Building

To build the daemon, run the following command in the `libmysyslog-daemon` directory:

```bash
make all

The daemon reads its configuration from /etc/mysyslog/mysyslog.cfg and logs messages to the specified file with the chosen format and driver. It can be controlled using systemd commands.

Configuration
The configuration file (/etc/mysyslog/mysyslog.cfg) should be in the following format:

{
	"path": "/var/log/mysyslog.log",
	"format": "text",
	"driver": "text"
}

Install the daemon
make install

Enable the daemon to start on boot
make systemctl-enable

Disable the daemon from starting on boot
make systemctl-disable

Start the daemon
systemctl start mysyslog-daemon

Stop the daemon
systemctl stop mysyslog-daemon

Restart the daemon
systemctl restart mysyslog-daemon

Check the daemon's status
systemctl status mysyslog-daemon

To create a debian package, run:

make deb
