DELETE FROM help WHERE command = 'REMSGLINE';
INSERT INTO help (command, subcommand, line, help) VALUES ('REMSGLINE','',1,'****** REMSGLINE COMMAND ******');
INSERT INTO help (command, subcommand, line, help) VALUES ('REMSGLINE','',2,'Removes an SGLINE from the network');
INSERT INTO help (command, subcommand, line, help) VALUES ('REMSGLINE','',3,'Syntax: /msg $BOT$ remsgline [-fr] <user@host>');
INSERT INTO help (command, subcommand, line, help) VALUES ('REMSGLINE','',4,'-fr - Removes all the matching and the specified gline, otherwise just the specified gline.');
INSERT INTO help (command, subcommand, line, help) VALUES ('REMSGLINE','',5,'<user@host> - the user@host to remove from the sgline list');
DELETE FROM help WHERE command = 'CONFIG';
INSERT INTO help (command, subcommand, line, help) VALUES ('CONFIG','',1,'****** CONFIG COMMAND ******');
INSERT INTO help (command, subcommand, line, help) VALUES ('CONFIG','',2,'Sets internal configuration options within the bot');
INSERT INTO help (command, subcommand, line, help) VALUES ('CONFIG','',3,'Syntax: /msg $BOT$ config <option> <value>');
INSERT INTO help (command, subcommand, line, help) VALUES ('CONFIG','',4,'<option> may be:');
INSERT INTO help (command, subcommand, line, help) VALUES ('CONFIG','',5,'-GTime <duration> - default gline time (accepts friendly times e.g. 900s, 30m, 3h, 1d)');
INSERT INTO help (command, subcommand, line, help) VALUES ('CONFIG','',6,'-VClones <amount> - threshold for warning about virtual (realname) clones');
INSERT INTO help (command, subcommand, line, help) VALUES ('CONFIG','',7,'-Clones <amount> - threshold for clones on a single IP');
INSERT INTO help (command, subcommand, line, help) VALUES ('CONFIG','',8,'-CClones <amount> - threshold for CIDR clones (see below) for both IPv4 and IPv6!');
INSERT INTO help (command, subcommand, line, help) VALUES ('CONFIG','',9,'-CClonesCIDR24 <size> - CIDR bit length for IPv4 clones (16-32)');
INSERT INTO help (command, subcommand, line, help) VALUES ('CONFIG','',10,'-CClonesCIDR48 <size> - CIDR bit length for IPv6 clones (16-64)');
INSERT INTO help (command, subcommand, line, help) VALUES ('CONFIG','',11,'-CClonesGline <Yes|No> - auto-gline for CIDR clones flag');
INSERT INTO help (command, subcommand, line, help) VALUES ('CONFIG','',12,'-CClonesGTime <duration> - gline duration for CIDR clones (accepts friendly times)');
INSERT INTO help (command, subcommand, line, help) VALUES ('CONFIG','',13,'-IClones <amount> - threshold for CIDR ident clones');
INSERT INTO help (command, subcommand, line, help) VALUES ('CONFIG','',14,'-IClonesGline <Yes|No> - auto-gline for CIDR ident clones flag');
INSERT INTO help (command, subcommand, line, help) VALUES ('CONFIG','',15,'-CClonesTime <duration> - time between clone warnings to msglog (accepts friendly times)');
INSERT INTO help (command, subcommand, line, help) VALUES ('CONFIG','',16,'-GBCount <count> - number of glines to set at once');
INSERT INTO help (command, subcommand, line, help) VALUES ('CONFIG','',17,'-GBInterval <duration> - time between setting gline bursts (accepts friendly times)');
INSERT INTO help (command, subcommand, line, help) VALUES ('CONFIG','',18,'-SGline <Yes|No> - Save glines flag');