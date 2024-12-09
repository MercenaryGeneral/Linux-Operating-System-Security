[Unit]
Description=mysyslog-daemon

[Service]
Type=simple
ExecStart=/usr/bin/mysyslog-daemon
Restart=always
StandardOutput=journal
StandardError=journal
SyslogIdentifier=mysyslog-daemon

[Install]
WantedBy=multi-user.target
